#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

#define PRIMPOSSIBLE printf("Impossible\n");
int R, C, M;

bool transpose;
int r, c;
char grid[50][50];

void printGrid()
{
	if (transpose) {
		for (int i = 0; i < c; i++) {
			for (int j = 0; j < r; j++) {
				printf("%c", grid[j][i]);
			}
			printf("\n");
		}
	} else {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				printf("%c", grid[i][j]);
			}
			printf("\n");
		}
	}
}

void fillAllMine()
{
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			grid[i][j] = '*';
		}
	}
	grid[r-1][c-1] = 'c';
}

void fillOneLine()
{
	int i = 0;
	while (i < M) {
		grid[0][i] = '*';
		i++;
	}
	while (i < c - 1) {
		grid[0][i] = '.';
		i++;
	}
	grid[0][c-1] = 'c';
}

void fillTwoLine()
{
	int i = 0;
	while (i < M / 2) {
		grid[0][i] = '*';
		grid[1][i] = '*';
		i++;
	}
	while (i < c) {
		grid[0][i] = '.';
		grid[1][i] = '.';
		i++;
	}
	grid[1][c-1] = 'c';
}

void fillSparse()
{
	// r >= 3
	int mc = M / r;
	int mr = M % r;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < mc; j++) {
			grid[i][j] = '*';
		}
	}
	for (int i = 0; i < mr; i++) {
		grid[i][mc] = '*';
	}
	for (int i = mr; i < r; i++) {
		grid[i][mc] = '.';
	}
	for (int i = 0; i < r; i++) {
		for (int j = mc + 1; j < c; j++) {
			grid[i][j] = '.';
		}
	}
	grid[r-1][c-1] = 'c';

	if (mr == r - 1) {
		// swap
		grid[mr-1][mc] = '.';
		grid[0][mc+1] = '*';
	}
}

void setLastThreeLines()
{
	// 3 <= r <= c
	int E = r * c - M;
	// E = 6, 8, 10, 11, 12, ...
	int er = E / 3;
	int ec = E % 3;
	for (int i = r - er; i < r; i++) {
		for (int j = c - 3; j < c; j++) {
			grid[i][j] = '.';
		}
	}
	if (ec == 1) {
		// E > 10. E != 8. E != 6.
		// er >= 3
		grid[r - er][c - 3] = '*';
		grid[r - er - 1][c - 2] = '.';
		grid[r - er - 1][c - 1] = '.';
	} else if (ec == 2) {
		// E can be 8 or more
		grid[r - er - 1][c - 2] = '.';
		grid[r - er - 1][c - 1] = '.';
	}
	grid[r-1][c-1] = 'c';
}

void set4Points()
{
	grid[r-2][c-2] = '.';
	grid[r-2][c-1] = '.';
	grid[r-1][c-2] = '.';
	grid[r-1][c-1] = 'c';
}

void solve()
{
	int E = R * C - M;
	if (R > C) {
		r = C;
		c = R;
		transpose = true;
	} else {
		r = R;
		c = C;
		transpose = false;
	}
	// now r <= c

	if (E == 1) {
		fillAllMine();
		printGrid();
		return;
	}

	if (r == 1) {
		fillOneLine();
		printGrid();
		return;
	}

	if (E == 2 || E == 3 || E == 5 || E == 7) {
		PRIMPOSSIBLE;
		return;
	}

	if (r == 2) {
		if (M & 1) {
			PRIMPOSSIBLE;
			return;
		}
		fillTwoLine();
		printGrid();
		return;
	}

	// now 3 <= r <= c
	if (E >= 3 * r) {
		fillSparse();
		printGrid();
		return;
	}

	// now E < 3 * r
	fillAllMine();

	if (E > 4) {
		// E == 6, 8, 9, 10, 11, 12, ...
		setLastThreeLines();
	} else {
		// E == 4
		set4Points();
	}

	printGrid();
}

int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		printf("Case #%d:\n", i);
		scanf("%d %d %d", &R, &C, &M);

		solve();
	}
	return 0;
}
