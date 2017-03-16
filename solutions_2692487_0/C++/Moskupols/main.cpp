#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cstdlib>
#include <cassert>
using namespace std;

#ifdef moskupols 
    #define debug(...) fprintf(stderr, __VA_ARGS__) // thank Skird it's friday!
#else
    #define debug(...) 
#endif

const int maxa = 1000005, maxn = 105;

int dp[maxa][maxn];
int s[maxn];

int solve()
{
	int a, n;
	cin >> a >> n;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	sort(s, s+n);
	int ma = s[n-1]+1;

	if (a >= ma)
		return 0;
	int ret = 1<<30;

	for (int i = 0; i <= ma; ++i)
		for (int j = 0; j <= n; ++j)
			dp[i][j] = 1<<30;

	dp[a][0] = 0;
	for (int i = a; i <= ma; ++i)
	{
		for (int j = 0; j <= n; ++j)
		{
			if (dp[i][j] == 1<<30)
				continue;
			ret = min(ret, dp[i][j] + n-j);
			if (j == n)
				continue;
			if (i > s[j])
			{
				int ne = min(ma, i+s[j]);
				dp[ne][j+1] = min(dp[ne][j+1], dp[i][j]);
			}
			int ne = min(ma, i + i - 1);
			dp[ne][j] = min(dp[ne][j], dp[i][j] + 1);
		}
	}
	return ret;
}

int main()
{
	cin.sync_with_stdio(false);

	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		cout << "Case #" << i << ": " << solve() << endl;
	}

	return 0;
}
