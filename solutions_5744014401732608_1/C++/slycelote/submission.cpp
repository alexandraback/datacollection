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

namespace caide {

typedef unsigned long long ull;

template<typename T>
vector<vector<T>> makeVector(int n, int m) {
    return vector<vector<T>>(n, vector<T>(m));
}

}

using namespace caide;

// Powered by caide (code generator, tester, and library code inliner)
class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
        int T; in >> T;
        for (int test = 1; test <= T; ++test) {
            out << "Case #" << test << ": ";
            int B;
            ull M;
            in >> B >> M;
            if (M > (1ULL << (B-2))) {
                out << "IMPOSSIBLE\n";
                continue;
            }
            out << "POSSIBLE\n";
            auto v = makeVector<int>(B, B);
            for (int i = 0; i < B; ++i) for (int j = i+1; j < B-1; ++j)
                v[i][j] = 1;
            if (M == (1ULL << (B-2))) {
                for (int i = 0; i < B-1; ++i)
                    v[i][B-1] = 1;
            } else {
                for (int i = 1; i < B-1; ++i)
                    if (M & (1ULL << (i-1)))
                        v[i][B-1] = 1;
            }

            for (const auto& r : v) {
                for (int i : r)
                    out << i;
                out << "\n";
            }
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

