#include <stdio.h>
#include <limits.h>
#include <string.h>

#define DEBUG 0

typedef struct
{
	int w;
	int h;
	int *board;
} board_t;

int get(board_t board, int r, int c)
{
	if (r < 0 || r >= board.h)
		return 0;
	else if (c < 0 || c >= board.w)
		return 0;
	else
		return board.board[r * board.w + c];
}

int getCheckBoard(board_t board, int r, int c, int lr)
{
	if (r < 0 || r >= board.h)
		return 1;
	else if (c < 0 || c >= board.w)
		return 1;
	else if (lr)
		return board.board[r * board.w + c] > 2;
	else
		return board.board[r * board.w + c] == 1 || board.board[r * board.w + c] == 4;
}

char *solveIt(board_t board)
{
	int r, c, i, x, flag, bad;
	for (r=0;r<board.h;++r)
	{
		for (c=0;c<board.w;++c)
		{
			x = get(board, r, c);
			flag = 1;
			bad = 0;
			for (i=0;i<board.h && flag;++i)
			{
				if (x >= get(board, i, c)) {}
				else
					flag = 0;
			}

			if (!flag)
				bad = 1;

			flag = 1;
			for (i=0;i<board.w && flag;++i)
			{
				if (x >= get(board, r, i)) {}
				else
					flag = 0;
			}
			if (!flag && bad)
				return "NO";
		}
	}
	return "YES";
}

int main(int argc, char **argv)
{
	int trials;
	scanf("%d", &trials);
	board_t board;
	int i, j;
	for (i=1;i<=trials;++i)
	{
		scanf("%d", &board.h);
		scanf("%d", &board.w);

		int b[board.h * board.w];
		for (j=0;j<board.h * board.w;++j)
			scanf("%d", &b[j]);
		board.board = b;
		printf("Case #%d: %s\n", i, solveIt(board));
		if (DEBUG)
		{
			int r, c;
			for (r=0;r<board.h;++r)
			{
				for (c=0;c<board.w;++c)
					printf("%d ", get(board, r, c));
				puts("");
			}
			puts("-----------------------");
		}
	}

	return 0;
}
