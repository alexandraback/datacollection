#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int g[1111][1111],r[1111],n;
bool f[1111];
int T;

void init()
{
	memset(r,0,sizeof(r));
	memset(g,0,sizeof(g));
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&r[i]);
		for (int j=1;j<=r[i];j++)
		{
			int x;	scanf("%d",&x);
			g[x][++g[x][0]]=i;
		}
	}
}

bool dfs(int v)
{
	if (f[v]) return true;
	f[v]=true;
	for (int i=1;i<=g[v][0];i++)
		if (dfs(g[v][i])) return true;
	return false;
}

bool work()
{
	for (int i=1;i<=n;i++)
		if (r[i]==0)
		{
			memset(f,0,sizeof(f));
			if (dfs(i)) return true;
		}
	return false;
}

int main()
{
	scanf("%d",&T);
	for (int t=1;t<=T;t++)
	{
		init();
		printf("Case #%d: ",t);
		if (work()) printf("Yes\n");	else printf("No\n");
	}
	return 0;
}