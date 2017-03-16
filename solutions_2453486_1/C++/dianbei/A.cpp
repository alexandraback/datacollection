#include <stdio.h>
#include <string.h>

char a[10][10];

bool won(char x) {
	int i, j;

	for (i = 0; i < 4; i++) {
		int cntX = 0, cntT = 0;
		for (j = 0; j < 4; j++) {
			if (a[i][j] == x) cntX ++;
			if (a[i][j] == 'T') cntT ++;
		}
		if (cntX == 4 || (cntX == 3 && cntT == 1)) {
			return true;
		}
	}
	for (i = 0; i < 4; i++) {
		int cntX = 0, cntT = 0;
		for (j = 0; j < 4; j++) {
			if (a[j][i] == x) cntX ++;
			if (a[j][i] == 'T') cntT ++;
		}
		if (cntX == 4 || (cntX == 3 && cntT == 1)) {
			return true;
		}
	}

	{
		int cntX = 0, cntT = 0;
		for (j = 0; j < 4; j++) {
			if (a[j][j] == x) cntX ++;
			if (a[j][j] == 'T') cntT ++;
		}
		if (cntX == 4 || (cntX == 3 && cntT == 1)) {
			return true;
		}
	}

	{
		int cntX = 0, cntT = 0;
		for (j = 0; j < 4; j++) {
			if (a[j][3 - j] == x) cntX ++;
			if (a[j][3 - j] == 'T') cntT ++;
		}
		if (cntX == 4 || (cntX == 3 && cntT == 1)) {
			return true;
		}
	}

	return false;
}

int main() {
	int re, ri = 1;

	freopen("D:\\Work\\GCJ2013\\A-small-attempt0.in", "r", stdin);
	freopen("D:\\Work\\GCJ2013\\A-small-attempt0.out", "w", stdout);

	scanf("%d", &re);
	while(re--) {
		for(int i = 0; i < 4; i++) {
			scanf("%s", a[i]);
		}

		printf("Case #%d: ", ri++);
		if (won('X')) {
			printf("X won\n");
		} else if(won('O')) {
			printf("O won\n");
		} else {
			bool isDraw = true;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (a[i][j] == '.') {
						isDraw = false;
					}
				}
			}

			if (isDraw) {
				printf("Draw\n");
			} else {
				printf("Game has not completed\n");
			}
		}
	}

	return 0;
}
