/*
 * Sat Apr 14 08:07:10 CST 2012
 */
#define see(n) cerr << #n << " = " << n << endl
#define seeArray(n, a) cerr << #a << " = ";\
    for (int __i__ = 0; __i__ < (int) n; ++__i__)\
        cerr << a[__i__] << " ";\
    cerr << endl;
#define seeArray2(n, m, a) cerr << #a << " = " << endl;\
    for (int __i__ = 0; __i__ < (int) n; ++__i__) {\
        for (int __j__ = 0; __j__ < (int) m; ++__j__)\
            cerr << a[__i__][__j__] << " ";\
        cerr << endl;\
    }
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <list>
#include <sstream>
#include <cctype>
#include <ctime>
#include <numeric>
using namespace std;
const int dir[8][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }, { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } };
const int inf = 1000000000;
const long long infll = 1000000000000000000LL;
const double eps = 1e-10;
const double pi = acos(-1.0);

const int maxn = 128;
int cases, cas = 1;
int n, surprising, lim;
int scores[maxn];

int main() {
    for (scanf("%d", &cases); cases--; ++cas) {
        scanf("%d%d%d", &n, &surprising, &lim);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &scores[i]);
        }
        int ans = 0; for (int i = 0; i < n; ++i) {
            int three = scores[i] / 3;
            if (scores[i] % 3 != 0) {
                three++;
            }
            if (three >= lim) {
                ans++; continue;
            }
            int left = scores[i] - lim;
            if (left < 0) {
                continue;
            }
            int half = left / 2;
            if (lim < half) {
                continue;
            }
            if (lim - half > 2) {
                continue;
            }
            if (lim - half == 2 && surprising > 0) {
                surprising--; ans++; continue;
            }
            if (lim - half <= 1) {
                ans++; continue;
            }
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
