#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main() {
    unsigned int T;
    std::cin >> T;

    for (auto i = 1u; i <= T; ++i) {
        unsigned int K, C, S;
        std::cin >> K >> C >> S;

        std::vector<unsigned int> v(S, 0);
        std::iota(v.begin(), v.end(), 1);

        std::cout << "Case #" << i << ": ";
        std::copy(
            v.cbegin(), v.cend(),
            std::ostream_iterator<unsigned int>(std::cout, " ")
        );
        std::cout << std::endl;
    }
}
