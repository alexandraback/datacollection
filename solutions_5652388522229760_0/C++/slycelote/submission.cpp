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
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// Powered by caide (code generator, tester, and library code inliner)
class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
        int T; in >> T;
        for (int test = 1; test <= T; ++test) {
            out << "Case #" << test << ": ";
            int N; in >> N;
            int res = solve(N);
            if (res < 0)
                out << "INSOMNIA\n";
            else
                out << res << "\n";
        }
    }
    int solve(int N) {
        if (N == 0)
            return -1;
        vector<bool> seen(10, false);
        int nSeen = 0, res = -1;
        for (int i = 1; res < 0 && i <= 72; ++i) {
            int cur = i * N;
            while (cur) {
                int d = cur % 10;
                if (!seen[d]) {
                    seen[d] = true;
                    if (++nSeen == 10)
                        return i*N;
                }
                cur /= 10;
            }
        }
        return -1;
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

