#include <cstdio>
#include <algorithm>
#define LL long long
using namespace std;

LL T,m,now,ans,r,n,v[10010];

int main() {
	freopen("B-large.in","r",stdin);
	freopen("1.txt","w",stdout);
	scanf("%d",&T);
	for (int T_T=1;T_T<=T;++T_T) {
		scanf("%I64d%I64d%I64d",&m,&r,&n);
		now=m;
		for (int i=1;i<=n;++i) scanf("%I64d",&v[i]);
		ans=0;
		for (int i=1;i<=n;++i,now=min(m,now+r)) {
			int pos=0;
			for (int j=i+1;j<=n;++j)
				if (v[j]>v[i]) {pos=j;break;}
			if (!pos) ans+=v[i]*now,now=0;
			else {
				if ((LL)(pos-i)*r+now<=m) continue;
				else {
					LL tmp=min(now,(LL)(pos-i)*r+now-m);
					ans+=v[i]*tmp;
					now-=tmp;
				}
			}
		}
		printf("Case #%d: %I64d\n",T_T,ans);
	}
	return 0;
}

