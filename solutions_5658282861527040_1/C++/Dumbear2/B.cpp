/******************************************************************************\
*                         Author:  Dumbear                                     *
*                         Email:   dumbear[#at]163.com                         *
*                         Website: http://dumbear.com                          *
\******************************************************************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>

using namespace std;

#define output(x) cout << #x << ": " << (x) << endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<string> VS;

int t, A, B, X;
LL dp[32][8];

void solve() {
    scanf("%d%d%d", &A, &B, &X);
    memset(dp, 0, sizeof(dp));
    dp[31][0] = 1;
    for (int i = 31; i > 0; --i) {
        for (int f = 0; f < 8; ++f) {
            if (dp[i][f] == 0)
                continue;
            // output(dp[i][f]);
            for (int s = 0; s < 8; ++s) {
                int a = s & 1, b = (s >> 1) & 1, x = (s >> 2) & 1;
                if (x != (a & b))
                    continue;
                int fa = f & 1, fb = (f >> 1) & 1, fx = (f >> 2) & 1;
                if (!fa && a > ((A >> i - 1) & 1))
                    continue;
                if (!fb && b > ((B >> i - 1) & 1))
                    continue;
                if (!fx && ((a & b) > ((X >> i - 1) & 1)))
                    continue;
                int nfa = (fa ? 1 : (a < ((A >> i - 1) & 1)));
                int nfb = (fb ? 1 : (b < ((B >> i - 1) & 1)));
                int nfx = (fx ? 1 : ((a & b) < ((X >> i - 1) & 1)));
                // output(nfa + (nfb << 1) + (nfx << 2));
                dp[i - 1][nfa + (nfb << 1) + (nfx << 2)] += dp[i][f];
            }
        }
    }
    printf("Case #%d: ", ++t);
    cout << dp[0][7] << endl;
}

int main() {
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
        solve();
    return 0;
}
