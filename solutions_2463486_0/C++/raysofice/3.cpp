#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define LL long long
#define MXN 10000002

LL dp[MXN];
int A,B;

bool judge(LL n)
{
	int a[20],len=0;
	while(n)
	{
		a[len++]=n%10;
		n/=10;
	}
	for(int i=0;i<=len/2;++i)
	{
		if(a[i]!=a[len-1-i])
			return false;
	}
	return true;
}

void init(int n)
{
	memset(dp,0,sizeof(dp));
	int s=0;
	for(LL i=1;i<=n;++i)
	{
		if(judge(i) && judge(i*i))
		{
			dp[i]=s+1;
			s=dp[i];
		}
		else
			dp[i]=s;
	}
}

int main()
{
	int i,k,T,cas=0,a1,b1;
	init(100);
	scanf("%d",&T);
	while(T--)
	{
		cas++;
		scanf("%d %d",&A,&B);
		if(A>B)
			swap(A,B);
		a1=sqrt(A);
		b1=sqrt(B);
		if(a1*a1==A)
			a1--;
		printf("Case #%d: %lld\n",cas,dp[b1]-dp[a1]);
	}
	return 0;
}
