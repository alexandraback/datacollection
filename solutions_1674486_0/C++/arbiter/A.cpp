#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
vector<int> v[1100];
int map[1100],n,m[1100],ok;
bool used[1100];
void dfs(int now)
{
	int i;
	if(ok)return;
	used[now]=1;
	for(i=0;i<m[now];i++)
	{
		if(used[v[now][i]]==1)
			ok=1;
		dfs(v[now][i]);
	}
}

main()
{
	freopen("A-small-attempt1.in","r",stdin);
	freopen("A-small-attempt1.out","w",stdout);
	int abc,T,i,j;
	scanf("%d",&T);
	for(abc=1;abc<=T;abc++)
	{
		ok=0;
		memset(v,0,sizeof(v));
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m[i]);
			for(j=0;j<m[i];j++)
			{
				int tmp;
				scanf("%d",&tmp);
				v[i].push_back(tmp);
			}
		}
		for(i=1;i<=n;i++)
		{
			memset(used,0,sizeof(used));
			dfs(i);
		}
		printf("Case #%d: ",abc);
		if(ok==1)printf("Yes\n");
		else printf("No\n");
	}
}	
