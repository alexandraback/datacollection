#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

char out[60][60];

int main() {
	int ttt;
	scanf("%d", &ttt);
	for (int test = 1; test <= ttt; ++test) {
		int R, C, M;
		scanf("%d%d%d", &R, &C, &M);
		int r, c, m;
		r = R, c = C;
		m = R * C - M;
		if (r < c) swap(r, c);
		bool flag;
		if (c == 1) {
			flag = true;
			for (int i = 0; i < r; ++i) {
				out[i][0] = '*';
				if (i >= M) out[i][0] = '.';
				if (i == r - 1) out[i][0] = 'c';
			}
		}
		else if (c == 2) {
			if (m == 1) {
				flag = true;
				for (int i = 0; i < r; ++i) {
					for (int j = 0; j < c; ++j) {
						out[i][j] = '*';
					}
				}
				out[r - 1][c - 1] = 'c';
			}
			else if (m % 2 == 1 || m == 2) {
				flag = false;
			}
			else {
				flag = true;
				for (int i = 0; i < r; ++i) {
					out[i][0] = out[i][1] = '*';
					if (i >= M / 2) out[i][0] = out[i][1] = '.';
				}
				out[r - 1][c - 1] = 'c';
			}
		}
		else {
			int lines = M / c;
			int add = M % c;
			int leftlines = r - lines;
			for (int i = 0; i < r; ++i)
				for (int j = 0; j < c; ++j)
					out[i][j] = '.';
			out[r - 1][c - 1] = 'c';
			for (int i = 0; i < lines; ++i) {
				for (int j = 0; j < c; ++j) {
					out[i][j] = '*';
				}
			}
			for (int j = 0; j < add; ++j) {
				out[lines][j] = '*';
			}
			if (leftlines >= 4) {
				if (add == c - 1) {
					out[lines][add - 1] = '.';
					out[lines + 1][0] = '*';
				}
				flag = true;
			}
			else if (leftlines == 3) {
				if (add == c - 1) {
					out[lines][add - 1] = out[lines][add - 2] = '.';
					out[lines + 1][0] = out[lines + 2][0] = '*';
					if (c == 3) flag = false;
					else flag = true;
				}
				else flag = true;
			}
			else if (M == R * C - 1) {
				flag = true;
			}
			else if (leftlines <= 2) {
				if (leftlines == 1) {
					--lines;
					add += c;
				}
				int last = add / 2;
				int last2 = c;
				if (add % 2) {
					last += 2;
					last2 -= 3;
				}
				if (last2 < last) flag = false;
				else {
					for (int i = lines - 1; i < r; ++i)
						for (int j = 0; j < c; ++j)
							out[i][j] = '.';
					out[r - 1][c - 1] = 'c';
					for (int j = 0; j < last2; ++j)
						out[lines - 1][j] = '*';
					for (int j = 0; j < last; ++j)
						out[lines][j] = out[lines + 1][j] = '*';
					if (last <= c - 2) flag = true;
					else flag = false;
				}
			}
		}
		printf("Case #%d:\n", test);
		if (!flag) {
			printf("Impossible\n");
		} else {
			for (int i = 0; i < R; ++i) {
				for (int j = 0; j < C; ++j) {
					if (R == r) printf("%c", out[i][j]);
					else printf("%c", out[j][i]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}