//shjj-c
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=1003;
int go[N],t[N],last[N],en;
int f[N],Dep[N],n,sum,ans;
bool vis[N];

void add(int u,int v)
{
	go[++en]=v;t[en]=last[u];last[u]=en;
}

void dfs(int w,int dep)
{
	if (Dep[w])
	{
		ans=max(ans,dep-Dep[w]);
		return;
	}
	Dep[w]=dep;
	dfs(f[w],dep+1);
}

int Get(int w)
{
	if (vis[w]) return 0;
	int x=0;
	for (int i=last[w];i;i=t[i])
	{
		x=max(x,Get(go[i]));
	}
	return x+1;
}

int main()
{
	freopen("C1.in","r",stdin);
	freopen("C1.out","w",stdout);
	int T,Tt=0;scanf("%d",&T);
	for (;T--;)
	{
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&f[i]);
		ans=0;
		for (int i=1;i<=n;i++)
		{
			memset(Dep,0,sizeof(Dep));
			dfs(i,1);
		}
		sum=0;
		for (int i=1;i<=n;i++)
			if (f[f[i]]==i)
			{
				memset(last,0,sizeof(last));
				en=0;
				for (int j=1;j<=n;j++)
					if (i!=j&&f[i]!=j)
					{
						add(f[j],j);
					}
				memset(vis,0,sizeof(vis));
				sum+=Get(i)+Get(f[i]);
			}
		ans=max(ans,sum/2);
		printf("Case #%d: %d\n",++Tt,ans);
	}
}