#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000006];
int rev(int n)
{
	int m = 0;
	while(n)
	{
		m = (m<<1) + (m<<3) + n%10;
		n /= 10;
	}
	return m;
}

void calc()
{
	fill(dp,dp+1000006,1000000000);
	dp[1] = 1;
	for(int i = 1; i <= 1000000; ++i)
	{
		dp[i+1] = min(dp[i+1], dp[i] + 1);
		int r = rev(i);
		dp[r] = min(dp[r], dp[i] + 1);
	}
}

int main()
{
	calc();
	ios_base::sync_with_stdio(0);
	int T;
	cin>>T;
	for(int t = 1; t <= T; ++t)
	{
		int n;
		cin>>n;
		int ans = dp[n];
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
	return 0;
}