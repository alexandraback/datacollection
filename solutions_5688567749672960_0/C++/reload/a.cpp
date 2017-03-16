#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <set>
using namespace std;
#define oo 1000000007

long long int dp[1000005];
long long int rev(long long int n)
{
	long long int rev=0;
	while(n>0)
	{
		rev=rev*10+n%10;
		n=n/10;
	}
	return rev;

}
long long int func(long long int n)
{
	if( dp[n]!=0 ) return dp[n];

	if(n==1)
		return 1;

	long long int z=rev(n);
	long long int ans=123456789;

		if(n-1>=z && (n%10!=0) )
			ans=min(ans,1 + func(z));
		ans=min(ans,1 + func(n-1));

	return dp[n]=ans;	
}
int main()
{
	long long int t,n;
	cin>>t;
	for(int i=0;i<=1000000;i++){
		dp[i]=0;	
	}
	for(int i=0;i<t;i++){
		cin>>n;
		//cout<<n<<endl;
		cout<<"Case #"<<i+1<<": ";
		cout<<func(n)<<endl;
	}	

}
