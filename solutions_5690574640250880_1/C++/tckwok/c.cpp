#include <cstdio>

#define N 64

int T, n, m, k;
char d[N][N];

int main() {
	scanf("%d", &T);
	for (int r = 1; r <= T; ++r) {
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				d[i][j] = '*';
		for (int i = 0; i < n; ++i)
			d[i][m] = 0;
		k = n*m - k;
		printf("Case #%d:\n", r);
		if (k == 1) {
			d[0][0] = 'c';
			for (int i = 0; i < n; ++i)
				puts(d[i]);
			continue;
		}
		if (n == 1 || m == 1) {
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j)
					if (i + j < k) d[i][j] = '.';
			d[0][0] = 'c';
			for (int i = 0; i < n; ++i)
				puts(d[i]);
			continue;
		}
		if (n == 2 || m == 2) {
			if ((k&1) || k < 4) puts("Impossible");
			else {
				for (int i = 0; i < n; ++i)
					for (int j = 0; j < m; ++j)
						if (n == 2 && j + j < k || m == 2 && i + i < k) d[i][j] = '.';
				d[0][0] = 'c';
				for (int i = 0; i < n; ++i)
					puts(d[i]);
			}
			continue;
		}
		if (k < 4 || k == 5 || k == 7) {
			puts("Impossible");
			continue;
		}
		if (k <= m + m + 1) {
			if (k&1) {
				d[2][0] = d[2][1] = d[2][2] = '.';
				k -= 3;
			}
			for (int i = 0; i < 2; ++i)
				for (int j = 0; j + j < k; ++j)
					d[i][j] = '.';
			d[0][0] = 'c';
			for (int i = 0; i < n; ++i)
				puts(d[i]);
			continue;
		}
		if (k%m == 1) {
			for (int i = 0; i < k/m - 1; ++i)
				for (int j = 0; j < m; ++j)
					d[i][j] = '.';
			for (int j = 0; j < m - 1; ++j)
				d[k/m - 1][j] = '.';
			d[k/m][0] = d[k/m][1] = '.';
			d[0][0] = 'c';
			for (int i = 0; i < n; ++i)
				puts(d[i]);
			continue;
		}
		for (int i = 0; i < k/m; ++i)
			for (int j = 0; j < m; ++j)
				d[i][j] = '.';
		for (int j = 0; j < k%m; ++j)
			d[k/m][j] = '.';
		d[0][0] = 'c';
		for (int i = 0; i < n; ++i)
			puts(d[i]);
		continue;
	}
	return 0;
}
