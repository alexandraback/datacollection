#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <algorithm>

int64_t k, c, s;
std::vector<int64_t> ans;

int64_t get_position(int64_t cur) {
    int64_t pos = 0;
    for (size_t i = 0; i < c; ++i) {
        pos = pos * k + cur;

        cur = std::max(cur - 1, static_cast<int64_t>(0));
    }
    return pos;
}

void solve() {
    if (k > c * s) {
        return;
    }

    auto cur = std::min(k - 1, c - 1);
    while (true) {
        ans.push_back(get_position(cur));
        if (cur == k - 1) {
            break;
        }
        cur = std::min(cur + c, k - 1);
    }
}


void read(std::istream &input) {
    input >> k >> c >> s;
    ans.clear();
}


void print(std::ostream &output) {
    if (ans.size() == 0) {
        output << "IMPOSSIBLE" << std::endl;
    } else {
        for (auto pos : ans) {
            output << pos + 1 << ' ';
        }
        output << std::endl;
    }
}


int main() {
#ifdef DEBUG
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    size_t t;
    std::cin >> t;
    for (size_t i = 1; i <= t; ++i) {
        read(std::cin);
        solve();
        std::cout << "Case #" << i << ": ";
        print(std::cout);
    }
    return 0;
}