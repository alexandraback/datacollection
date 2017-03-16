#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

const int maxn = 50;

int pre[maxn + 1][maxn + 1][maxn * maxn + 1];
int r, c, m;
bool reverse;

void print(int i, int last, int sum)
{
	if (i == 0) {
		return;
	}
	int j = pre[i][last][sum];
	print(i - 1, j, sum - last);
	
	for (int col = 0; col < c; ++ col) {
		if (col < last) {
			printf("*");
		} else {
			if (i == r && col == c - 1) {
				printf("c");
			} else {
				printf(".");
			}
		}
	}
	puts("");
}

int main()
{
	int tests, test = 1;
	for (scanf("%d", &tests); test <= tests; ++ test) {
		scanf("%d%d%d", &r, &c, &m);
		
		printf("Case #%d:\n", test);
		
		if (m == r * c - 1) {
			for (int i = 0; i < r; ++ i) {
				for (int j = 0; j < c; ++ j) {
					if (i || j) {
						printf("*");
					} else {
						printf("c");
					}
				}
				puts("");
			}
			continue;
		}
		
		if (r == 1) {
			if (m <= c - 1) {
				for (int i = 0; i < c; ++ i) {
					if (i < m) {
						printf("*");
					} else if (i == c - 1) {
						printf("c");
					} else {
						printf(".");
					}
				}
				puts("");
			} else {
				puts("Impossible");
			}
			continue;
		}
		
		if (c == 1) {
			if (m <= r - 1) {
				for (int i = 0; i < r; ++ i) {
					if (i < m) {
						printf("*\n");
					} else if (i == r - 1) {
						printf("c\n");
					} else {
						printf(".\n");
					}
				}
			} else {
				puts("Impossible");
			}
			continue;
		}
		
		memset(pre, -1, sizeof(pre));
		
		pre[0][c][0] = -2;
		for (int i = 0, sum = 0; i < r; ++ i, sum += c) {
			for (int j = 0; j <= c; ++ j) {
				for (int s = 0; s <= sum && s <= m; ++ s) {
					if (pre[i][j][s] != -1) {
						for (int nc = 0; nc <= j; ++ nc) {
							if (s == sum && nc == c - 1) {
								continue;
							}
							if (i + 1 == r && nc != j) {
								continue;
							}
							
							pre[i + 1][nc][s + nc] = j;
						}
					}
				}
			}
		}
		
		bool flag = false;
		for (int last = 0; last <= c - 2; ++ last) {
			if (pre[r][last][m] != -1) {
				print(r, last, m);
				flag = true;
				break;
			}
		}
		if (!flag) {
			puts("Impossible");
		}
	}
	return 0;
}
