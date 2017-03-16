#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 55;
char c[MAX_N][MAX_N];
int n, m, k;

int main() {
	int n_case = 0;
	scanf("%d", &n_case);
	for (int ca = 1; ca <= n_case; ca++) {
		scanf("%d%d%d", &n, &m, &k);
		printf("Case #%d:\n", ca);
		bool f = n > m;
		if (f) {
			swap(n, m);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				c[i][j] = '*';
			}
		}
		if (n * m == k) {
			printf("Impossible\n");
			continue;
		}
		if (n * m - k == 1) {
			c[0][0] = 'c';	
		} else if (n == 1) {
			c[0][0] = 'c';
			for (int i = 1; i < m - k; i++) {
				c[0][i] = '.';
			}
		} else if (n == 2) {
			if ((k & 1) || (n * m - k) == 2) {
				printf("Impossible\n");
				continue;
			} else {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m - k / 2; j++) {
						if (i == 0 && j == 0) c[i][j] = 'c';
						else if (j < m - k / 2) c[i][j] = '.';
					}
				}
			}
		} else {
			int tmp = n * m - k;
			if (tmp == 2 || tmp == 3 || tmp == 5 || tmp == 7) {
				printf("Impossible\n");
				continue;
			} else {
				if (tmp & 1) {
					int y = 3;
					tmp -= 3;
					int val = 2;
					c[0][0] = 'c', c[1][0] = '.';
					for (int j = 1; j < m; j++) {
						c[0][j] = '.';
						c[1][j] = '.';
						val += 2;
						if (val == tmp) {
							break;
						}
					}
					if (val == tmp) {
						c[2][0] = c[2][1] = c[2][2] = '.';
					} else {
						tmp++, y--;
						for (int i = 2; i < n; i++) {
							for (int j = 0; j < m; j++) {
								c[i][j] = '.';
								val++;
								if (val == tmp) {
									if (j < m - 2) {
										c[i][j + 1] = '.';
										c[i][j + 2] = '.';
									} else {
										c[i + 1][0] = '.';
										c[i + 1][1] = '.';
									}
									break;
								}
							}
							if (val == tmp) {
								break;
							}
						}
					}
				} else {
					int val = 2;
					c[0][0] = 'c', c[1][0] = '.';
					for (int j = 1; j < m; j++) {
						c[0][j] = '.', c[1][j] = '.';
						val += 2;
						if (val == tmp) {
							break;
						}
					}
					if (val < tmp) {
						for (int i = 2; i < n; i++) {
							for (int j = 0; j < m; j++) {
								c[i][j] = '.';
								val++;
								if (val == tmp) {
									if (j == 0) {
										c[i - 1][m - 1] = '*';
										c[i][1] = '.';
									}
									break;
								}
							}
							if (val == tmp) {
								break;
							}
						}
					}
				}
			}
		}
		if (f) {
			int t = max(n, m);
			for (int i = 0; i < t; i++) {
				for (int j = i; j < t; j++) {
					swap(c[i][j], c[j][i]);
				}
			}
			swap(n, m);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf("%c", c[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
