#include <algorithm>
#include <complex>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <istream>
#include <limits>
#include <map>
#include <numeric>
#include <ostream>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

#define ALL(c) std::begin(c), std::end(c)

// Powered by caide (code generator, tester, and library code inliner)
class Solution {
public:
    vector<vector<int>> solve(int J, int P, int S, int K) {
        vector<vector<int>> res;

        if (S <= K) {
            for (int j = 1; j <= J; ++j) for (int p = 1; p <= P; ++p) for (int s = 1; s <= S; ++s) {
                res.push_back({j, p, s});
            }
            return res;
        }

        if (K == 1) {
            if (J == 1) {
                for (int i = 1; i <= P; ++i)
                    res.push_back({1, i, i});
                return res;
            } else if (J == 2) {
                if (P == 2) {
                    res = {{1,1,1}, {2,2,1}, {1,2,2}, {2,1,2}};
                    return res;
                } else {
                    res = {{1,1,1}, {1,2,2}, {1,3,3}, {2,1,3}, {2,2,1}, {2,3,2}};
                    return res;
                }
            } else {
                for (int j = 1; j <= J; ++j) for (int p = 1; p <= P; ++p) for (int s = 1; s <= S; ++s) {
                    if ((j + p + s) % 3 == 0)
                        res.push_back({j, p, s});
                }
                return res;
            }
        }

        // K == 2, S == 3

        if (J == 1) {
            if (P == 1) {
                for (int i = 1; i <= min(2, S); ++i) {
                    res.push_back({1,1,i});
                }
                return res;
            } else {
                for (int i = 1; i <= P; ++i) for (int j = 1; j <= S; ++j) if ((i+j)%3 != 0) {
                    res.push_back({1,i,j});
                }
                return res;
            }
        } else if (J == 2) {
            vector<vector<int>> r;
            if (P == 2) {
                r = {{1,1,1}, {2,2,1}, {1,2,2}, {2,1,2}};
            } else {
                r = {{1,1,1}, {1,2,2}, {1,3,3}, {2,1,3}, {2,2,1}, {2,3,2}};
            }
            for (int j = 1; j <= J; ++j) for (int p = 1; p <= P; ++p) for (int s = 1; s <= S; ++s) {
                vector<int> v{j,p,s};
                if (find(ALL(r), v) == r.end())
                    res.push_back(v);
            }
            return res;
        } else {
            for (int j = 1; j <= J; ++j) for (int p = 1; p <= P; ++p) for (int s = 1; s <= S; ++s) {
                if ((j + p + s) % 3 != 0)
                    res.push_back({j, p, s});
            }
            return res;
        }

        return res;
    }

    void solve(std::istream& in, std::ostream& out) {
        int T; in >> T;
        for (int test = 1; test <= T; ++test) {
            out << "Case #" << test << ": ";
            int J, P, S, K; in >> J >> P >> S >> K;
            auto res = solve(J, P, S, K);
            out << res.size() << "\n";
            for (const auto& v : res)
                out << v[0] << " " << v[1] << " " << v[2] << "\n";
        }
    }
};

void solve(std::istream& in, std::ostream& out)
{
    out << std::setprecision(12);
    Solution solution;

    solution.solve(in, out);

}

#include <fstream>
#include <iostream>

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    istream& in = cin;

    ostream& out = cout;

    solve(in, out);
    return 0;
}

