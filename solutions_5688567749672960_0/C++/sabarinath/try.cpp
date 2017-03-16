#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cstdio>
#include <cstdlib>
using namespace std;
vector<long long> no;
long long dp[4000002];

long long rev(long long n)
{
	long long i,ans=0;
	while(n)
	{
		ans=ans*10+ n%10 ;
		n/=10;
	}
	return ans;
}
long long msb(long long n)
{
	while(n/10)
	n/=10;
	return n;
}

int main() 
{
	freopen("input.txt","r",stdin);
	freopen("output2.txt","w",stdout);
	long long t,i,n,cnt,T,x;
	for(i=1;i<=1000000;i++)
	dp[i]=INT_MAX;
	for(i=1;i<=9;i++)
	dp[i]=i;
	for(i=10;i<=1000000;i++)
	{
		dp[i]=min(dp[i],dp[i-1]+1);
		x=rev(i);
		if(i%10)
		dp[i]=min(dp[i],dp[x]+1);
		dp[x]=min(dp[x],dp[i]+1);
	}
	cin>>T;
	for(t=0;t<T;t++)
	{
		cin>>n;
		cout<<"Case #"<<t+1<<": "<<dp[n]<<"\n";
	
	}
	return 0;
}
