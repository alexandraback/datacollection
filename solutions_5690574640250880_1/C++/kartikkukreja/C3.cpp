#include <cstdio>
using namespace std;

char grid[52][52];

bool possible (int R, int C, int M) {
	if (M == 0) {
		grid[0][0] = 'c'; return true;
	}
	if (R == 1 && C == 1) return false;
	if (R == 2 && C == 2) {
		if (M != 3) return false;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				grid[i][j] = '*';
		grid[0][0] = 'c';
		return true;
	}
	
	int min = (R <= C) ? R : C;
	if (M >= min) {
		if (min == R) {
			for (int i = 0; i < R; i++)
				grid[i][C-1] = '*';
			return possible (R, C-1, M-R);
		} else {
			for (int i = 0; i < C; i++)
				grid[R-1][i] = '*';
			return possible (R-1, C, M-C);		
		}
	} else if (M == min-1) {
		if ((R-2)*(C-2) < M) return false;
		for (int j = C-1, cnt = 0; cnt < M; j--)
			for (int i = R-1; i >= 2 && cnt < M; i--, cnt++)
				grid[i][j] = '*';
		grid[0][0] = 'c';
		return true;
	} else {
		for (int i = R-1, cnt = 0; i >= 0; i--, cnt++)
			grid[i][C-1] = (cnt < M) ? '*' : '.';
		grid[0][0] = 'c';
		return true;
	}
}

int main() {
	int T, i, j, t, R, C, M;
	
	freopen("C-large.in", "r", stdin);
	freopen("C-large.txt", "w", stdout);
	
	scanf("%d", &T);
	for (t = 1; t <= T; t++) {
		scanf("%d %d %d", &R, &C, &M);
		for (i = 0; i < R; i++)
			for (j = 0; j < C; j++)
				grid[i][j] = '.';
		
		if (!possible (R, C, M))
			printf("Case #%d:\nImpossible\n", t);
		else {
			printf("Case #%d:\n", t);
			for (i = 0; i < R; i++) {
				grid[i][C] = '\0';
				printf("%s\n", grid[i]);
			}
		}
	}
	
	return 0;
}
