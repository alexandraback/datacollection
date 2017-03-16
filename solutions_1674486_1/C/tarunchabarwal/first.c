#include<stdio.h>
#define N 1001
int path[N][N];
int queue[10000000];
int bfs(int start,int n)
{
	int i,j,k,ii;
	int visit[N];
	for(i=0;i<=n;i++)visit[i]=0;
	int f,r;
	f=-1;
	r=0;
	queue[++f]=start;
	while(r<=f)
	{
		j=queue[r++];
		if(visit[j]==1)return 1;
		for(i=1;i<=n;i++)
			if(path[j][i]==1)
			{
				queue[++f]=i;
			}
		visit[j]=1;
	}
	return 0;
}
int main()
{
	int t,n,i,j,k,tt;
	
	scanf("%d",&t);
	for(tt=1;tt<=t;tt++)
	{
		scanf("%d",&n);
		for(i=0;i<=n;i++)for(j=0;j<=n;j++)path[i][j]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&k);
			while(k--)
			{
				scanf("%d",&j);
				path[i][j]=1;
			}
		}
		printf("Case #%d: ",tt);
		for(i=1;i<=n;i++)
		{
			k=bfs(i,n);
			if(k==1){puts("Yes");break;}
		}
		if(k==0) puts("No");
	}
	return 0;
}
