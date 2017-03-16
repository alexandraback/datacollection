#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <memory.h>
using namespace std;

int n, x;
int n1, n2, w;
char db1[1005][30], db2[1005][30];
char t1[30], t2[30];

pair<int, int> a[1005];
int b[1005][1005];
int m, p[1005], c[1005];

bool recall(int k) {
	if (k == m) { return true; }
	for (int i = 2; i <= m; i++) {
		if (b[k][i] > 0 && c[i] == 0) {
			p[i] = k;
			c[i] = 1;
			bool flag = recall(i);
			if (flag) { return true; }
		}
	}
	return false;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);

	for (int k = 1; k <= n; k++) {
		scanf("%d", &x);
		n1 = n2 = 0;

		for (int i = 1; i <= x; i++) {
			int v1, v2;
			v1 = v2 = 0;

			scanf("%s %s", t1 + 1, t2 + 1);
			for (int j = 1; j <= n1; j++) {
				if (strcmp(db1[j] + 1, t1 + 1) == 0) {
					v1 = j;
					break;
				}
			}
			for (int j = 1; j <= n2; j++) {
				if (strcmp(db2[j] + 1, t2 + 1) == 0) {
					v2 = j;
					break;
				}
			}

			//printf("# %d %d\n", v1, v2);

			if (v1 == 0) {
				v1 = ++n1;
				strcpy(db1[n1] + 1, t1 + 1);
			}
			if (v2 == 0) {
				v2 = ++n2;
				strcpy(db2[n2] + 1, t2 + 1);
			}

			a[i] = make_pair(v1, v2);
		}

		memset(b, 0, sizeof(b));
		memset(p, 0, sizeof(p));
		memset(c, 0, sizeof(c));
		m = n1 + n2 + 2;

		for (int i = 1; i <= n1; i++) {
			b[1][i + 1] = 1;
		}
		for (int i = 1; i <= n2; i++) {
			b[1 + n1 + i][m] = 99999;
		}

		for (int i = 1; i <= x; i++) {
			b[a[i].first + 1][a[i].second + n1 + 1] = 1;
		}

		/*
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= m; j++) {
				printf("%d ", b[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		*/

		int sum = 0;
		while (recall(1)) {
			int xi = m;
			sum++;
			do {
				b[p[xi]][xi]--;
				b[xi][p[xi]]++;
				xi = p[xi];
			} while (xi > 1);
			memset(c, 0, sizeof(c));
		}

		printf("Case #%d: %d\n", k, x - sum);
	}

	return 0;
}