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
std::array<bool, N> mark;

std::vector<int> b[N];

//struct cmp {
//    bool operator()(int lhs, int rhs) const {
//        if (b[lhs].size() != b[rhs].size()) {
//            return b[lhs].size() < b[rhs].size();
//        }
//        return lhs < rhs;
//    }
//};

int dfs(int u, int p = 0) {
    int d = 1;
    for (int v : b[u]) {
        assert(f.at(v) == u);
        if (v != p) {
            d = std::max(d, dfs(v) + 1);
        }
    }
    return d;
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
            b[i].clear();
        }
//        std::fill(f.begin(), f.end(), 0);
        for (int i = 1; i <= n; ++i) {
            int k;
            std::cin >> k;
            f.at(i) = k;
            assert(k != i);
            assert(1 <= k && k <= n);
            b[k].push_back(i);
        }
        int answer = 0;
        std::fill(mark.begin(), mark.end(), false);
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (f.at(f.at(i)) == i && mark.at(f.at(i)) == false) {
                int size = dfs(i, f.at(i)) + dfs(f.at(i), i);
                sum += size;
                mark.at(i) = true;
            }
        }
        answer = sum;
//        std::set<int, cmp> s;
//        for (int i = 1; i <= n; ++i) {
//            s.insert(i);
//        }
        for (;;) {
            int i = 0;
            for (int j = 1; j <= n; ++j)
                if (b[j].empty() && mark.at(j) == false) {
                    i = j;
                    break;
                }
            if (i == 0) break;
            mark.at(i) = true;
//        while (s.empty() == false) {
//            int i = *s.begin();
//            if (b[i].empty() == false) {
//                break;
//            }
//            s.erase(i);
            int j = f.at(i);
            if (b[j].empty()) continue;
//            if (s.count(j)) {
//                s.erase(j);
                auto iter = std::find(b[j].cbegin(), b[j].cend(), i);
                b[j].erase(iter);
//                s.insert(j);
//            } else {
//                assert(b[j].empty());
//            }
        }
        std::fill(mark.begin(), mark.end(), false);
        for (int i = 1; i <= n; ++i) {
//        for (int i : s) {
//            assert(b[i].empty() == false);
            if (mark.at(i) == false && b[i].empty() == false) {
                int size = 0;
                int j = i;
                while (mark.at(j) == false) {
                    ++size;
                    mark.at(j) = true;
                    assert(b[f.at(j)].at(0) == j);
                    j = f.at(j);
                }
                assert(size > 1);
                answer = std::max(answer, size);
            }
        }
//        for (int i : s) {
//            assert(mark.at(i));
//        }
        assert(answer >= 2);
        std::cout << "Case #" << ti << ": " << answer << std::endl;
    }
}
