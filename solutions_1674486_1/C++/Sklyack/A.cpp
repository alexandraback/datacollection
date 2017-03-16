#include <cstdio>
#include <cstring>

const int MAXN=1000, MAXM=10000;
int hd[MAXN], to[2*MAXM], nx[2*MAXM], ec;
bool was[MAXN];
bool ans;
void adde(int u, int v)
{
	to[ec]=v;
	nx[ec]=hd[u];
	hd[u]=ec++;
}

void dfs(int u)
{
	int i, v;
	was[u]=true;
	for(i=hd[u]; i>=0; i=nx[i])
	{
		v=to[i];
		if(!was[v])
			dfs(v);
		else
			ans=true;
	}
}
int main()
{
	int T, t, n, m, i, u, v;
	freopen("A-large.in", "r", stdin);
	//freopen("input.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for(t=1; t<=T; ++t)
	{
		scanf("%d", &n);
		ec=0;
		for(u=0; u<n; ++u)
		{
			scanf("%d", &m);
			hd[u]=-1;
			for(i=0; i<m; ++i)
			{
				scanf("%d", &v);
				adde(u, v-1);
			}
		}
		ans=false;
		for(u=0; u<n; ++u)
		{
			memset(was, 0, sizeof(was));
			dfs(u);
		}
		printf("Case #%d: %s\n", t, ans ? "Yes" : "No");
	}
	return 0;
}
