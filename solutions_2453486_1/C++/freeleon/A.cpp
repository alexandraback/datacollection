//Problem A. Tic-Tac-Toe-Tomek
#include <cstdio>
#include <cstring>
#include <cassert>

char mat[4][5];

bool win(char ch) {
	int dc1 = 0, dt1 = 0, dc2 = 0, dt2 = 0;
	for (int i = 0; i < 4; ++i) {
		int tr = 0, nr = 0, tc = 0, nc = 0;
		for (int j = 0; j < 4; ++j) {
			if (mat[i][j] == ch) nr++;
			else if (mat[i][j] == 'T') tr++;
			if (mat[j][i] == ch) nc++;
			else if (mat[j][i] == 'T') tc++;
		}
		if (nr == 4 || nc == 4 || (nr == 3 && tr == 1) || (nc == 3 && tc == 1)) {
	//		printf("%d-%d, %d-%d\n", nr, tr, nc, tc);
			return 1;
		}
		if (mat[i][i] == ch) dc1++;
		else if (mat[i][i] == 'T') dt1++;
		if (mat[i][3-i] == ch) dc2++;
		else if (mat[i][3-i] == 'T') dt2++;
	}
	return (dc1 == 4) || (dc1 == 3 && dt1 == 1) || (dc2 == 4) || (dc2 == 3 && dt2 == 1);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int run = 1; run  <= T; run++) {
		int em = 0;
		for (int i = 0; i < 4; ++i) {
			scanf("%s", mat[i]);
			assert(strlen(mat[i]) == 4);
			for (int j = 0; j < 4; ++j) if (mat[i][j] == '.') em++;
		}
		bool x = win('X'), o = win('O');
		printf("Case #%d: ", run);
		if (x) puts("X won");
		else if (o) puts("O won");
		else if (em == 0) puts("Draw");
		else puts("Game has not completed");
	}
	return 0;
}
