#include <iostream>
#include <iterator>
#include <string>

int solve(const std::string& s) {
    auto count = 0;
    auto current = '+';
    for (auto it = std::rbegin(s); it != std::rend(s); ++it) {
        auto c = *it;
        if (c != current) {
            count++;
            current = c;
        }
    }
    return count;
}

int main() {
    auto line = std::string{};
    std::getline(std::cin, line);
    auto T = std::stoi(line);
    for (int i=1; i<=T; i++) {
        std::getline(std::cin, line);
        auto retval = solve(line);
        std::cout << "Case #" << i << ": " << retval << std::endl;
    }
    return 0;
}
