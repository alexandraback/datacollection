#include <stdio.h>
#include <string.h>

int map[50][50];
int row, column;
int space;

int foo(int r, int width, int space)
{
	int j;
	if (r > 0) {
		int cost = width;
		if (cost < column) {
			cost++;
		}
		if (cost == space) {
			for (j = 0; j < cost; j++) {
				map[r][j] = 1;
			}
			return 1;
		}
	}

	if (r == row - 1) {
		int i;
		for (i = 1; i <= width; i++) {
			int cost = width;
			if (r == 0) {
				cost = i;
			}
			if (cost < column) {
				cost++;
			}
			if (cost == space) {
				for (j = 0; j < cost; j++) {
					map[r][j] = 1;
				}
				return 1;
			}
		}
	}
	else {
		int i;
		for (i = 1; i <= width; i++) {
			int cost = width;
			if (r == 0) {
				cost = i;
			}
			if (cost < column) {
				cost++;
			}
			if (foo(r + 1, i, space - cost)) {
				for (j = 0; j < cost; j++) {
					map[r][j] = 1;
				}
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int k, t;
	scanf("%d", &t);
	for (k = 0; k < t; k++) {
		int mine;
		scanf("%d%d%d", &row, &column, &mine);
		printf("Case #%d:\n", k + 1);
		space = row * column - mine;
		if (space <= 0) {
			printf("Impossible\n");
			continue;
		}
		else if (space == 1) {
			int i, j;
			for (i = 0; i < row; i++) {
				for (j = 0; j < column; j++) {
					if (i == 0 && j == 0) {
						printf("c");
					}
					else {
						printf("*");
					}
				}
				printf("\n");
			}
			continue;
		}
		memset(map, 0, sizeof (map));
		if (foo(0, column, space) == 0) {
			printf("Impossible\n");
		}
		else {
			int i, j;
			for (i = 0; i < row; i++) {
				for (j = 0; j < column; j++) {
					if (i == 0 && j == 0) {
						printf("c");
					}
					else if (map[i][j] == 0) {
						printf("*");
					}
					else if (map[i][j] == 1) {
						printf(".");
					}
				}
				printf("\n");
			}
		}
	}
	return 0;
}