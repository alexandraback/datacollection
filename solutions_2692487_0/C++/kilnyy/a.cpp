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

int x[101];

typedef long long LL;
int main()
{
#ifdef DEBUG
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    int a,n;
    scanf("%d",&T);
    FOR(d,T) {
        scanf("%d%d",&a,&n);
        FOR(i,n) {
            scanf("%d",x+i);
        }
        sort(x+1, x+n+1);
        int ans = 1000000;
        int cur = 0;
        if (a == 1) {
            printf("Case #%d: %d\n", d, n);
            continue;
        }
        FOR(i,n) {
            if (a > x[i]) a+=x[i];
            else {
                ans = min(cur + n-i+1, ans);
                while (a <= x[i]) {
                    a += a-1;
                    cur++;
                }
                a+=x[i];
            }
        }
        ans = min(ans, cur);
        printf("Case #%d: %d\n", d, ans);
    }
#endif
	return 0;
}
