#include <stdio.h>

char board[10][10];

int
check(char ch) {
	int i, j;

	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j)
			if (board[i][j] != 'T' && board[i][j] != ch)
				break;
		if (j == 4)
			return 1;
	}
	for (j = 0; j < 4; ++j) {
		for (i = 0; i < 4; ++i)
			if (board[i][j] != 'T' && board[i][j] != ch)
				break;
		if (i == 4)
			return 1;
	}
	for (i = 0; i < 4; ++i)
		if (board[i][i] != 'T' && board[i][i] != ch)
			break;
	if (i == 4)
		return 1;
	for (i = 0; i < 4; ++i)
		if (board[i][3 - i] != 'T' && board[i][3 - i] != ch)
			break;
	if (i == 4)
		return 1;
	return 0;
}

int
filled() {
	int i, j;

	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			if (board[i][j] == '.')
				return 0;
	return 1;
}

int
main()
{
	int ti, tn, i;
	FILE *inp, *oup;

	if ((inp = fopen("A-small-attempt0.in", "r")) == NULL) {
		fprintf(stderr, "Failed to open the input file\n");
		return -1;
	}
	if ((oup = fopen("A.out", "w")) == NULL) {
		fprintf(stderr, "Failed to open the output file\n");
		return -1;
	}
	fscanf(inp, "%d\n", &tn);
	for (ti = 1; ti <= tn; ++ti) {
		for (i = 0; i < 4; ++i)
			fgets(board[i], 256, inp);
		fprintf(oup, "Case #%d: ", ti);
		if (check('X'))
			fprintf(oup, "X won\n");
		else if (check('O'))
			fprintf(oup, "O won\n");
		else if (filled())
			fprintf(oup, "Draw\n");
		else
			fprintf(oup, "Game has not completed\n");
		fgets(board[0], 256, inp);
	}
	fclose(inp);
	fflush(oup);
	fclose(oup);
	return 0;
}
