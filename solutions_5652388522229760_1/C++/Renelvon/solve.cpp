#include <bitset>
#include <iostream>
#include <string>

std::string solve(const unsigned int N) {
    if (N == 0) {
        return "INSOMNIA";
    }

    std::bitset<10> seen;
    auto cur_num = N;
    std::string cur_num_s;
    do {
        cur_num_s = std::to_string(cur_num);
        for(const auto c: cur_num_s) {
            seen.set('9' - c);
        }
        cur_num += N;
    } while (seen.count() < 10);

    return cur_num_s;
}

int main() {
    unsigned int T;
    std::cin >> T;

    for (auto i = 1u; i <= T; ++i) {
        unsigned int N;
        std::cin >> N;
        std::cout << "Case #" << i << ": " << solve(N) << std::endl;
    }
}
