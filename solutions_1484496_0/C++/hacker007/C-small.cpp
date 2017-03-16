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
    freopen("C-small.in", "r", stdin);
    freopen("C-small.out", "w", stdout);
#else
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
#endif

    int T, n, sum, a[30];

    scanf("%d", &T);
    for (int tc = 1; tc <= T; ++tc) {
        scanf("%d", &n);
        REP(i,n) scanf("%d", &a[i]);
        sort(a, a+n);
        bool found = false;
        map<int, int> subset;
        REP(mask, 1<<n) {
            sum = 0;
            REP(i,n) {
                if (mask & 1<<i) sum += a[i];
            }
            if (subset.count(sum) == 0) subset[sum] = mask;
            else {
                printf("Case #%d:\n", tc);
                REP(i,n) if (subset[sum] & 1<<i) printf("%d ", a[i]);
                printf("\n");
                REP(i,n) if (mask & 1<<i) printf("%d ", a[i]);
                printf("\n");
                found = true;
                break;
            }
        }
        if (!found) printf("Impossible\n");
    }
    return 0;
}
