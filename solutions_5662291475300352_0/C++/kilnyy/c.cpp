#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>

#define REP(i,n) for(int i=0;i<(n);i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,n) for(int i=1;i<=(n);i++)
#define FORD(i,n) for(int i=(n);i>=1;i--)

#define SZ(x) ((int)x.size())
#define CC(a,x) memset(a,x,sizeof(a))
#define TWO(x) ((LL)1<<(x))

using namespace std;

int T, n;
int d[11], h[11];

int solve() {
    int a, b, c, o;
    n = 0;
    scanf("%d", &o);
    REP(t, o) {
        scanf("%d%d%d", &a, &b, &c);
        for (int i=1; i<=b; i++) {
            d[n] = a;
            h[n] = c + i;
            n++;
        }
    }

    int ans = n - 1;
    if (n <= 1) return 0;
    REP(i, n) {
        int cur = 0;
        REP(j, n) {
            int t = (360 - d[i]) * h[i];
            if (d[j] * h[j] + t < 360 * h[j] || t > 360 * h[j] + d[j] * h[j]) {
                cur++;
            }
        }
        ans = min(ans, cur);
    }
    return ans;
}

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &T);
    for (int i=1; i<=T; i++) {
        printf("Case #%d: %d\n", i, solve());
    }
    return 0;
}
