#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
#include <stack>
#include <cassert>
#include <set>
#include <string>
#include <cstring>
#define rf freopen("in.txt", "r", stdin);
#define wf freopen("out.out", "w", stdout);
#define rep(i, s, n) for(int i=int(s); i<=int(n); ++i)
using namespace std;
const int mx = 1e6+10;

int n;
int dp[mx];

int rev(int i)
{
	int ret = 0;
	while(i)
	{
		ret = ret*10 + (i%10);
		i/=10;
	}
	return ret;
}

int main()
{
	rf; wf;
	
	int test;
	scanf("%d", &test);

	rep(tt, 1, test)
	{
		scanf("%d", &n);
		memset(dp, 0, sizeof dp);
		rep(i, 1, mx-1)
			dp[i] = 1e9;

		dp[1] = 1;
		rep(i, 2, n)
		{
			int rv = rev(i);
			dp[i] = min(dp[i], dp[i-1]+1);
			
			dp[rv] = min(dp[rv], dp[i]+1);
		}
		printf("Case #%d: %d\n", tt, dp[n]);
	}
	return 0;
}