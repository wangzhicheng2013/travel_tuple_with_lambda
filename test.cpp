#include <iostream>
#include <tuple>
#include <algorithm>

template <typename Tuple, typename Func, size_t ...N>
void apply_func_to_tuple(const Tuple &t, Func &&func, std::index_sequence<N...>) {
    static_cast<void>(std::initializer_list<int>{(func(std::get<N>(t)), 0)...});
}
template <typename...Args, typename Func>
void travel_tuple(const std::tuple<Args...>&t, Func &&func) {
    apply_func_to_tuple(t, std::forward<Func>(func), std::make_index_sequence<sizeof...(Args)>{});
}
int main() {
    auto t = std::make_tuple(1, 10, "hello world.");
    travel_tuple(t, [] (auto &&item) { std::cout << item << std::endl; });

    return 0;
}