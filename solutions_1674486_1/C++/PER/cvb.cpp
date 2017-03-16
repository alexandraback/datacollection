#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

bool f = false;
int used[1005] = {0};

vector < vector <int> > e(1005);

void dfs(int dest, int num)
{
	if (used[dest] == num)
	{
		f = true;
		return;
	}
	used[dest] = num;
	int enn = e[dest].size();
	for (int i = 0; i < enn; i++)
	{
		if (!f)
			dfs(e[dest][i], num);
	}
}

int main()
{
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	int T;
	scanf("%d ", &T);
	for (int k = 0; k < T; k++)
	{
		int n;
		scanf("%d ", &n);
		int a,b;
		f = false;
		int inner[1005] = {0};
		for (int i = 0; i < 1005; i++)
		{
			used[i] = 0;
			e[i].clear();
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d ", &a);
			for (int j = 0; j < a; j++)
			{
				scanf("%d ", &b);
				e[i].push_back(b - 1);
				inner[b - 1]++;
			}
		}
		int nn = 1;
		for (int i = 0; i < n; i++)
		{
			if (f)
				break;
			if (!inner[i])
			{
				dfs(i,nn);
				nn++;
			}
		}
		if (f)
			printf("Case #%d: Yes\n", k + 1);
		else
			printf("Case #%d: No\n", k + 1);

	}

	return 0;
}