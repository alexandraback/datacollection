#include<iostream>
#include<string.h>
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[1005][1005];
int s;
int solve(int r, int t)
{
	if(t<=0)
		return 0;
	if(dp[r][t])
		return dp[r][t];
	int sum = (r+1)*(r+1) - r*r;
	if(sum > t)
	{
		dp[r][t] = 0;
	}
	else
		dp[r][t] = 1 + solve(r+2, t-sum);
	return dp[r][t];
}
int main()
{
	freopen("D:\\ACM\\zj\\codejam\\1in.txt","r",stdin);
    freopen("D:\\ACM\\zj\\codejam\\1out.txt","w",stdout);
    int T, r, t;
    cin>>T;
    int caseid = 1;
    memset(dp, 0, sizeof(dp));
    while(T--)
    {
    	
    	cin>>r>>t;
    	s = 1;
    	int ans = solve(r, t);
    	cout<<"Case #"<<caseid<<": "<<ans<<endl;
    	caseid++;
    }
	return 0;
}
