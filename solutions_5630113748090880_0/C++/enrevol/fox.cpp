#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

signed main() {
    std::freopen("in", "r", stdin);
    std::freopen("out", "w", stdout);
    int tn;
    std::cin >> tn;
    for (int ti = 1; ti <= tn; ++ti) {
        int n;
        std::cin >> n;
        std::map<int, int> counter;
        for (int i = 0; i < 2 * n - 1; ++i) {
            for (int j = 0; j < n; ++j) {
                int a;
                std::cin >> a;
                ++counter[a];
            }
        }
        std::vector<int> answer;
        answer.reserve(n);
        for (auto&& e : counter) {
            if (e.second % 2) {
                answer.push_back(e.first);
            }
        }
        std::cout << "Case #" << ti << ":";
        for (auto&& e : answer) {
            std::cout << " " << e;
        }
        std::cout << std::endl;
    }
}
