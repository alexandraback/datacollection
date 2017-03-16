#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:268435456")

#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;


int dp[105][105];

bool canBeSurprising(int t, int p)
{
	for (int a = 0; a <= 10; a++)
		for (int b = max(a-2, 0); b <= min(a+2, 10); b++)
		{
			int c = t - a - b;
			if (0 <= c && c <= 10 && abs(a-c) <= 2 && abs(b-c) <= 2 && max(max(a,b),c) >= p)
				return true;
		}
	return false;
}

bool canBeUsual(int t, int p)
{
	for (int a = 0; a <= 10; a++)
		for (int b = max(a-1, 0); b <= min(a+1, 10); b++)
		{
			int c = t - a - b;
			if (0 <= c && c <= 10 && abs(a-c) <= 1 && abs(b-c) <= 1 && max(max(a,b),c) >= p)
				return true;
		}
	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int testCount;
	cin >> testCount;
	for (int test = 1; test <= testCount; test++)
	{
		int n, s, p;
		cin >> n >> s >> p;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];

		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= n; j++)
				if (dp[i][j] != -1)
				{
					if (canBeSurprising(v[i], p))
						dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + 1);
					else
						dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]);

					if (canBeUsual(v[i], p))
						dp[i+1][j] = max(dp[i+1][j], dp[i][j] + 1);
					else
						dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
				}

		printf("Case #%d: %d\n", test, dp[n][s]);
	}

	return 0;
}