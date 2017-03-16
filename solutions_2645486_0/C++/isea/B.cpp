// New Ryan
// Create @ 10:02 04-27 2013
// Comment - 

#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <map>
#include <set>

using namespace std;

// Self Template Code BGEIN

#define sz(x) ((int)((x).size()))
#define out(x) printf(#x" %d\n", x)
#define all(x) (x).begin(), (x).end()
#define clz(x) memset (x, 0, sizeof(x))
#define read(x) freopen (x, "r", stdin)
#define wrte(x) freopen (x, "w", stdout)
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t, Case = 1; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

typedef long long int64;
typedef pair<int, int> pii;
typedef pair<int64, int64> pll;
typedef pair<double, double> pdd;

int sgn(double x) { return (x > 1e-8) - (x < -1e-8); }
int count_bit(int x) { return x == 0? 0 : count_bit(x >> 1) + (x & 1); }

template<class T> inline void ckmin(T &a, const T b) { if (b < a) a = b; }
template<class T> inline void ckmax(T &a, const T b) { if (b > a) a = b; }

// Self Template Code END

int dp[12][12], a[12], e, r, n;

int main() {
    wrte ("B.out");
    
    repcase {
        scanf ("%d%d%d", &e, &r, &n);
        rep (i, n) {
            scanf ("%d", &a[i]);
        }
        memset (dp, -1, sizeof(dp));
        dp[0][e] = 0;
        rep (i, n) {
            repf (j, 0, e) {
                if (dp[i][j] == -1) continue;
                repf (k, 0, j) {
                    ckmax (dp[i + 1][min(e, j - k + r)], dp[i][j] + k * a[i]);
                }
            }
        }
        int ans = 0;
        repf (j, 0, e) {
            ckmax (ans, dp[n][j]);
        }
        printf ("Case #%d: %d\n", Case++, ans);
    }
    return 0;
}

