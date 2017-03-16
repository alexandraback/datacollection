#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
bool g[88][88] = { false };
int code[88];
bool visited[88] = { false };
bool check[88] = { false };
int ans[88];

void dfs(int now)
{
	check[now] = true;
	for (int i = 1; i <= n; i++)
	if (g[now][i] && (!check[i]) && (!visited[i]))
		dfs(i);
}

int path(int pos, int x)
{
	for (int i = pos - 1; i >= 0; i--)
	{
		if (g[ans[i]][x]) 
			return i;
	}
	return -1;
}

int main()
{
	int T;
	cin >> T;
	for (int c = 1; c <= T; c++)
	{
		

		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			cin >> code[i];
		memset(g, 0, sizeof(g));
		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			g[x][y] = g[y][x] = true;
		}

		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; i++)
		{
			int best = 99999999;
			ans[i] = 0;
			for (int j = 1; j <= n; j++)
			if (visited[j] == false && code[j] < best && (i == 0 || path(i, j) >= 0))
			{
				int back = ans[i];
				ans[i] = j;
				int up = path(i, j);
				memset(check, 0, sizeof(check));
				for (int k = 0; k <= up; k++)
					dfs(ans[k]);
				dfs(j);
				bool ok = true;
				for (int k = 1; k <= n; k++)
				if (!(check[k] || visited[k]))
				{
					ok = false;
					break;
				}
				if (ok)
				{
					best = code[j];
				}
				else
					ans[i] = back;
			}
			visited[ans[i]] = true;
		}
	

		cout << "Case #" << c << ": ";
		for (int i = 0; i < n; i++)
			cout << code[ans[i]];
		cout << endl;	
	}
	return 0;
}