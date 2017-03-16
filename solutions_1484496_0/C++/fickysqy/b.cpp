#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<memory.h>
#define N 510
using namespace std;
__int64 a[N];
int go[N];
int n;
bool cmp(__int64 a,__int64 b)
{
	return a<b;
}

bool dfs(__int64 sum,int i)
{
	int j;
	if(sum==0)
	return 1;
	for(j=i+1;j<n;j++)
	{
		if(a[j]==a[j-1])
		{
			memset(go,0,sizeof(go));
			go[j]=1;
			go[j-1]=2;
			return 1;
		}
		if(!go[j])
		{
			if(sum-a[j]<0)
			return 0;
			go[j]=2;
			if(dfs(sum-a[j],j))
			return 1;
			go[j]=0;
		}
	}
	return 0;
}

bool All(__int64 sum,int i)
{
	int j;
	if(dfs(sum,i))
	return 1;
	for(j=i+1;j<n;j++)
	{
		if(!go[j])
		{
			go[j]=1;
			if(All(sum+a[j],j))
			return 1;
			go[j]=0;
		}
	}
	return 0;
}
		
int main()
{
	int t;
	int i,cas;
	__int64 sum,flag;
	freopen("C-small-attempt1.in","r",stdin);
	freopen("ans.txt","w",stdout);
	scanf("%d",&t);
	for(cas = 1 ; cas <= t ; cas++)
	{
		scanf("%d",&n);
		sum=0;
		for(i=0;i<n;i++)
		{
			scanf("%I64d",&a[i]);
			sum+=a[i];
		}
		memset(go,0,sizeof(go));
		sort(a,a+n,cmp);
		flag=0;
		for(i=0;i<n;i++)
		{
			go[i]=1;
			if(All(a[i],i))
			{
				flag=1;
				break;
			}
			go[i]=0;
		}
		printf("Case #%d:\n",cas);
		if(flag)
		{
			for(i=0;i<n;i++)
			{
				if(go[i]==1)
					printf("%I64d ",a[i]);
			}
			printf("\n");
			for(i=0;i<n;i++)
			{
				if(go[i]==2)
					printf("%I64d ",a[i]);
			}
			printf("\n");
		}
		else
			printf("Impossible\n");
	}
	return 0;
}
