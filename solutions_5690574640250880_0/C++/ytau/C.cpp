#include <cstdio>

int T, m, n, k;

void doit() {
	if (m == 1) {
		for (int i = 0; i <n; ++i) {
			if (i == 0) printf("c");
			else if (i < k) printf(".");
			else printf("*");
		}
		printf("\n");
		return;
	}
	if (n == 1) {
		for (int i = 0; i < m; ++i) {
			if (i == 0) printf("c\n");
			else if (i < k) printf(".\n");
			else printf("*\n");
		}
		return;
	}
	if (k == 2 || k == 3 || k == 5 || k == 7) {
		printf("Impossible\n");
		return;
	}
	if (k == 1) {
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if ((i|j) == 0) printf("c");
				else printf("*");
			}
			printf("\n");
		}
		return;
	}
	if (k == 4) {
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if ((i|j) == 0) printf("c");
				else if (i < 2 && j < 2) printf(".");
				else printf("*");
			}
			printf("\n");
		}
		return;
	}
	if (m == 2) {
		if (k&1) printf("Impossible\n");
		else {
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) {
					if ((i|j) == 0) printf("c");
					else if (j + j < k) printf(".");
					else printf("*");
				}
				printf("\n");
			}
		}
		return;
	}
	if (n == 2) {
		if (k&1) printf("Impossible\n");
		else {
			for (int i = 0; i < m; ++i) {
				for (int j = 0; j < n; ++j) {
					if ((i|j) == 0) printf("c");
					else if (i + i < k) printf(".");
					else printf("*");
				}
				printf("\n");
			}
		}
		return;
	}
	if (k == 6) {
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if ((i|j) == 0) printf("c");
				else if (i < 2 && j < 3) printf(".");
				else printf("*");
			}
			printf("\n");
		}
		return;
	}
	char c[55][55];
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			c[i][j] = '*';
		}
	}
	c[0][0] = 'c';
	c[0][1] = c[0][2] = c[1][0] = c[1][1] = c[1][2] = c[2][0] = c[2][1] = '.';
	k -= 8;
	for (int i = 3; i < m && k >= 2; ++i) {
		c[i][0] = c[i][1] = '.';
		k -= 2;
	}
	for (int i = 3; i < n && k >= 2; ++i) {
		c[0][i] = c[1][i] = '.';
		k -= 2;
	}
	for (int i = 2; i < m && k >= 1; ++i) {
		for (int j = 2; j < n && k >= 1; ++j) {
			c[i][j] = '.';
			--k;
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%c", c[i][j]);
		}
		printf("\n");
	}
}

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d%d%d", &m, &n, &k);
		k = m * n - k;
		printf("Case #%d:\n", tc);
		doit();
	}
	return 0;
}