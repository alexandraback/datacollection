#include<stdio.h>
#include<string.h>
#define M 1000

int visit[M+10];
int child_num[M+10];
int map[M+10][M+10];

int dfs(int u)
{
	if(visit[u]) return 1;
	else
	{
		visit[u]=1;
		int res=0;
		for(int i=1;i<=child_num[u];i++)
			res|=dfs(map[u][i]);
		return res;
	}
}

int main()
{
	freopen("E:\\A-large.in","r",stdin);
	freopen("E:\\A-large.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	for(int cse=1;cse<=T;cse++)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&child_num[i]);
			for(int j=1;j<=child_num[i];j++) scanf("%d",&map[i][j]);
		}
		
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			memset(visit,0,sizeof(visit));
			ans|=dfs(i);
		}
		
		printf("Case #%d: ",cse);
		if(ans) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
