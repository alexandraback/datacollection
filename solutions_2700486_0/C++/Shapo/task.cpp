#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <algorithm>

using namespace std;

#define maxn 50

int n, x, y, k;
double dist[maxn][maxn];
double noway[maxn][maxn];
double f[maxn][maxn][maxn];

int calc() {
	/*dist[0][0] = 1.0;
	for (int i = 0; i < maxn - 1; ++i)
		for (int j = 0; j < maxn - 1; ++j) {
			dist[i][j + 1] += (dist[i][j]) / 2;
			dist[i + 1][j] += (dist[i][j]) / 2;
		}
	for (int i = 2; i < maxn - 1; i += 2) {
		noway[i][0] = dist[i][0];
		//printf("noway[%d] = %.16lf\n", i, noway[i][0]);
		for (int j = 1; j <= i; ++j)
			noway[i][j] = dist[i - 1][j] / 2 + noway[i][j - 1]
				;//printf("%d %d = %.16lf\n", i, j, noway[i][j]);
		//assert(noway[i][i] == 1.0);
	}*/
	for (int i = 2; i < maxn; i += 2) {
		f[i][0][0] = 1.0;
		for (int j = 0; j <= i; ++j)
			for (int k = 0; k <= i; ++k)
				if (j == i) {
					if (k != i) f[i][j][k + 1] += f[i][j][k];
				} else {
					if (k == i) f[i][j + 1][k] += f[i][j][k];
					else f[i][j + 1][k] += f[i][j][k] / 2, 
						f[i][j][k + 1] += f[i][j][k] / 2;
				}
	}
	return 0;
}

int proc(const int &id) {
	printf("Case #%d: ", id);
	scanf("%d%d%d", &n, &x, &y);
	int k = 1;
	while (k * (2 * k - 1) < n) ++k;
	//printf("k = %d\n", k);
	double ans = 0.0;
	if ((2 * k - 1) * k == n) {
		//printf("go 1\n");
		if (y - x <= 2 * (k - 1) && y + x <= 2 * (k - 1)) ans = 1.0;
	} else {
		//printf("go2\n");
		--k;
		n -= k * (2 * k - 1);
		//printf("n %d %d\n", n, k);
		if (y - x <= 2 * k - 2 && y + x <= 2 * k - 2) ans = 1.0;
		else if (y - x > 2 * k || y + x > 2 * k) ans = 0.0;
		else {
			if (x == 0 && y == 2 * k) ans = 0.0;
			else {
				int below = y + 1;
				for (int i = below; i <= n; ++i) {
					/*if (i < 2 * k && (n - i) < 2 * k) ans += dist[i][(n - i)];
					else {
						ans += noway[max(n - i, i)][min(n - i, i)];
					}*/
					ans += f[2 * k][i][n - i];
				}
			}
		}
	}
	printf("%.16lf\n", ans);
	return 0;
}

int main() {
	calc();
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) proc(i + 1);
	return 0;
}
