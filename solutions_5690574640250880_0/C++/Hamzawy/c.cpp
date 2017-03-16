/*
 * c.cpp
 *
 *  Created on: Apr 12, 2014
 *      Author: AhmedHamza
 */

#include<cstdio>
#include<vector>
#include<string.h>

using namespace std;

int tc, r, c, m, n, rem;
char board[12][12];
bool vis[12][12];
int di[] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int dj[] = { 1, 0, -1, 0, -1, 1, -1, 1 };

void print()
{
	for (int i = 0; i < r; ++i)
	{
		board[i][c] = 0;
		printf("%s\n", board[i]);
	}
}

void inflate(int mask, int i, int j)
{
	memset(board, '.', sizeof board);
	board[i][j] = 'c';
	for (i = 0; i < n; ++i)
		if ((mask >> i) & 1)
			board[i / c][i % c] = '*';
}

bool valid(int i, int j)
{
	return i >= 0 && j >= 0 && i < r && j < c;
}

int test(int i, int j)
{
	vis[i][j] = 1;
	int c = 0;
	for (int d = 0; d < 8; ++d)
	{
		int ni = i + di[d], nj = j + dj[d];
		c += (valid(ni, nj) && board[ni][nj] == '*');
	}
	int res = 1;
	if (c == 0)
	{
		for (int d = 0; d < 8; ++d)
		{
			int ni = i + di[d], nj = j + dj[d];
			if (valid(ni, nj) && !vis[ni][nj])
				res += test(ni, nj);
		}
	}
	return res;
}

int main()
{
		freopen("C-small-attempt3.in", "rt", stdin);
		freopen("C-small-attempt3.txt", "wt", stdout);
//	freopen("c.in", "rt", stdin);
	scanf("%d", &tc);
	for (int t = 1; t <= tc; ++t)
	{
		scanf("%d%d%d", &r, &c, &m);
		printf("Case #%d:\n", t);
		n = r * c, rem = n - m;
		for (int mask = 0; mask < (1 << n); ++mask)
		{
			if (__builtin_popcount(mask) != m)
				continue;
			for (int i = 0; i < n; ++i)
			{
				if ((mask >> i) & 1)
					continue;
				memset(vis, 0, sizeof vis);
				inflate(mask, i / c, i % c);
				if (test(i / c, i % c) != rem)
					continue;
				print();
				goto end;
			}
		}
		printf("Impossible\n");
		end: ;
	}
	return 0;
}
