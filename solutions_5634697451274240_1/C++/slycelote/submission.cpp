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

namespace caide {

template<typename C>
int SZ(const C& c) { return (int)c.size(); }

}

using namespace caide;

// Powered by caide (code generator, tester, and library code inliner)
class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
        int T; in >> T;
        for (int test = 1; test <= T; ++test) {
            string s; in >> s;
            int res = 0;
            for (int i = 0; i < SZ(s) - 1; ++i)
                if (s[i] != s[i+1])
                    ++res;
            if (s.back() == '-')
                ++res;
            out << "Case #" << test << ": " << res << "\n";
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

