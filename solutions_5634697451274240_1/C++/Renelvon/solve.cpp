#include <iostream>
#include <string>

unsigned int solve(const std::string s) {
    auto last_char = '+';
    auto inversions = 0u;
    for (auto c = s.crbegin(); c != s.crend(); ++c) {
        if (*c != last_char) {
            ++inversions;
            last_char = *c;
        }
    }
    return inversions;
}

int main() {
    unsigned int T;
    std::cin >> T;

    for (auto i = 1u; i <= T; ++i) {
        std::string s;
        std::cin >> s;
        std::cout << "Case #" << i << ": " << solve(s) << std::endl;
    }
}
