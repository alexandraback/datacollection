// Copyright @Vipul Verma
// Created on 2/05/2014
#include<iostream>
using namespace std;
using namespace std;
long long int rever(int n)
{
	long long int ans = 0;
	while(n!=0)
	{
		ans = ans*10 + n%10;
		n/=10;
	}
	return ans;
}
int dp[1000001];
int main()
{
	int t;
	int k=1;
	cin >> t;
	for(int i=1;i<=1000000;i++)
   		dp[i]=-1;
	dp[0]=0;
   	for(int i=1;i<=1000000;i++)
   	{
   		long long int  tmp=rever(i);
   		if(tmp!=i && dp[tmp]!=-1 && i%10!=0 && tmp<=1000000)
   		{
			dp[i]=min(dp[i-1]+1,dp[tmp]+1);
   		}
   		else
   		{
   			dp[i]=dp[i-1]+1;
   		}
   	}
	while(t--)
	{
		long long int n;
		cin>>n;
		long long int ans=dp[n];
		cout<<"Case #"<<k<<": "<<ans<<"\n";
		k++;
	}
	return 0;
}