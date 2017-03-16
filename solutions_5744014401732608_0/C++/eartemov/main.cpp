//#define MYDEBUG
#define _CRT_SECURE_NO_WARNINGS
#define TASK "B-small-attempt0"
#pragma comment(linker, "/STACK:536870912")
#include <cstdio>
#include <iostream>
#include <iomanip> 
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <functional>
#include <cassert>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <random>

const int MOD = 1000000007;
const int INF = 1000000001;
const int MAXN = 100010;
const long double EPS = 1e-8;
const int HASH_POW = 29;
const long double PI = acos(-1.0);

using namespace std;

void my_return(int code)
{
#ifdef MYDEBUG
	cout << "\nTime = " << fixed << setprecision(3) << double(clock()) / CLOCKS_PER_SEC << endl;
#endif
	exit(code);
}

int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	mt19937 mt_rand(time(0));
#ifdef MYDEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen(TASK".in", "rt", stdin);
	freopen(TASK".out", "wt", stdout);
	/*freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);*/
#endif

	int CASE;
	cin >> CASE;
	for (int it = 1; it <= CASE; ++it)
	{
		int b, m;
		cin >> b >> m;
		int ans = -1;
		char G[6][6];
		memset(G, '0', sizeof G);
		for (int msk = 0; msk < (1 << (b*(b - 1) / 2)); ++msk)
		{
			int x = 0, y = 1;
			for (int j = 0; j < b*(b - 1) / 2; ++j)
			{
				if (msk & (1 << j))
					G[x][y] = '1';
				++y;
				if (y == b)
				{
					++x;
					y = x + 1;
				}
			}

			int dp[6];
			dp[0] = 1;
			for (int i = 1; i < b; ++i)
				dp[i] = 0;
			for (int i = 0; i < b - 1; ++i)
			{
				for (int j = i + 1; j < b; ++j)
				{
					if (G[i][j] == '1')
						dp[j] += dp[i];
				}
			}

			x = 0, y = 1;
			for (int j = 0; j < b*(b - 1) / 2; ++j)
			{
				if (msk & (1 << j))
					G[x][y] = '0';
				++y;
				if (y == b)
				{
					++x;
					y = x + 1;
				}
			}

			if (dp[b - 1] == m)
			{
				ans = msk;
				break;
			}
		}

		cout << "Case #" << it << ": ";
		if (ans == -1)
			cout << "IMPOSSIBLE" << endl;
		else
		{
			cout << "POSSIBLE" << endl;
			int x = 0, y = 1;
			for (int j = 0; j < b*(b - 1) / 2; ++j)
			{
				if (ans & (1 << j))
					G[x][y] = '1';
				++y;
				if (y == b)
				{
					++x;
					y = x + 1;
				}
			}
			for (int i = 0; i < b; ++i)
			{
				for (int j = 0; j < b; ++j)
					cout << G[i][j];
				cout << endl;
			}
		}
	}

	my_return(0);
}