#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define SZ(v) ((int)(v).size())
#define FOR(i, a, b) for (typeof(a) i = (a); i < (b); ++i)
#define FORD(i, a, b) for(typeof(a) i = (a);i >= (b); --i)
#define FOREACH(iter, v) for (typeof((v).begin()) iter = (v).begin(); iter != (v).end(); ++iter)
#define REP(i, n) FOR(i, 0, n)

using namespace std;

#define SMALL 1

int main()
{
#if SMALL
    freopen("A-small.in", "r", stdin);
    freopen("A-small.out", "w", stdout);
#else
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
#endif

    int T, n, a[222];
    double ans[222];

    scanf("%d", &T);
    for (int tc = 1; tc <= T; ++tc) {
        scanf("%d", &n);
        int sum = 0;
        REP(i,n) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        REP(i,n) ans[i] = max(0.0, 2.0/n - (double)a[i] / sum);

        printf("Case #%d: ", tc);
        REP(i,n-1) printf("%.8lf ", ans[i] * 100);
        printf("%.8lf\n", ans[n-1] * 100);
/*
        double mi = 1000000;
        REP(i,n) {
            double cur = a[i]+sum*ans[i];
            mi = min(mi, cur);
            printf("#%d = %.6lf ", i, cur);
        }
        puts("");
        int c = 0;
        printf("min = %.6lf\n", mi);
        double sum2 = 0;
        REP(i,n) {
            if (mi + 1e-8 < a[i]+sum*ans[i]) ++c;
            sum2 += a[i]+sum*ans[i];
        }
        printf("num of min = %d, sum = %d, sum2 = %.6lf\n", n - c, sum, sum2);
        assert(n - c > 1);
*/
    }
    return 0;
}
