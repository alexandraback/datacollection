#include <cstdio>
#include <cstring>
const int Maxn=1001, Maxm=1000001;
bool ok,u[Maxn],uu[Maxn];
int x[Maxm],next[Maxm],g[Maxn];


void dfs(int v)
{
	if (ok) return;
	uu[v]=u[v]=true;
	for (int p=g[v]; p; p=next[p])
		if (u[x[p]]) ok=true; else dfs(x[p]);
}

int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int T,t,n,m,k,i,v;
	scanf("%d",&T);
	for (t=1; t<=T; ++t)
	{
		scanf("%d",&n);
		memset(g,0,sizeof g);
		m=0;
		for (i=1; i<=n; ++i)
		{
			scanf("%d",&k);
			while (k--)
			{
				scanf("%d",&v);
				x[++m]=v; next[m]=g[i]; g[i]=m;
			}
		}
		ok=false;
		memset(uu,0,sizeof uu);
		for (i=1; !ok && i<=n; ++i)
		{
			if (uu[i]) continue;
			memset(u,0,sizeof u);
			dfs(i);
		}
		printf("Case #%d: ",t);
		if (ok) puts("Yes"); else puts("No");
	}
	return 0;
}
