#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
#include <functional>
#include <algorithm>
#include <stdint.h>
using namespace std;

int64_t reverse(int64_t n)
{
	int64_t ans = 0;
	while (n)
	{
		ans *= 10;
		ans += n % 10;
		n /= 10;
	}
	return ans;
}

map<int64_t, int64_t> dp;

int64_t get_val(int64_t n)
{
	int64_t cur = n;
	int64_t ans = 1;
	while (cur != 1)
	{
		if (dp.count(cur))
		{
			ans += dp[cur]-1;
			break;
		}
		int64_t next1 = reverse(cur);
		int64_t next2 = cur - 1;
		if (cur % 10 == 0)
			cur = next2;
		else
			cur = min(next1, next2);		
		++ans;
	}
	return ans;
}

void init()
{
	int64_t n = 1000 * 1000;
	dp.clear();
	dp[1] = 1;
	for (int64_t i = 2; i <= n; ++i)
	{
		int64_t cur = get_val(i);
		dp[i] = min(cur, dp[i - 1] + 1);
	}
}

void solve(int test)
{
	int64_t n;
	cin >> n;	
	cout << "Case #" << test << ": " << dp[n] << endl;
}

int main(void)
{
	init();
#if 1
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		solve(i);
	}
	return 0;
}