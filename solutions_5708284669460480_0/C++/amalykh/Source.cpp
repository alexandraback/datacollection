#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cstring>
#include <queue>
#include <deque>
#include <functional>
#include <climits>
#include <cassert>
#include <list>

#define mp make_pair
#define mt(a, b, c) mp(a, mp(b, c))
#define ABS(a) (((a) > 0) ? (a) : (-(a)))
#define ZERO(x) memset((x), 0, sizeof(x))
#define NEGATE(x) memset((x), 255, sizeof(x))

using namespace std;
typedef long long ll;

const int N = 110;
int u[N][30];

double dp[N][N];

double p[30];

int main()
{
#ifdef XXX
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int tests;
	cin >> tests;
	for (int q = 0; q < tests; q++)
	{
		int k, l, s;
		ZERO(p);
		cin >> k >> l >> s;

		string key;
		cin >> key;
		string t;
		cin >> t;

		for (int i = 0; i < key.size(); i++)
		{
			p[key[i] - 'A'] += 1.0;
		}

		for (int i = 0; i < 30; i++)
			p[i] /= (double)(key.size());

		ZERO(u);
		u[0][t[0] - 'A'] = 1;

		for (int j = 1; j < t.size(); j++)
		{
			for (char c = 'A'; c <= 'Z'; c++)
			{
				if (t[j] == c)
				{
					u[j][c - 'A'] = j + 1;
				}
				else
				{
					for (int k = 1; k <= j; k++)
					{
						string prefix = t.substr(0, k);
						string suffix = t.substr(j - k + 1, k - 1);
						suffix += c;
						if (suffix == prefix)
							u[j][c - 'A'] = k;
					}
				}
			}
		}
		
		ZERO(dp);

		int all = 0;
		for (int i = 1; i < t.size(); i++)
		{
			int len = t.size() - i;
			string suffix = t.substr(i, len);
			string prefix = t.substr(0, len);
			if (suffix == prefix)
			{
				all = max(all, len);
			}
		}

		double ans = 0;

		dp[0][0] = 1;

		for (int i = 0; i < s; i++)
		{
			for (int j = 0; j < t.size(); j++)
			{
				for (int c = 0; c < 26; c++)
				{
					if (u[j][c] != t.size())
						dp[i + 1][u[j][c]] += p[c] * dp[i][j];
					else
					{
						dp[i + 1][all] += p[c] * dp[i][j];
						ans += dp[i][j] * p[c];
						//dp[i + 1][all] = p[c] * (dp[i][j] + 1);
					}
				}
			}
		}

		double ensured = 1 + (s - t.size()) / (t.size() - all);

		for (int i = 0; i < t.size(); i++)
		{
			if (p[t[i] - 'A'] == 0) ensured = 0;
		}

		/*for (int j = 0; j < t.size(); j++)
		{
			ans += dp[s][j];
		}*/

		printf("Case #%d: %.10lf\n", q + 1, ensured - ans);

	}

	return 0;
}