#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1111;
int go[N],t[N],last[N],en;
int a[N],deep[N],n,sum,ans;
bool vis[N];

void add(int u,int v)
{
	go[++en]=v;t[en]=last[u];last[u]=en;
}

void dfs(int u,int dd)
{
	if (deep[u])
	{
		ans = max(ans,dd-deep[u]);
		return;
	}
	deep[u] = dd;
	dfs(a[u], dd+1);
}

int dfs_(int u)
{
	if (vis[u]) return 0;
	int x=0;
	for (int i=last[u];i;i=t[i])
	{
		x = max(x,dfs_(go[i]));
	}
	return x+1;
}

int main()
{
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	int T;
	int k = 0;
    scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		ans=0;
		for (int i=1;i<=n;i++)
		{
			memset(deep,0,sizeof(deep));
			dfs(i,1);
		}
		sum=0;
		for (int i=1;i<=n;i++)
			if (a[a[i]]==i)
			{
				memset(last,0,sizeof(last));
				en=0;
				for (int j=1;j<=n;j++)
					if (i != j && a[i]!=j)
					{
						add(a[j],j);
					}
				memset(vis,0,sizeof(vis));
				sum += dfs_(i) + dfs_(a[i]);
			}
		int tmp = sum / 2;
		ans = max(ans, tmp);
		printf("Case #%d: %d\n",++k,ans);
	}
}
