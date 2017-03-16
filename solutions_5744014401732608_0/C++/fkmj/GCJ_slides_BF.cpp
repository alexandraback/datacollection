#include <cstdio>
#include <algorithm>
using namespace std;
int adj[10][10]={};
int tadj[10][10]={};
int tadj2[10][10]={};
bool ck(int x,int m)
{
	int a1,a2;
	for(int i=1;i<=x;i++)
	{
		for(int j=1;j<=x;j++)
		{
			if(i==j)tadj[i][j]=1;
			else tadj[i][j]=0;
		}
	}
	adj[x][x]=1;
	for(int z=1;z<=x+3;z++)
	{
		for(int i=1;i<=x;i++)
		{
			for(int j=1;j<=x;j++)
			{
				tadj2[i][j]=0;
				for(int k=1;k<=x;k++)
				{
					tadj2[i][j]+=tadj[i][k]*adj[k][j];
				}
			}
		}
		for(int i=1;i<=x;i++)
		{
			for(int j=1;j<=x;j++)
			{
				tadj[i][j]=tadj2[i][j];
			}
		}
		if(z==x)a1=tadj[1][x];
		if(z==x+3)a2=tadj[1][x];

	}
	return(a1==m&&a1==a2);
}
int main()
{
	int pw2[30]={};
	pw2[0]=1;
	bool found;
	int c,m,n,T;
	for(int i=1;i<30;i++)
	{
		pw2[i]=2*pw2[i-1];
	}
	scanf("%d",&T);
	for(int z=1;z<=T;z++)
	{
		found=false;
		scanf("%d %d",&n,&m);
		if(n==2&&m==1)
		{
			found=true;
			printf("Case #%d: POSSIBLE\n",z);
			printf("01\n00\n");
		}
		for(int i=0;i<pw2[(n-1)+(n-2)*(n-2)];i++)
		{
			c=0;
			if(found)break;
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					adj[j][k]=0;
					if(j==k||j==n||k==1)continue;
					if((i&pw2[c])!=0)
					adj[j][k]=1;
					c++;
				}
			}
			if(ck(n,m))
			{
				adj[n][n]=0;
				found=true;
				printf("Case #%d: POSSIBLE\n",z);
				for(int j=1;j<=n;j++)
				{
					for(int k=1;k<=n;k++)
					{
						printf("%d",adj[j][k]);
					}
					printf("\n");
				}
				break;
			}
		}
		if(!found)
		{
			printf("Case #%d: IMPOSSIBLE\n",z);
		}
	}
}
