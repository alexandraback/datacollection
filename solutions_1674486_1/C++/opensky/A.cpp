#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,times,all[2000],way[2000][100],use[2000];
bool have(int x)
{
	use[x]=1;
	for (int a=1;a<=all[x];++a)
	{
		if (use[way[x][a]])
		{
			return true;
		}else use[way[x][a]]=1;
		if (have(way[x][a])) return true;
	}
	return false;
}
bool ok()
{
	for (int a=1;a<=n;++a)
	{
		memset(use,0,sizeof(use));
		if (have(a)) return true;
	}
	return false;
}
int main()
{
	freopen("a1.in","r",stdin);
	freopen("a1.out","w",stdout);
	scanf("%d",&times);
	for (int z=1;z<=times;++z)
	{
		scanf("%d",&n);
		for (int a=1;a<=n;++a)
		{
			scanf("%d",&all[a]);
			for (int b=1;b<=all[a];++b)
			{
				scanf("%d",&way[a][b]);
			}
		}
		printf("Case #%d: ",z);
		if (ok()) printf("Yes\n");else printf("No\n");
	}
}
