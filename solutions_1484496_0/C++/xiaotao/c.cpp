#include <cstdio>
int n,a[30],b[30],c[30];
bool ok;

void dfs(int p,int p1,int s1,int p2,int s2)
{
	if (ok) return;
	if (s1 && s1==s2)
	{
		int i;
		for (i=0; i+1<p1; ++i) printf("%d ",b[i]);
		printf("%d\n",b[p1-1]);
		for (i=0; i+1<p2; ++i) printf("%d ",c[i]);
		printf("%d\n",c[p2-1]);
		ok=true;
		return;
	}
	if (p==n) return;
	dfs(p+1,p1,s1,p2,s2);
	b[p1]=a[p];
	dfs(p+1,p1+1,s1+a[p],p2,s2);
	if (!s1) return;
	c[p2]=a[p];
	dfs(p+1,p1,s1,p2+1,s2+a[p]);
}

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int T,t,i;
	scanf("%d",&T);
	for (t=1; t<=T; ++t)
	{
		scanf("%d",&n);
		for (i=0; i<n; ++i) scanf("%d",a+i);
		ok=false;
		printf("Case #%d:\n",t);
		dfs(0,0,0,0,0);
		if (!ok) puts("Impossible");
	}
	return 0;
}
