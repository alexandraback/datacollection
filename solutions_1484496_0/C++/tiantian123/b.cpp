#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int n,a[501];
int vis[501];

bool dfs(int sum,int c)
{
	if(sum==0)
		return 1;
	for(int i=c+1; i<n; i++)
	{
		if(!vis[i])
		{
			if(sum-a[i]<0)
				return 0;
			vis[i] = 2;
			if(dfs(sum-a[i],i))
				return 1;
			vis[i] = 0;
		}
	}
	return 0;
}

bool f(int sum,int c)
{
	if(dfs(sum,c))
		return 1;
	int i;
	for(i=c+1; i<n; i++)
	{
		if(!vis[i])
		{
			vis[i] = 1;
			if(f(sum+a[i],i))
				return 1;
			vis[i] = 0;
		}
	}
	return 0;
}

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("output.out","w",stdout);
	int cas = 1;
	int t,i,j,sum,flag;
	scanf("%d",&t);
	while(t--)
	{
		printf("Case #%d:\n",cas++);
		scanf("%d",&n);
		sum = 0;
		for(i=0; i<n; i++)
		{
			scanf("%d",&a[i]);
			sum += a[i];
		}
		memset(vis,0,sizeof(vis));
		sort(a,a+n);
		for(i=1; i<n; i++)
			if(a[i]==a[i-1])
			{
				printf("%d\n%d\n",a[i],a[i-1]);
				break;
			}
		if(i>=n)
		{
			for(i=0; i<n; i++)
			{
				vis[i] = 1;
				if(f(a[i],i))
				{
					for(j=0; j<n; j++)
						if(vis[j]==1)
							printf("%d ",a[j]);
					puts("");
					for(j=0 ;j<n; j++)
						if(vis[j]==2)
							printf("%d ",a[j]);
					puts("");
					break;
				}
				vis[i] = 0;
			}
			if(i>=n)
				puts("Impossible");
		}
	}
	return 0;
}
