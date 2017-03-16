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

#define DEBUG

using namespace std;

int solve() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    if (n > m) {
        int t = n;
        n = m;
        m = t;
    }
    if (n == 1 || n == 2) return k;
    int ans = k;
    FOR(i, n-2) FOR(j, m-2) {
        int t = i * j + 2 * i + 2 * j;
        int o, cnt;
        o = 0, cnt = j-2;
        int ti;
        for (ti=i+1; ti<=n-2; ti++) {
            t += cnt;
            if (++o > 1) o = 0, cnt -= 2;
            if (cnt <= 0) break;
        }
        int m1 = 0;
        if (cnt == 0 && ti <= n-2) m1 = 1;
        o = 0, cnt = i-2;
        for (ti=j+1; ti<=m-2; ti++) {
            t += cnt;
            if (++o > 1) o = 0, cnt -= 2;
            if (cnt <= 0) break;
        }
        int m2 = 0;
        if (cnt == 0 && ti <= m-2) m2 = 1;
        if (t >= k) ans = min(ans, i*2 + j*2);
        else {
            ans = min(ans, k - t + i*2 + j*2);
            if (m1 || m2) t += 2;
            if (t >= k) ans = min(ans, i*2 + j*2 + 1);
        }
    }
    return ans;
}

typedef long long LL;
int main()
{
#ifdef DEBUG
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
    int T;
    scanf("%d", &T);
    FOR(i, T) {
        printf("Case #%d: %d\n", i, solve());
    }
	return 0;
}
