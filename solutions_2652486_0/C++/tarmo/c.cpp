#include<cstdio>
#include<cstdlib>
#include<cstring>
int r,n,m,k,a[10000],b[20],v[1000][50];
void ra()
{
	for(int i=1;i<=n;i++)
	{
		b[i]=rand()%(m-1)+2;
	}
}
bool dfs(int x,int prev)
{
	if(x==1)return 1;
	if(v[x][prev])
	{
		if(v[x][prev]==1)return 1;
		else return 0;
	}
	for(int i=prev;i<=n;i++)
		if(x%b[i]==0)
		{
			if(dfs(x/b[i],i+1))
			{
				for(int j=prev;j;j--)v[x][j]=1;
				return 1;
			}
		}
	for(int j=prev;j<=n;j++)v[x][j]=-1;
	return 0;
}
bool check()
{
	memset(v,0,sizeof(v));
	for(int i=1;i<=k;i++)
	{
		if(!dfs(a[i],1))return 0;
	}
	return 1;
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	srand(666);
	scanf("%d",&n);
	printf("Case #1:\n");
	scanf("%d%d%d%d",&r,&n,&m,&k);
	while(r--)
	{
		for(int j=1;j<=k;j++)
		{
			scanf("%d",&a[j]);
		}
		for(int i=1;i<=10;i++)
		{
			while(1)
			{
				ra();
				if(check())break;
			}
		}
		for(int i=1;i<=n;i++)printf("%d",b[i]);
		printf("\n");
	}
}
