#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define mod 1000000007
using namespace std;
int dp[10000002];
int reverse(int n)
{
	int num=0;
	while(n)
	{
		num=num*10+(n%10);
		n/=10;
	}
	return num;
}
void solve()
{
	dp[1]=1;
	for(int i=2;i<1000001;i++)
	{
		if(dp[i]==0)
		{
			dp[i]=dp[i-1]+1;
			if(reverse(i)>i)	dp[reverse(i)]=1+dp[i];
		}
		else
		dp[i]=min(dp[i],1+dp[i-1]);		
	}
}
int main()
{
  std:ios_base::sync_with_stdio(false);
  freopen ("A-small-attempt0 (3).in", "r", stdin);
  freopen ("Asmallout.in", "w", stdout);
  int i; 
  solve();
  int t,cs=1;
  int n;
  cin>>t;
  while(t--)
  {
  	cin>>n;
  	cout<<"Case #"<<cs++<<": "<<dp[n]<<"\n";
  }
  return 0;
}

