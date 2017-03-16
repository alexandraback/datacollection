#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

signed main() {
    std::freopen("in", "r", stdin);
    std::freopen("out", "w", stdout);
    int tn;
    std::cin >> tn;
    for (int ti = 1; ti <= tn; ++ti) {
        std::string s;
        std::cin >> s;
        std::string answer;
        for (char c : s) {
            if (answer.empty()) {
                answer.push_back(c);
            } else {
                char v = answer.front();
                if (v <= c) {
                    answer = c + answer;
                } else {
                    answer.push_back(c);
                }
            }
        }
        std::cout << "Case #" << ti << ": " << answer << std::endl;
    }
}
