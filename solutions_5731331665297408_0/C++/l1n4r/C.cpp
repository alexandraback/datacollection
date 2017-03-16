
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <memory>
using namespace std;

typedef unsigned long long ull;

int g[64][64];

int n, m;
ull mask_all_visited;
vector<string> z;
string ans;

void solve(const int u, const ull mask, const string& s)
{
	if (mask == mask_all_visited)
	{
		bool f = true;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (g[i][j] < 0)
				{
					f = false;
					break;
				}
			}
			if (!f)
			{
				break;
			}
		}

		if (f)
		{
			if (ans == "")
			{
				ans = s;
			}
			else
			{
				if (s < ans)
				{
					ans = s;
				}
			}
		}
	}
	else
	{
		for (int v = 0; v < n; v++)
		{
			if (g[u][v] > 0)
			{
				if (!(mask & (1<<v)))
				{
					g[u][v] = -1;
					g[v][u] = -1;

					solve(v, mask | (1<<v), s+z[v]);

					g[u][v] = 1;
					g[v][u] = 1;
				}
			}
		}
	}

	for (int v = 0; v < n; v++)
	{
		if (g[u][v] < 0)
		{
			g[u][v] = 0;
			g[v][u] = 0;

			solve(v, mask, s);

			g[u][v] = -1;
			g[v][u] = -1;
		}
	}
}

int main()
{
	static char tmp[16];

	gets(tmp);
	int test_cases;
	sscanf(tmp, "%d", &test_cases);

	for (int test_case = 1; test_case <= test_cases; test_case++)
	{
		gets(tmp);
		sscanf(tmp, "%d %d", &n, &m);

		mask_all_visited = (1<<n) - 1;

		z.resize(n);

		for (int i = 0; i < n; i++)
		{
			gets(tmp);
			z[i] = tmp;

			for (int j = 0; j < n; j++)
			{
				g[i][j] = 0;
			}
		}

		for (int i = 0; i < m; i++)
		{
			int x, y;
			gets(tmp);
			sscanf(tmp, "%d %d", &x, &y);
			x--;
			y--;
			g[x][y] = 1;
			g[y][x] = 1;
		}

		ans = "";
		for (int i = 0; i < n; i++)
		{
			solve(i, 1<<i, z[i]);
		}

		printf("Case #%d: %s\n", test_case, ans.c_str());
	}

	return 0;
}