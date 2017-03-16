#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

constexpr int N = 1010;

std::array<int, N> f;

int h[N];
bool chosen[N];

bool solve(int iter, int size, int n) {
    if (iter > size) {
        bool ok = true;
        for (int i = 1; i <= size && ok; ++i) {
            int prev = (i - 1);
            if (prev < 1) prev = size;
            int next = (i + 1);
            if (next > size) next = 1;
            ok = ok && (f.at(h[i]) == h[next] || f.at(h[i]) == h[prev]);
        }
        return ok;
    }
    for (int i = 1; i <= n; ++i) {
        if (!chosen[i]) {
            chosen[i] = true;
            h[iter] = i;
            if (solve(iter + 1, size, n)) {
                return true;
            }
            chosen[i] = false;
        }
    }
    return false;
}

signed main() {
    std::freopen("in", "r", stdin);
    std::freopen("out", "w", stdout);
    int tn;
    std::cin >> tn;
    for (int ti = 1; ti <= tn; ++ti) {
        int n;
        std::cin >> n;
        for (int i = 1; i <= n; ++i) {
            int k;
            std::cin >> k;
            f.at(i) = k;
        }
        int answer = 0;
        for (int size = n; size >= 1; --size) {
            std::fill(chosen + 1, chosen + n + 1, false);
            if (solve(1, size, n)) {
                answer = size;
                break;
            }
        }
        std::cout << "Case #" << ti << ": " << answer << std::endl;
    }
}
