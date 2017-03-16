#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <functional>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <iostream>

#define ENP     printf("**Entry Point**\n")
#define A       first
#define B       second
#define MP      make_pair

using namespace std;

typedef long long ll;

const int INF = 0x60000000;
const int MINF = -1000000000;
const ll mod = 1000000007;
const int cons = 50000001;
const double pi = 3.141592653589793;

ll dp[7];
bool adj[7][7];

ll fn(int now, int n)
{
	if (now == 1)return 1;

	ll &ret = dp[now];
	if (ret != -1)return ret;

	ret = 0;

	for (int i = 1; i <= n; i++)
	{
		if (adj[i][now] == true)
		{
			ret += fn(i, n);
		}
	}

	return ret;
}

bool fn2(int x, int n, ll m)
{
	if (x > n)
	{
		memset(dp, -1, sizeof(dp));
		if (m == fn(n, n))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int lim = 1 << (n - x);
	for (int i = 0; i < lim; i++)
	{
		int tmp = i;

		for (int j = x + 1; j <= n; j++)
		{
			if (tmp % 2)adj[x][j] = true;
			tmp /= 2;
		}

		if (fn2(x + 1, n, m))return true;

		memset(adj[x], false, sizeof(adj[x]));
	}

	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int testCases;
	scanf("%d", &testCases);

	for (int testNum = 1; testNum <= testCases; testNum++)
	{
		printf("Case #%d: ", testNum);
		
		int n;
		ll m;
		scanf("%d%lld", &n, &m);

		memset(adj, false, sizeof(adj));

		if (fn2(1, n, m))
		{
			puts("POSSIBLE");

			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					printf("%d", adj[i][j]);
				}puts("");
			}
		}
		else
		{
			puts("IMPOSSIBLE");
		}
	}

	return 0;
}