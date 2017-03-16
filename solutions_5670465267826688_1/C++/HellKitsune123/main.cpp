#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

const int mu[5][5] = {{0, 0, 0, 0, 0},
                      {0, 1, 2, 3, 4},
                      {0, 2,-1, 4,-3},
                      {0, 3,-4,-1, 2},
                      {0, 4, 3,-2,-1}};

int a[300000];
char s[10005];
int len, tt, n;
LL x, xx;

inline int mul(int a, int b) {
    int tmp = 1;
    if (a < 0) a = -a, tmp = -tmp;
    if (b < 0) b = -b, tmp = -tmp;
    int ret = mu[a][b];
    return ret * tmp;
}

int binPow(int x, LL p) {
    int ret = 1;
    while (p) {
        if (p & 1ll) ret = mul(ret, x);
        p >>= 1;
        x = mul(x, x);
    }
    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &tt);
    for (int test = 1; test <= tt; ++test) {
        scanf("%d%I64d%s", &len, &x, s), xx = x;
        if (x > 30) x = 30;
        REP(i, len) if (s[i] == 'i') a[i] = 2;
        else if (s[i] == 'j') a[i] = 3;
        else a[i] = 4;
        n = len * x;
        for (int i = len; i < n; ++i)
            a[i] = a[i - len];
        int cur = 1;
        int nx = 2;
        REP(i, n) {
            cur = mul(cur, a[i]);
            if (cur == nx) {
                ++nx;
                cur = 1;
            }
        }
        int cyc = 1;
        REP(i, len) {
            cyc = mul(cyc, a[i]);
        }
        cur = mul(cur, binPow(cyc, xx - x));
        if (nx == 5 && cur == 1) printf("Case #%d: YES\n", test);
        else printf("Case #%d: NO\n", test);
    }
	return 0;
}
