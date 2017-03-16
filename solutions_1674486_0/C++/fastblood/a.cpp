#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <memory.h>
#include <algorithm>
#include <cassert>
#include <math.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define _(a, b) memset(a, b, sizeof(a))

typedef long long lint;
typedef unsigned long long ull;

const double eps = 1e-9;
const int INF = 1000000000;
const lint LINF = 4000000000000000000ll;

void prepare()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int n;
vector<int> g[1005];

bool used[1005];

bool dfs(int x)
{
	used[x] = true;
	for (int i = 0; i < g[x].size(); i++)
		if (!used[g[x][i]])
		{
			if (dfs(g[x][i]))
				return true;
		}
		else
			return true;
	return false;
}

bool solve()
{
	for (int i = 0; i < 1005; i++)
		g[i].clear();

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{
			int b;
			scanf("%d", &b);
			g[i].pb(b - 1);
		}
	}

	static int TT = 0;
	printf("Case #%d: ", ++TT);

	bool ans = false;
	for (int i = 0; i < n && !ans; i++)
	{
		_(used, 0);
		ans = dfs(i);
	}

	if (ans)
		printf("Yes\n");
	else
		printf("No\n");

	return false;
}

int main()
{
	prepare();
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
		solve();
	return 0;
}