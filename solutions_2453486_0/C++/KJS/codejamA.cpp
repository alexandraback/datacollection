#include <stdio.h>

#define D 0
#define O 1
#define X 2
#define U 3

const int B = 4;

int main()
{	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out_A.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	getchar();
	char board[B +1][B +1];
	int row[B], col[B], lcross, rcross;
	for (int t = 1; t <= T; ++t) {
		for (int i = 0; i < B; ++i)
			scanf("%s", &board[i]);

		int status = U;

		for (int i = 0; i < B; ++i)
			row[i] = col[i] = 0;
		lcross = rcross = 0;

		for (int i = 0; i < B; ++i) {
			for (int j = 0; j < B; ++j) {

				if (board[i][j] == 'O' || board[i][j] == 'T')	++row[i];

				if (board[j][i] == 'O' || board[j][i] == 'T')	++col[i];
			}

			if (board[i][i] == 'O' || board[i][i] == 'T')
				++lcross;
			if (board[i][B - i -1] == 'O' ||  board[i][B - i -1] == 'T')
				++rcross;
		}

		for (int i = 0; i < B; ++i)
			if (row[i] == 4 || col[i] == 4 || lcross == 4 || rcross == 4)
				status = O;

		for (int i = 0; i < B; ++i)
			row[i] = col[i] = 0;
		lcross = rcross = 0;

		for (int i = 0; i < B; ++i) {
			for (int j = 0; j < B; ++j) {
				if (board[i][j] == 'X' || board[i][j] == 'T')
					++row[i];

				if (board[j][i] == 'X' || board[j][i] == 'T')	++col[i];
			}

			if (board[i][i] == 'X' || board[i][i] == 'T')
				++lcross;
			if (board[i][B - i -1] == 'X' ||  board[i][B - i -1] == 'T')
				++rcross;
		}

		for (int i = 0; i < B; ++i)
			if (row[i] == 4 || col[i] == 4 || lcross == 4 || rcross == 4)
				status = X;

		if (status == U) {
			status = D;
			for (int i = 0; i < B; ++i)
				for (int j = 0; j < B; ++j)
					if (board[i][j] == '.')
						status = U;
		}


		printf("Case #%d: ", t);
		switch (status) {
			case D:	puts("Draw");	break;
			case O: puts("O won");	break;
			case X: puts("X won");	break;
			case U: puts("Game has not completed");	break;
			defualt:puts("Game has not completed");	break;
		}
	}
	return 0;
}
