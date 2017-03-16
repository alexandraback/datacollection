#include <cstdio>
#include <algorithm>
#define LL long long
#define REP(i,n) for (int i=1;i<=n;++i)
using namespace std;

int T,k,c,s;
LL a[110];

int main() {
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	REP(T_T,T) {
		printf("Case #%d:", T_T);
		scanf("%d%d%d",&k,&c,&s);
		a[0]=0;
		for (int i=0;i<k;i+=c) {
			a[++a[0]]=0;
			for (int j=0;j<c;++j)
				a[a[0]]=a[a[0]]*k+min(i+j,k-1);
		}
		if (a[0]>s) puts(" IMPOSSIBLE");
		else {
			REP(i,a[0])
				printf(" %lld",a[i]+1);
			puts("");
		}
	}
	return 0;
}