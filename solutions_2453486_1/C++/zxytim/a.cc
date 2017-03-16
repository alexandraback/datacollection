/*
 * $File: a.cc
 * $Date: Sat Apr 13 11:36:53 2013 +0800
 * $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>
 */

#include <cstdio>

const int NO_RESULT = 0;
int result(char board[4][5], int x, int y, int dir)
{
	const int DIRS[8][2] = {
		{0, 1}, {1, 0}, {0, -1}, {-1, 0},
		{1, 1}, {1, -1}, {-1, -1}, {-1, 1}
	};
	int dx = DIRS[dir][0],
		dy = DIRS[dir][1];
	if (!(x == 0 || x == 3 || y == 0 || y == 3))
		throw "invalid position";

	int c0 = board[x][y];
	if (c0 == 'T' || c0 == '.')
		return NO_RESULT;
	for (int i = 1; i < 4; i ++)
	{
		int tx = x + dx * i,
			ty = y + dy * i;
		if (!(tx >= 0 && tx < 4 && ty >= 0 && ty < 4))
			return NO_RESULT;
		int c1 = board[tx][ty];
		if (c0 == c1 || c1 == 'T')
			continue;
		return NO_RESULT;
	}
	return c0;
}

void solve(int case_id)
{
	printf("Case #%d: ", case_id);
	char board[4][5];
	for (int i = 0; i < 4; i ++)
		scanf("%s", board[i]);
	for (int i = 0; i < 4; i ++)
		for (int j = 0; j < 4; j ++)
			if (i == 0 || j == 0 || i == 3 || j == 3)
			{
				for (int k = 0; k < 8; k ++)
				{
					int rst = result(board, i, j, k);
					if (rst)
					{
						printf("%c won\n", rst);
						return;
					}
				}
			}
	for (int i = 0; i < 4; i ++)
		for (int j = 0; j < 4; j ++)
			if (board[i][j] == '.')
			{
				printf("Game has not completed\n");
				return;
			}
	printf("Draw\n");
}

int main()
{
	int ncase;
	scanf("%d", &ncase);
	for (int i = 1; i <= ncase; i ++)
		solve(i);
	return 0;
}


/**
 * vim: syntax=cpp11 foldmethod=marker
 */

