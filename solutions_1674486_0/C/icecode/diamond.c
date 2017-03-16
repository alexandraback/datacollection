#include<stdio.h>
int a[1000][1000];
int count;
void dfs(int source,int destination,int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		if(a[source][i]==1)
		{
			if (i==destination)
			{
				count++;
			}
			else dfs(i,destination,n);
		}
	}
	return;
}
int main()
{
	int i,j,t;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		int n;
		int m,k;
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
				a[j][k]=0;
			}
		}
		count=0;
		for(j=1;j<=n;j++)
		{
			scanf("%d",&m);
			for(k=1;k<=m;k++)
			{
				int val;
				scanf("%d",&val);
				a[j][val]=1;
			}
		}
		int flag=0;
		for(j=1;j<=n;j++)
		{
			for(k=1;k<=n;k++)
			{
					dfs(j,k,n);
					if(count<2)	count=0;
					else
					{
						flag=1;
						break;
					}
			}
			if (flag==1)	break;
		}
		if(flag==0)	printf("Case #%d: No\n",i+1);
		else	printf("Case #%d: Yes\n",i+1);
	}
	return 0;
}

