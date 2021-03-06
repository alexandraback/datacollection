#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

#define mxn 200005
#define LL long long
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)

int p[1005];

int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);

    int t, cas = 0, n;

    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        REP(i, 1, n) scanf("%d", p + i);
        int ans = 1000;
        REP(k, 1, 1000) {
            int cost = k;
            REP(i, 1, n) cost += (p[i] - 1) / k;
            ans = min(ans, cost);
        }
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}