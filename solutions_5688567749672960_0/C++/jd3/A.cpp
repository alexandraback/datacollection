#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<queue>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;


int list[20];


ll flip(ll a)
{
	int i = 0;
	for( ; a>0 ; i++)
	{
		list[i] = a%10;
		a/=10;
	}
	ll ans=0;
	for(int j = 0 ; j < i ; j++)
	{
		ans *= 10;
		ans += list[j];
	}
	return ans;
}


int dp[10000000];


int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	
	int t;
	
	for(int i = 0 ; i < 10000000 ; i++)
		dp[i] = i;
	dp[1] = 1;
	for(int i = 1 ; i < 10000000 ; i++)
	{
		if(dp[i-1]+1 < dp[i])
			dp[i] = dp[i-1]+1;
		int j = flip(i);
		if(dp[i]+1 < dp[j])
		{
			dp[j] = dp[i]+1;
			if(j < i)
				cout << "!![" << i << "]->[" << j << "] \n";
		}
	}
	
	/*
	for(int i = 0 ; i < 1000000 ; i++)
		cout << dp[i] << ",";
	cout << endl;
	*/
	
	cin >> t;
	for(int time = 1 ; time <= t ; time++)
	{
		ll n;
		cin >> n;
		printf("Case #%d: ", time);
		cout << dp[n] << endl;
	}
	
	return 0;
}

