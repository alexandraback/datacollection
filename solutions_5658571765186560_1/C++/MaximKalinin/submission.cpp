#include <algorithm>
#include <iomanip>
#include <istream>
#include <map>
#include <ostream>
#include <set>
#include <sstream>
#include <utility>
#include <vector>
using namespace std;
// Solution template generated by caide


class Solution {
public:
    void solve(std::istream& in, std::ostream& out) {
        int T;
        in >> T;
        for (int test = 1; test <= T; ++test) {
            int X, R, C;
            in >> X >> R >> C;
            out << "Case #" << test << ": " << (solve(X, R, C) ? "RICHARD" : "GABRIEL") << endl;
        }
    }
    bool solve(int x, int m, int n) {
        if (m > n)
            swap(m, n);
        if (x >= 7)
            return true;
        if (m*n % x != 0)
            return true;
        if (n < x)
            return true;
        if (x <= 2)
            return false;
        if (x == 3)
            return m == 1;
        if (x == 4)
            return m <= 2;
        if (x == 5) {
            if (m <= 2)
                return true;
            if (m == 3)
                return n == 5;
            return false;
        }
        // x == 6
        return m <= 3;
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
