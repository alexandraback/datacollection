#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker,"/STACK:64000000")
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <string>
#include <memory.h>
#include <limits.h>
#include <queue>

using namespace std;

void prepare(string s)
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	if (s.size() != 0)
	{
		freopen((s + ".in").c_str(), "r", stdin);
		freopen((s + ".out").c_str(), "w", stdout);
	}
#endif
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
}

int XX[] = { 0, 1, 1, 1, 0, -1, -1, -1 },
	YY[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int no_bomb;

bool used[50][50];
int n, m, mine, ans;
queue<pair<int, int> > q;

bool in(int y, int x)
{
	return y < n && x < m && y >= 0 && x >= 0;
}

void dfs(int y, int x)
{

}

void happy()
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			if (i == 0 && j == 0)
			{
				cout << 'c';
			}
			else
			if (used[i][j])
			{
				cout << '.';
			}
			else
				cout << '*';
		}
		cout << endl;
	}
}


int main()
{
	prepare("");
	int T;
	cin >> T;
	for (size_t test = 0; test < T; test++)
	{
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				used[i][j] = 0;
			}
		}
		while (q.size())
		{
			q.pop();
		}
		cout << "Case #" << test + 1 << ":" << endl;
		cin >> n >> m >> mine;
		no_bomb = n * m - mine;
		bool flag = 1;
		if ((m == 2 || n == 2) && no_bomb % 2 != 0)
		{
			flag = 0;
		}
		if (m != 1 && n != 1 && no_bomb >= 4 && no_bomb != 5 && no_bomb != 7 && flag)
		{
			for (size_t i = 0; i < 2; i++)
			{
				for (size_t j = 0; j < 2; j++)
				{
					used[i][j] = 1;
					no_bomb--;
					if (!(i == 0 && j == 0))
					{
						q.push(make_pair(i, j));
					}
				}
			}

			int k = 0;
			while (q.size() && no_bomb != 0)
			{
				int y = q.front().first,
					x = q.front().second;
				q.pop();
				int our = 0;
				for (size_t i = 0; i < 8; i++)
				{
					int to_y = y + YY[i],
						to_x = x + XX[i];
					if (in(to_y, to_x) && !used[to_y][to_x])
					{
						our++;
					}
				}

				if (no_bomb % 2 == 1 && our % 2 == 1 || no_bomb % 2 == 0 && our == 2 || no_bomb <= 2 && our == 1 && k >= q.size())
				{
					k = 0;
					no_bomb -= our;
					for (size_t i = 0; i < 8; i++)
					{
						int to_y = y + YY[i],
							to_x = x + XX[i];
						if (in(to_y, to_x) && !used[to_y][to_x])
						{
							used[to_y][to_x] = 1;
							q.push(make_pair(to_y, to_x));
						}
					}
				}
				else
				{
					if (our)
					{
						k++;
						q.push(make_pair(y, x));
					}
					
				}
			}
			happy();
			continue;
		}
		else
		{
			if (no_bomb == 1)
			{
				used[0][0] = 1;
				happy();
				continue;
			}
			if (n == 1 && no_bomb > 0)
			{
				for (size_t i = 0; i < no_bomb; i++)
				{
					used[0][i] = 1;
				}
				happy();
				continue;
			}
			if (m == 1 && no_bomb > 0)
			{
				for (size_t i = 0; i < no_bomb; i++)
				{
					used[i][0] = 1;
				}
				happy();
				continue;
			}
			cout << "Impossible\n";
		}
	}
	return 0;
}
