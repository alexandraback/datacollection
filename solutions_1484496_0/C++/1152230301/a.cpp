#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<memory.h>
#define N 505
using namespace std;

int a[N];
int vis[N];
int n;
bool cmp(int a,int b)
{
	return a<b;
}

bool dfs(int sum,int i)
{
	int j;
	if(sum==0)
	return 1;
	for(j=i+1;j<n;j++)
	{
		if(!vis[j])
		{
			if(a[j]==a[j-1])
			{
				printf("%d\n%d\n",a[j],a[j-1]);
				return 1;
			}
			if(sum-a[j]<0)
			return 0;
			vis[j]=2;
			if(dfs(sum-a[j],j))
			return 1;
			vis[j]=0;
		}
	}
	return 0;
}

bool f(int sum,int i)
{
	int j;
	if(dfs(sum,i))
	return 1;
	for(j=i+1;j<n;j++)
	{
		if(!vis[j])
		{
			vis[j]=1;
			if(f(sum+a[j],j))
			return 1;
			vis[j]=0;
		}
	}
	return 0;
}
		
int main()
{
	int t;
	int i,cas=1;
	int sum,flag;
	freopen("re.txt","r",stdin);
	freopen("ans.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		memset(vis,0,sizeof(vis));
		sort(a,a+n,cmp);
		flag=0;
		for(i=0;i<n;i++)
		{
			vis[i]=1;
			if(f(a[i],i))
			{
				flag=1;
				break;
			}
			vis[i]=0;
		}
		printf("Case #%d:\n",cas++);
		if(flag)
		{
			for(i=0;i<n;i++)
			if(vis[i]==1)
			printf("%d ",a[i]);
			printf("\n");
			for(i=0;i<n;i++)
			if(vis[i]==2)
			printf("%d ",a[i]);
			printf("\n");
		}
		else
		printf("Impossible\n");
	}
	return 0;
}

