#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cstdint>

#define ld long double
#define ll long long

int n;
int64_t m;
std::vector<std::vector<bool>> graph;
bool no_answer;

int64_t readInt64() {
    ll x;
    std::cin >> x;
    return x;
}

int readInt32() {
    int x;
    std::cin >> x;
    return x;
}

void read() {
    n = readInt32();
    m = readInt64();

    graph.assign(n, std::vector<bool>(n, false));

    no_answer = false;
}

void solve() {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            graph[i][j] = true;
        }
    }

    int64_t max_edges = static_cast<int64_t>(1) << n - 2;
    if (m > max_edges) {
        no_answer = true;
    } else {
        for (int j = n - 2; j >= 0; --j) {
            int64_t cur = static_cast<int64_t>(1) << std::max(0, j - 1);
            if (m >= cur) {
                m -= cur;
                graph[j][n - 1] = true;
            }
        }
    }
}

void print() {
    if (no_answer) {
        std::cout << "IMPOSSIBLE" << std::endl;
    } else {
        std::cout << "POSSIBLE" << std::endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                std::cout << (graph[i][j] ? '1' : '0');
            }
            std::cout << std::endl;
        }
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        read();
        solve();
        std::cout << "Case #" << i + 1 << ": ";
        print();
    }

    return 0;
}