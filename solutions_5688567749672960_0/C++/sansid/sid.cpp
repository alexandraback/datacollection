#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;

long long int a[1000006],b[1000006],dp[1000006];

long long int fn(long long int x)
{
	long long int i,ans,j,num[106];
	i=0;
	while(x!=0)
	{
		num[i++]=x%10;
		x=x/10;
	}
	x=1;ans=0;
	for(j=i-1;j>=0;j--)
	{
		ans=ans+num[j]*x;
		x=x*10;
	}
	return ans;
}

int main()
{
	freopen("abc.txt","r",stdin);
	freopen("test.txt","w",stdout);
	long long int i,j,n,c,f1,f;
	for(i=0;i<1000006;i++)
	{
		dp[i]=-1;
	}
	dp[0]=0;
	n=1;
	a[0]=0;
	c=1;
	while(1)
	{
		if(n==0)
		break;
		j=0;
		for(i=0;i<n;i++)
		{
			if(dp[a[i]+1]==-1 && a[i]+1<=1000000)
			{
				dp[a[i]+1]=c;
				b[j++]=a[i]+1;
			}
			if(dp[fn(a[i])]==-1 && fn(a[i])<=1000000)
			{
				dp[fn(a[i])]=c;
				b[j++]=fn(a[i]);
			}
		}
		c++;
		n=j;
		for(i=0;i<n;i++)
		a[i]=b[i];
	}
	scanf("%lld",&f);
	for(f1=1;f1<=f;f1++)
	{
		scanf("%lld",&n);
		printf("Case #%lld: %lld\n",f1,dp[n]);
	}
	return 0;
}
