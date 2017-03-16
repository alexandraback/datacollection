#include<stdio.h>
#include<string.h>
#define maxn 1010
int f[maxn][maxn];
int n;
int main()
{
	int i,j,k,t,m;
	int cur,flag;
	int cases;
	freopen("test.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&cases);
	for(t=1;t<=cases;t++)
	{
		printf("Case #%d: ",t);
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(j=0;j<m;j++)
			{
				scanf("%d",&cur);
				f[i][cur]=1;
			}
		}

		for(k=1,flag=0;k<=n && !flag;k++)
		{
			for(i=1;i<=n && !flag;i++)
			if(i!=k)
			for(j=1;j<=n;j++)
			if(j!=i && j!=k)
			{
				f[i][j]+=f[i][k]*f[k][j];
				if(f[i][j]>1){flag=1;break;}
			}
		}
		if(flag)printf("Yes\n");
		else	printf("No\n");
	}
	return 0;
}
