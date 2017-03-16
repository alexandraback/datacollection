#include <cstdio>
#include <algorithm>
#define LD long double
#define DO double
#define REP(i,n) for (int i=1;i<=n;++i)
using namespace std;

LD now,ans;
int T,n,m,x,y;

int main() {
	freopen("B-large.in","r",stdin);
	freopen("1.out","w",stdout);
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
			if (n-x-y>y) ans=1;
			else {
				now=1; ans=0;
				for (int i=1;i<=n;++i) now*=(LD)i*0.5;
				for (int i=1;i<=y;++i) now/=(LD)i;
				for (int i=1;i<=n-y;++i) now/=(LD)i;
				for (int i=y+1;i<=n;++i) {
					now*=(LD)(n-i+1)/(LD)i;
					ans+=now;
				}
			}
			printf("Case #%d: %.20lf\n",T_T,(DO)ans);
		}
	}
	return 0;
}

