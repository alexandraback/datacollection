#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <map>

typedef long long LL;

using namespace std;

const int INF = 1e9;

int dp[1000007];

vector <int> buf;

int rev(int z)
{
	buf.clear();
	while (z > 0)
	{
		buf.push_back(z % 10);
		z /= 10;
	}
	int res = 0;
	for (int j = 0; j  < buf.size(); j++)
	{
		res *= 10;
		res += buf[j];
	}
	return res;
}

int main ()
{
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
	int t;
	cin >> t;
	for (int i = 0; i < 1e6 + 2; i++)
	{
		dp[i] = INF;
	}
	dp[1] = 1;
	for (int i = 2; i <= 1e6; i++)
	{
		if (i % 10 != 0)
			dp[i] = min(dp[i - 1], dp[rev(i)]) + 1;
		else
			dp[i] = dp[i - 1] + 1;
	}
	for (int i = 1; i <= t; i++)
	{
		int n;
		cin >> n;
		cout << "Case #" << i << ": " << dp[n] << endl;
	}
    //for(;;);
    return 0;
}
