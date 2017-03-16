#include<stdio.h>
#include<memory.h>
char hash[1005],map[1005][1005];
int n;
int BFS(int p)
{
	int q[1005],i,h,t;
	h=t=0;
	memset(hash,0,sizeof(hash));
	q[0]=p;
	hash[p]=1;
	while(h<=t)
	{
		for(i=1;i<=n;i++)
		{
			if(hash[i]&&map[q[h]][i]) return 1;
			if(map[q[h]][i]&&!hash[i])
			{
				q[++t]=i;
				hash[i]=1;
			}
		}
		h++;
	}
	return 0;
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int t,c,m,i,j;
	scanf("%d",&t);
	for(c=1;c<=t;c++)
	{
		printf("Case #%d: ",c);
		memset(map,0,sizeof(map));
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d",&j);
				map[i][j]=1;
			}
		}
		for(i=1;i<=n;i++)
		{
			if(BFS(i))
			{
				printf("Yes\n");
				break;
			}
		}
		if(i>n) printf("No\n");
	}
	return 0;
}