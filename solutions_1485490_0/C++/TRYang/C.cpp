#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 110

using namespace std;

typedef long long ll;

ll a[maxn];
int at[maxn];
ll b[maxn];
int bt[maxn];
ll g[maxn][maxn];
int n,m;
ll f(int x,int y){
	if (g[x][y]!=-1) return g[x][y];
	ll &gt=g[x][y];
	if (x==0 || y==0) return gt=0;
	gt=max(f(x-1,y),f(x,y-1));
	int p=x,q=y;
	ll dx=a[x],dy,c;
	ll tot=0;
	int flag=0;

	while (1){
		if (!flag){
			while (q && bt[q]!=at[p]) --q;
			if (q==0) break;
			dy=b[q];
			c=min(dx,dy);
			tot+=c;
			gt=max(gt,tot+f(p-1,q-1));
			if (dx==dy) break;
			dx-=c;
			dy-=c;
			if (dx==0){
				--p;
				flag=1;
			}else{
				--q;
			}
		}else{
			while (p && at[p]!=bt[q]) --p;
			if (p==0) break;
			dx=a[p];
			c=min(dx,dy);
			tot+=c;
			gt=max(gt,tot+f(p-1,q-1));
			if (dx==dy) break;
			dx-=c;
			dy-=c;
			if (dy==0){
				--q;
				flag=0;
			}else{
				--p;
			}
		}
	}

	p=x,q=y;
	dy=b[y];
	tot=0;
	flag=1;

	while (1){
		if (!flag){
			while (q && bt[q]!=at[p]) --q;
			if (q==0) break;
			dy=b[q];
			c=min(dx,dy);
			tot+=c;
			gt=max(gt,tot+f(p-1,q-1));
			if (dx==dy) break;
			dx-=c;
			dy-=c;
			if (dx==0){
				--p;
				flag=1;
			}else{
				--q;
			}
		}else{
			while (p && at[p]!=bt[q]) --p;
			if (p==0) break;
			dx=a[p];
			c=min(dx,dy);
			tot+=c;
			gt=max(gt,tot+f(p-1,q-1));
			if (dx==dy) break;
			dx-=c;
			dy-=c;
			if (dy==0){
				--q;
				flag=0;
			}else{
				--p;
			}
		}
	}
	return gt;
}
int main(){
	int tn,cp;
	for (scanf("%d",&tn),cp=1;cp<=tn;cp++){
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;i++) scanf("%lld%d",a+i,at+i);
		for (int i=1;i<=m;i++) scanf("%lld%d",b+i,bt+i);
		memset(g,-1,sizeof(g));
		printf("Case #%d: %lld\n",cp,f(n,m));
	}
	return 0;
}
