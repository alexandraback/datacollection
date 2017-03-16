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

typedef long long LL;
int main()
{
#ifdef DEBUG
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int T;
    scanf("%d", &T);
    LL a, b;
    FOR(i, T) {
        scanf("%lld/%lld", &a, &b);
        printf("Case #%d: ", i);
        int ans = -2;
        int t = sqrt(a);
        for(int j=2; j<t+1; j++) {
            while (a % j == 0 && b % j ==0) a/=j, b/=j;
        }
        if (b % a == 0) b /= a, a = 1;
        REP(j, 60) {
            if (b == (1 << j)) ans = -1;
        }
        if (ans != -2)
        REP(j, 60) {
            if (b % (1 << j) != 0) break;
            LL tmp = b / (1 << j);
            if (a >= tmp) {ans = j;break;}
        }
        if (ans != -1 && ans != -2) {
            printf("%d\n", ans);
        } else {
            printf("impossible\n");
        }
    }
	return 0;
}
