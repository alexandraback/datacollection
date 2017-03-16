//g++ -std=c++0x your_file.cpp -o your_program
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<math.h>
#include<vector>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#define fname ""
#define mp make_pair
#define F first
#define pb push_back
#define S second
#define ub upper_bound
#define lb lower_bound
#define inf 2000000000
#define INF 2000000000000000000ll
using namespace std;

const int maxn = 25;

int f[maxn][maxn], s[maxn][maxn];

string v[maxn][2];

const int N = (1 << 16);

int dp[N + 5];

void solve()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i][0] >> v[i][1];
	memset(f, 0, sizeof(f));
	memset(s, 0, sizeof(s));
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (v[i][0] == v[j][0])
				f[i][j] = 1;
			if (v[i][1] == v[j][1])
				s[i][j] = 1;
		}
	}
	bool ok1, ok2;
	for (int mask = 0; mask < (1 << n); mask++)
	{
		for (int i = 0; i < n; i++)
		{
			if (!(mask & (1 << i)))
			{
				ok1 = ok2 = 0;
				for (int j = 0; j < n; j++)
				{
					if (mask & (1 << j))
					{
						ok1 |= f[i][j];
						ok2 |= s[i][j];
					}
				}
				if ((ok1 && ok2) == 1)
					dp[mask | (1 << i)] = max(dp[mask | (1 << i)], dp[mask] + 1);
				else
					dp[mask | (1 << i)] = max(dp[mask | (1 << i)], dp[mask]);
			}
		}
	}
	cout << dp[(1 << n) - 1] << endl;
}


int main()
{
	freopen (fname"input.txt", "r", stdin);
	freopen (fname"output.txt", "w", stdout);
	int T;
	cin >> T;
	for (int Case = 1; Case <= T; Case++)
	{
		printf("Case #%d: ", Case);
		solve();
	}

	return 0;
}
