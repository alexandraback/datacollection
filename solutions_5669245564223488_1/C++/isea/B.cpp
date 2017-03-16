// Rain Dreamer MODEL
// Create @ 17:25 05-11 2014
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

const int maxn = 100 + 5;
const int mod = 1000000007;

int64 M(int64 x, int64 y) { return (x * y % mod); }

char s[maxn][maxn];
int n, fac[maxn];

int cnt[26][4];

// 0 - all
// 1 - mid
// 2 - head
// 3 - tail

bool valid() {
    clz (cnt);
    rep (i, n) {
        bool all_same = true;
        int len = strlen(s[i]);
        rep (id, len) {
            if (id && s[i][id] != s[i][id - 1]) all_same = false;
            if (id == 0) cnt[s[i][id] - 'a'][2] += 1;
            else if (id == len - 1) cnt[s[i][id] - 'a'][3] += 1;
            else {
                if (s[i][id] != s[i][id - 1]) {
                    cnt[s[i][id] - 'a'][1] += 1;
                }
            }
        }
        if (all_same) {
            cnt[s[i][0] - 'a'][0] += 1;
            cnt[s[i][0] - 'a'][2] -= 1;
            if (len != 1) {
                cnt[s[i][0] - 'a'][3] -= 1;
            }
        }
        else if (len > 2) {
            if (s[i][len - 1] == s[i][len - 2]) {
                cnt[s[i][len - 1] - 'a'][1] -= 1;
            }
        }
    }
    //rep (i, 26) if (cnt[i][0] || cnt[i][1] || cnt[i][2] || cnt[i][3]) {
        //printf ("%d %d %d %d\n", cnt[i][0], cnt[i][1], cnt[i][2], cnt[i][3]);
    //}
    rep (i, 26) if (cnt[i][1]) {
        if (cnt[i][1] > 1) return false;
        if (cnt[i][0] || cnt[i][2] || cnt[i][3]) return false;
    }
    rep (i, 26) if (cnt[i][2] > 1 || cnt[i][3] > 1) {
        return false;
    }
    return true;
}

bool g[maxn][maxn];

bool conflict() {
    clz (g);
    rep (i, n) {
        int len = strlen(s[i]);
        rep (id, len - 1) {
            g[s[i][id] - 'a'][s[i][id + 1] - 'a'] = true;
        }
    }
    rep (k, 26) rep (i, 26) rep (j, 26) if (g[i][k] && g[k][j]) g[i][j] = true;
    rep (i, 26) rep (j, i) if (g[i][j] && g[j][i]) return false;
    return true; 
}

int solve() {
    if (!conflict()) {
        return 0;
    }
    if (!valid()) {
        return 0;
    }
    int no_tail_tile = 0;
    rep (i, 26) {
        if (cnt[i][0] || cnt[i][2]) {
            no_tail_tile += (cnt[i][3] == 0);
        }
    }
    int ans = fac[no_tail_tile];
    rep (i, 26) {
        ans = M(fac[cnt[i][0]], ans);
    }
    return ans;
}

void gen() {
    fac[0] = 1;
    repf (i, 1, 100) fac[i] = M(fac[i - 1], i);
}

int main() {
    WT ("B.out");
    gen();
    repcase {
        scanf ("%d", &n);
        rep (i, n) scanf ("%s", s[i]);
        printf ("Case #%d: %d\n", Case ++, solve());
    }
    return 0;
}

