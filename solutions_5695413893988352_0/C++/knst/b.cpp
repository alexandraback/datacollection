/*****************************************************************************
 * codeforces:   knst
 * topcoder:     knstqq
 * projecteuler: knstqq
 * **************************************************************************/

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

namespace std {
    template <class T1, class T2>
    class hash<pair<T1, T2>> {
    public:
        size_t operator()(const pair<T1, T2>& p) const {
            return hash<T1>()(p.first) & hash<T2>()(p.second);
        }
    };
}

constexpr long double const_pi() { return std::atan(static_cast<long double>(1))*4; }

const int dx4[] = {-1, 0, 0, 1};
const int dy4[] = {0, -1, 1, 0};

const int dx8[] = {-1, -1, -1,  0,  0,  1,  1,  1};
const int dy8[] = {-1,  0,  1, -1,  1, -1,  0,  1};

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

bool valid(int i, string s) {
    if (s[2] != '?' && i % 10 != s[2] - '0')
        return false;
    if (s[1] != '?' && i / 10 % 10 != s[1] - '0')
        return false;
    if (s[0] != '?' && i / 100 % 10 != s[0] - '0')
        return false;
    return true;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    for (int T = 1; T <= t; ++T) {
        int minimal = numeric_limits<int>::max();
        int mX = 0;
        int mY = 0;
        string s1;
        string s2;
        cin >> s1 >> s2;

        size_t sLen = s1.size();

        while (s1.size() != 3)
            s1 = '0' + s1;
        while (s2.size() != 3)
            s2 = '0' + s2;
        for (int i = 0; i < 1000; ++i) {
            for (int j = 0; j < 1000; ++j) {
                if (!valid(i, s1))
                    continue;
                if (!valid(j, s2))
                    continue;
                int diff = i - j;
                if (diff < 0)
                    diff = -diff;
                if (diff < minimal) {
                    minimal = diff;
                    mX = i;
                    mY = j;
                }
            }
        }
        cout << "Case #" << T << ": " << setfill('0') << setw(sLen)<< mX << ' ' << setfill('0') << setw(sLen) << mY << endl;



    }
    return 0;
}
