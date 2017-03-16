#include <cstdio>
#include <cstdlib>

char board[50][50];
bool possible;
int T, R, C, M, trans, n;

void setbd(int h, int w, char c = '.') {
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			board[i][j] = c;
}

/*int t[50][50];
bool revealed[50][50];

void reveal(int x, int y) {
	if (revealed[x][y]) return;
	revealed[x][y] = true;
	if (t[x][y]) return;
	for (int l = -1; l <= 1; ++l)
		for (int k = -1; k <= 1; ++k) {
			if (l == 0 && k == 0) continue;
			int xx = x + l;
			int yy = y + k;
			if (xx < 0 || xx >= R || yy < 0 || yy >= C) continue;
			if (t[xx][yy] < 0) continue;
			reveal(xx, yy);
		}
}

bool check() {
	int bb = 0;
	if (board[0][0] != 'c') return false;
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j) {
			if (board[i][j] == '*') {
				t[i][j] = -1;
				++bb;
			}
			else t[i][j] = 0;
		}
	if (bb != M) return false;
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j) {
			if (t[i][j] < 0) continue;
			for (int l = -1; l <= 1; ++l)
				for (int k = -1; k <= 1; ++k) {
					if (l == 0 && k == 0) continue;
					int ii = i + l;
					int jj = j + k;
					if (ii < 0 || ii >= R || jj < 0 || jj >= C) continue;
					if (t[ii][jj] < 0) t[i][j]++;
				}
		}
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j) revealed[i][j] = false;
	reveal(0, 0);
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			if ((!revealed[i][j] && t[i][j] >= 0) || (revealed[i][j] && t[i][j] < 0))
				return false;
	return true;
}*/

int main() {
	FILE *fp = fopen("C-small-attempt2.in", "r");
	FILE *fout = fopen("out.txt", "w");
	fscanf(fp, "%d", &T);
	for (int i = 0; i < T; ++i) {
		fscanf(fp, "%d%d%d", &R, &C, &M);
		if (R >= C) trans = 0;
		else {
			int tmp = R;
			R = C;
			C = tmp;
			trans = 1;
		}
		n = R * C - M;
		possible = true;
		setbd(R, C, '*');
///////////////////////////////////////////////////////////
		if (n == 1) board[0][0] = 'c';
		// C = 1,2
		else if (C == 1) {
			setbd(n, 1);
			board[0][0] = 'c';
		}
		else if (C == 2) {
			if (n % 2 == 0 && n >= 4) {
				setbd(n / 2, 2);
				board[0][0] = 'c';
			}
			else possible = false;
		}
		// C >= 3 and n = 2,3,4,5,6,7,9
		else if (n == 2 || n == 3 || n == 5 || n == 7)
				possible = false;
		else if (n == 4 || n == 6 || n == 9) {
			if (n == 4) setbd(2, 2);
			else if (n == 6) setbd(2, 3);
			else if (n == 9) setbd(3, 3);
			board[0][0] = 'c';
		}
		// C >= 3 and n >= 4C
		else if (n >= 4 * C) {
			setbd(n / C, C);
			for (int i = 0; i < n % C; ++i)
				board[n / C][i] = '.';
			if (n % C == 1) {
				board[n / C][1] = '.';
				board[0][C - 1] = '*';
			}
			board[0][0] = 'c';
		}
		// C >= 3 and n < 4C
		else if (n % 4 == 0) {
			if (C == 3) {
				// n == 8, C == 3
				setbd(3, 3);
				board[2][2] = '*';
				board[0][0] = 'c';
			}
			else {
				// n >= 8, C >= 4
				setbd(4, n / 4);
				board[0][0] = 'c';
			}
		}
		else if (n % 4 == 1) {
			// n >= 13, C >= 4
			setbd(4, n / 4 + 1);
			board[2][n / 4] = '*';
			board[3][n / 4 - 1] = '*';
			board[3][n / 4] = '*';
			board[0][0] = 'c';
		}
		else if (n % 4 == 2) {
			// n >= 10
			setbd(4, n / 4 + 1);
			board[2][n / 4] = '*';
			board[3][n / 4] = '*';
			board[0][0] = 'c';
		}
		else {
			// n >= 11
			setbd(4, n / 4 + 1);
			board[3][n / 4] = '*';
			board[0][0] = 'c';
		}
///////////////////////////////////////////////////////////
		fprintf(fout, "Case #%d:\n", i + 1);
		if (!possible) {
			fprintf(fout, "Impossible\n");
			//printf("%d %d %d\n", R, C, n);
		}
		else {
			if (trans == 0) {
			for (int j = 0; j < R; ++j) {
				for (int k = 0; k < C; ++k)
					fprintf(fout, "%c", board[j][k]);
				fprintf(fout, "\n");
				}
			}
			else {
				for (int k = 0; k < C; ++k) {
					for (int j = 0; j < R; ++j)
						fprintf(fout, "%c", board[j][k]);
					fprintf(fout, "\n");
				}
			}
			//if (!check()) printf("%d %d %d %d\n", i+1, R, C, n);
		}
	}
	fclose(fp);
	fclose(fout);
	return 0;
}