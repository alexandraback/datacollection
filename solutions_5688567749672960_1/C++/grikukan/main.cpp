#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<bitset>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<queue>
using namespace std;
long long dp[10000007];
long long add[] = { 0, 1, 9, 19, 109, 199, 1099, 1999, 10999, 19999, 109999, 199999, 1099999, 1999999, 10999999, 19999999, 109999999, 199999999, 1099999999 };
long long need[17];
long long solve1(long long x, int len)
{
	long long base = 1;
	for (int i = 1; i < len; i++)
	{
		base *= 10;
	}
	return x - base;
}
long long solve2(long long x, int len)
{
	long long tmp = x;
	vector<int>digs;
	while (tmp>0)
	{
		digs.push_back(tmp % 10);
		tmp /= 10;
	}
	reverse(digs.begin(), digs.end());
	int mid = len / 2;
	long long ans = 0;
	long long ans1 = 0;
	for (int i = mid; i < digs.size(); i++)
	{
		ans1 = ans1 * 10 + digs[i];
	}
	long long ans2 = 0;
	for (int i = mid - 1; i >= 0; i--)
	{
		ans2 = ans2 * 10 + digs[i];
	}
	ans = ans1 + ans2;
	return ans;
}
long long solve3(long long x, int len)
{
	long long tmp = x;
	vector<int>digs;
	while (tmp>0)
	{
		digs.push_back(tmp % 10);
		tmp /= 10;
	}
	reverse(digs.begin(), digs.end());
	int mid = len / 2;
	long long ans = 0;
	long long ans1 = 0;
	for (int i = mid + 1; i < digs.size(); i++)
	{
		ans1 = ans1 * 10 + digs[i];
	}
	long long ans2 = 0;
	for (int i = mid; i >= 0; i--)
	{
		ans2 = ans2 * 10 + digs[i];
	}
	ans = ans1 + ans2;
	return ans;
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	for (int i = 1; i <= 14; i++)
	{
		need[i] = need[i - 1] + add[i];
	}
	for (int i = 2; i <= 14; i++)
	{
		//	need[i]--;
	}
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		long long x;
		cin >> x;
		int len = 0;
		long long tmp = x;
		while (tmp > 0)
		{
			len++;
			tmp /= 10;
		}
		long long ans = need[len];
		ans += min(min(solve1(x, len), solve2(x, len)), solve3(x, len));
		cout <<"Case #"<<tt<<": "<< ans << endl;
	}
}
