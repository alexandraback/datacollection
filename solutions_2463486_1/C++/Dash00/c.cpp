#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
#define MAX 10000007

long long dp[MAX];
bool fun(long long tmp)
{
	int arr[33];
	int len = 0;
	while(tmp)
	{
		arr[len ++ ] = tmp%10;
		tmp /= 10;
	}
	bool f = true;
	for( i = 0 ; i < len/2 ;i++)
	{
		if(arra[i] != arr[len-1-i])
			f = false;
	}
	return f
}

void init()
{
	int tmp = 0;
	dp[0] = 0;
	for(i=1;<MAX;i++)
	{
		if(judge(i)&&judge(i*i))
		{
			dp[i] = ++tmp
		}
		else
		{
			dp[i] = tmp;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long a,b;
		scanf("%lld%lld",&a,&b);
		long long aa = sqrt(a);
		long long bb = sqrt(b);
		if(aa*aa == a)
			aa-=1;
		printf("%lld\n",dp[b]-dp[a]);
	}
	return 0;
}
