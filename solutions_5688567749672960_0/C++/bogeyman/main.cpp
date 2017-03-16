#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <fstream>
#include <map>
#include <cmath>
#include <set>
#include <string.h>
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long ll;

ll rev(ll x)
{
	ll res = 0;
	while(x > 0)
	{
		res = res * 10 + (x % 10);
		x /= 10;
	}
	return res;
}

int t, m = int(1e7);

int dp[ll(1e6) + 10];

int main()
{
	freopen("/Users/user/Downloads/A-small.in", "r", stdin);
	freopen("key.out", "w", stdout);
	cin >> t;
	dp[1] = 1;
	for(int i = 2; i < int(1e6) + 5; i++)
		if(rev(i) < i && (i % 10 != 0))
			dp[i] = min(dp[rev(i)], dp[i - 1]) + 1;
		else
			dp[i] = dp[i - 1] + 1;
	
	for(int q = 0; q < t; q++)
	{
		int x;
		cin >> x;
		printf("Case #%d: %d\n", q + 1, dp[x]);
	}
}