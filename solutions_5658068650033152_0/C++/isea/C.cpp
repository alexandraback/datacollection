// Rain Dreamer MODEL
// Create @ 18:27 05-11 2014
// Comment - 

#include <cmath>
#include <ctime>
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
#define RD(x) freopen (x, "r", stdin)
#define WT(x) freopen (x, "w", stdout)
#define clz(x) memset (x, 0, sizeof(x))
#define cln(x) memset (x, -1, sizeof(x))
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repf(i,a,b) for (int i = (a); i <= (b); ++i)
#define repd(i,a,b) for (int i = (a); i >= (b); --i)
#define repcase int t, Case = 1; for (scanf ("%d", &t); t; --t)
#define repeach(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)

typedef long long int64;
typedef pair<int, int> pii;

int sgn(double x) { return (x > 1e-8) - (x < -1e-8); }
int count_bit(int x) { return x == 0? 0 : count_bit(x >> 1) + (x & 1); }

template<class T> inline void ckmin(T &a, const T b) { if (b < a) a = b; }
template<class T> inline void ckmax(T &a, const T b) { if (b > a) a = b; }

// Self Template Code END

int w, h, x;

int dp[22][22][444];
int minc[444];

void update(int& x, int y) {
    if (x == -1 || x > y) x = y;
}

void do_dp() {
    cln (dp);
    repf (i, 1, w * h) minc[i] = i;
    repf (i, 1, w) dp[0][i][i] = i;
    rep (j, h) {
        repf (num, 1, (j + 1) * w) repf (i, 1, w) {
            if (dp[j][num][i] != -1) {
                //printf ("dp[%d][%d][%d] = %d\n", j, num, i, dp[j][num][i]);
                if (j == h - 1) continue;
                repf (dif, -2, 2) {
                    if (i + dif <= w && i + dif > 0) {
                        update (dp[j + 1][num + i + dif][i + dif], dp[j][num][i] + 2);
                    }
                }
                int next = max(1, i - 2);
                update (minc[num + next], dp[j][num][i] + next);
            }
        }
    }
}

int main() {
    WT ("C3.out");
    repcase {
        scanf ("%d%d%d", &w, &h, &x);
        do_dp();
        
        int maxdif = 0;
        repf (i, 1, x) {
            //printf ("%d %d\n", minc[i], i);
            ckmax (maxdif, i - minc[i]);
        }
        printf ("Case #%d: %d\n", Case++, x - maxdif);
    }
    return 0;
}

