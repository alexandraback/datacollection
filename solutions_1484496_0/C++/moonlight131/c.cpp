#include<iostream>
#include<cstdio>
#include<vector>
#include<list>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<cmath>

using namespace std;

#define maxn 1100
#define maxm 1100000
#define eps 1e-10
#define inf 1000000000

int f[maxn],mat[maxn],n,l,r;
bool flag;
void dfs(int x)
{
	int z,i,j;
	if(x==n)
	{
		if(l!=r)return ;
		for(j=0;j<2;j++)
		{
			z=0;
			for(i=0;i<n;i++)
			{
				if(f[i]==j)
				{
					if(z)printf(" ");
					else z=1;
					printf("%d",mat[i]);
				}
			}
			puts("");
		}
		flag=false;
		return ;
	}
	if(flag)
	{
		f[x]=0;
		l+=mat[x];
		dfs(x+1);
	}
	if(flag)
	{
		f[x]=1;
		l-=mat[x];
		r+=mat[x];
		dfs(x+1);
	}
	if(flag)
	{
		f[x]=2;
		r-=mat[x];
		dfs(x+1);
	}
}
int main()
{
	int t,ca,i;
	scanf("%d",&t);
	for(ca=1;ca<=t;ca++)
	{
		printf("Case #%d:\n",ca);
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&mat[i]);
		}
		l=r=0;
		flag=true;
		dfs(0);
		if(flag)puts("Impossible");
	}
}
