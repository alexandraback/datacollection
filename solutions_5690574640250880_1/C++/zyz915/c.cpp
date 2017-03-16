#include <cstdio>
#include <cstring>

char ret[51][51];

int main(int argc, char **argv) {
	int cas, T;
	scanf("%d", &T);
	for (cas = 1; cas <= T; cas++) {
		int rows, cols, m, t, swap = 0, imp = 0;
		int i, j;
		scanf("%d%d%d", &rows, &cols, &m);
		if (rows > cols) {
			t = rows;
			rows = cols;
			cols = t;
			swap = 1;
		}
		m = rows * cols - m;
		printf("Case #%d:\n", cas);
		memset(ret, 0, sizeof(ret));
		if (rows == 1) {
			for (i = 0; i < m; i++)
				ret[0][i] = '.';
			for (i = m; i < cols; i++)
				ret[0][i] = '*';
		}
		if (rows == 2) {
			if (m == 2 || (m > 2 && m % 2 != 0))
				imp = 1;
			else {
				if (m == 1) {
					for (i = 0; i < rows; i++)
						for (j = 0; j < cols; j++)
							ret[i][j] = '*';
				} else {
					for (i = 0; i < rows; i++) {
						for (j = 0; j + j < m; j++)
							ret[i][j] = '.';
						for (j = m / 2; j < cols; j++)
							ret[i][j] = '*';
					}
				}
			}
		}
		if (rows > 2) {
			int a, b, c, d, flag = 0;
			if (m == 1) {
				flag = 1;
				for (i = 0; i < rows; i++)
					for (int j = 0; j < cols; j++)
						ret[i][j] = '*';
			}
			for (a = m / rows; !flag && a >= 0 && a >= m / rows - rows; a--) {
				if (a == 1) continue;
				t = m - a * rows;
				if (a != 0 && (t == 0 || (t > 1 && t <= rows))) {
					flag = 1;
					for (i = 0; i < rows; i++) {
						for (j = 0; j < a; j++)
							ret[i][j] = '.';
						ret[i][a] = (i < t ? '.' : '*');
						for (j = a + 1; j < cols; j++)
							ret[i][j] = '*';
					}
				}
				for (b = rows - 1; !flag && b > 1; b--) {
					c = t % b;
					d = t / b;
					if (a + d > 1 && (c != 1 && a + d + (c > 0) <= cols)) {
						flag = 1;
						for (i = 0; i < rows; i++) {
							for (j = 0; j < a; j++)
								ret[i][j] = '.';
							for (j = a; j < a + d; j++)
								ret[i][j] = (i < b ? '.' : '*');
							ret[i][a + d] = (i < c ? '.' : '*');
							for (j = a + d + 1; j < cols; j++)
								ret[i][j] = '*';
						}
					}
				}
			}
			if (!flag) imp = 1;
		}
		if (imp)
			printf("Impossible\n");
		else {
			ret[0][0] = 'c';
			if (!swap) {
				for (i = 0; i < rows; i++) {
					for (j = 0; j < cols; j++)
						printf("%c", ret[i][j]);
					printf("\n");
				}
			} else {
				for (i = 0; i < cols; i++) {
					for (j = 0; j < rows; j++)
						printf("%c", ret[j][i]);
					printf("\n");
				}
			}
		}
	}
	return 0;
}

