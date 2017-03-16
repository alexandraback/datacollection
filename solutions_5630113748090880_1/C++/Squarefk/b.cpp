#include <cstdio>
#include <list>
#include <cstring>
#define REP(i,n) for (int i=1;i<=n;++i)
#define FOR(i,n) for (__typeof(n.begin())i=n.begin();i!=n.end();++i)
using namespace std;

int T,n;
int sum[2525];

int main() {
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	REP(T_T,T) {
		printf("Case #%d:",T_T);
		scanf("%d",&n);
		memset(sum,0,sizeof(sum));
		REP(i,n+n-1) REP(j,n) {
			int x;
			scanf("%d",&x);
			++sum[x];
		}
		REP(i,2500)
			if (sum[i]&1) printf(" %d",i);
		puts("");
	}
	return 0;
}