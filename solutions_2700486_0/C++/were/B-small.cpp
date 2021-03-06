#include <cstdio>
#include <algorithm>
#define LD long double
#define DO double
#define REP(i,n) for (int i=1;i<=n;++i)
using namespace std;

LD now,ans;
int T,n,m,x,y;

int main() {
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	scanf("%d",&T);
	REP(T_T,T) {
		scanf("%d%d%d",&n,&x,&y);
		if (x<0) x=-x;
		for (int i=0;i<x+y;i+=2) n-=i+i+1;
		m=x+y+x+y+1;
		if (n<0) printf("Case #%d: 0.0\n",T_T); else
		if (n>m) printf("Case #%d: 1.0\n",T_T); else
		if (x==0) {
			if (n==m) printf("Case #%d: 1.0\n",T_T);
			else printf("Case #%d: 0.0\n",T_T);
		} else {
			now=1;
			for (int i=1;i<=n;++i) now*=0.5;
			ans=0;
			for (int i=0;i<=n;++i) {
				if (i) now*=(LD)(n-i+1)/(LD)i;
				if (max(n-x-y,i)>y) ans+=now;
			}
			printf("Case #%d: %.20lf\n",T_T,(DO)ans);
		}
	}
	return 0;
}

