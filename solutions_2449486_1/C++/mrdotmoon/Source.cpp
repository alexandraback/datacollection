#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

int graph[101][101];
int n, m, maxVal;

bool validate(int row, int col)
{
	int cur = graph[row][col];
	bool ret = true;
	for (int i = 0; i < n; i++)
	{
		if (graph[i][col] != cur)
		{
			ret = false;
			break;
		}
	}

	if (ret) return ret;

	ret = true;
	for (int i = 0; i < m; i++)
	{
		if (graph[row][i] != cur)
		{
			ret = false;
			break;
		}
	}
	return ret;
}
bool can(int minVal)
{
	if (minVal == maxVal)
		return true;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (graph[i][j] == minVal)
			{
				if (!validate(i, j))
					return false;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (graph[i][j] == minVal)
			{
				graph[i][j]++;
			}
		}
	}

	return can(minVal + 1);
}
void _main()
{
	scanf("%d%d", &n, &m);

	int minVal = 100;
	maxVal = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &graph[i][j]);
			minVal = min(graph[i][j], minVal);
			maxVal = max(graph[i][j], maxVal);
		}
	}

	if (can(minVal))
	{
		puts("YES");
	}
	else
	{
		puts("NO");
	}
}
int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int cases;
	scanf("%d", &cases);
	for (int i = 1; i <= cases; i++)
	{
		printf("Case #%d: ", i);
		_main();
	}

}