#include <bits/stdc++.h>
using namespace std;

long long rev(long long int j)
{
	long long int i=0;
	int dig=0;
	
	if(j%10==0)
		return j;
	long long temp=j;
	while(temp)
	{
		dig++;
		temp/=10;
	}
	while(j)
	{
		i+=j%10*pow(10,dig-1);
		dig--;
		j/=10;
	}
	return i;
}

long long dp[1000002];
long long  solve(long long n)
{
//	cout<<n<<" ";
	
	if(n==1)
		return 1;
	if(dp[n]!=-1)
		return dp[n];
	else
	{
		if(rev(n)<n)
			dp[n]=1+min(solve(n-1),solve(rev(n)));
		else
			dp[n]=1+solve(n-1);
		return dp[n];
	}
}
int main() {
	int t;
	cin>>t;
	for(int tt=1;tt<=1000001;tt++)
		dp[tt]=-1;
	for(int tt=1;tt<=t;tt++)
	{
		long long n;
		cin>>n;
		
		
		cout<<"Case #"<<tt<<": "<<solve(n)<<endl;
			
	}
	
	return 0;
}
