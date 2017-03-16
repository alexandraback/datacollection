#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <cmath>
#include <queue>
using namespace std;

queue<pair<pair<int, int> , int> > q;
int R, C, M;
char board[100][100];
int boardx[100][100];

int t[] = {1, -1, 0, 0};
int tt[] = {0, 0, 1, -1};

void clear()
{
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			board[i][j] = 0;
		}
	}
	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			board[i][j] = '.';
		}
	}
}

int is_boreder(int x, int y, int d)
{
	if (x == 1 || y == 1 || x == R || y == C) return true;
	//if (board[x + t[d]][y + tt[d]] == 0) return true;
	return false;
}

int try_this(int x, int y, int d)
{
	int ret = 1;

	for (int i = 0; i < 4; ++i)
	{
		if (is_boreder(x + t[i], y + tt[i], d) && board[x + t[i]][y + tt[i]] == '.')
		{
			ret += 1;
		}
	}

	return ret;
}

void gox(int x, int y)
{
	for (int i = 0; i < 4; ++i)
	{
		q.push(make_pair(make_pair(x + t[i], y + tt[i]), i));
	}
}

void go(int x, int y, int d)
{
	board[x][y] = '*';
	gox(x, y);

	for (int i = 0; i < 4; ++i)
	{
		if (is_boreder(x + t[i], y + tt[i], d) && board[x + t[i]][y + tt[i]] == '.')
		{
			board[x + t[i]][y + tt[i]] = '*';
			gox(x + t[i], y + tt[i]);
		}
	}
}

void evaluate()
{
	while (!q.empty())
	{
		q.pop();
	}
	
	q.push(make_pair(make_pair(1, 1), 3));

	while (M > 0 && !q.empty())
	{
		pair<int, int> next = q.front().first;
		int direction = q.front().second;
		q.pop();
		if (board[next.first][next.second] != '.') continue;
		
		if (try_this(next.first, next.second, direction) <= M)
		{
			M -= try_this(next.first, next.second, direction);
			go(next.first, next.second, direction);

			/*
			for (int i = 0; i < 4; ++i)
			{
				q.push(make_pair(make_pair(next.first + t[i], next.second + tt[i]), i));
			}*/
		}

		for (int i = 1; i <= R; ++i)
		{
			printf("%s\n", board[i] + 1);
		}
		printf("\n");
	}
}

int count_dot()
{
	int ret = 0;
	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			if (board[i][j] == '.') ret++;
		}
	}
	return ret;
}

void up(int x, int y)
{
	for (int i = x - 1; i <= x + 1; ++i)
	{
		for (int j = y - 1; j <= y + 1; ++j)
		{
			boardx[i][j]++;
		}
	}
}

void make_grid()
{
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			boardx[i][j] = 9;
		}
	}
	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			boardx[i][j] = 0;
		}
	}
	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			if (board[i][j] == '*')
			{
				up(i, j);
			}
		}
	}

	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			if (board[i][j] == '*')
			{
				boardx[i][j] = 9;
			}
		}
	}
}

int ans(int x, int y)
{
	if (boardx[x][y] == 9 || board[x][y] != '.') return 0;
	int k = boardx[x][y];
	boardx[x][y] = 9;

	int ret = 1;
	if (k == 0)
	{
		for (int i = x - 1; i <= x + 1; ++i)
		{
			for (int j = y - 1; j <= y + 1; ++j)
			{
				ret += ans(i, j);
			}
		}
	}

	return ret;
}

int chx()
{
	int c_dot = count_dot();
	make_grid();

	int minx = 9, ix, jx;
	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			if (boardx[i][j] < minx)
			{
				minx = boardx[i][j];
				ix = i;
				jx = j;
			}
		}
	}
	
	int c_ans = ans(ix, jx);
	if (c_dot == c_ans) 
	{
		board[ix][jx] = 'c';
		for (int i = 1; i <= R; ++i)
		{
			printf("%s\n", board[i] + 1);
		}
		return 1;
	}
	return 0;
}

int endx;

void evaluatex(int n, int ml)
{
	if (endx) return;
	if (ml == 0)
	{
		if (chx()) endx = 1;
		return;
	}

	if (n == R * C)
	{
		if (ml == 0 && chx()) endx = 1;
		return;
	}

	evaluatex(n + 1, ml);
	board[n / C + 1][n % C + 1] = '*';
	evaluatex(n + 1, ml - 1);
	board[n / C + 1][n % C + 1] = '.';
}

void input()
{
	scanf("%d %d %d", &R, &C, &M);
	clear();
	endx = 0;
	evaluatex(0, M);

	if (!endx) printf("Impossible\n");
/*
	int c_dot = count_dot();
	make_grid();

	int minx = 9, ix, jx;
	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			if (boardx[i][j] < minx)
			{
				minx = boardx[i][j];
				ix = i;
				jx = j;
			}
		}
	}
	
	int c_ans = ans(ix, jx);
	printf("%d %d\n", c_dot, c_ans);
	if (c_dot != c_ans) printf("Impossible\n");
	//else
	{
		board[ix][jx] = 'c';
		for (int i = 1; i <= R; ++i)
		{
			printf("%s\n", board[i] + 1);
		}
	}*/
}

int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int T;
	scanf("%d", &T);

	for (int test = 1; test <= T; ++test)
	{
		printf("Case #%d:\n", test);
		input();
	}

	return 0;
}