#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <algorithm>

using namespace std;

#define maxn 720

int n, x, y, k;
double f[maxn][2 * maxn][2 * maxn];

int calc() {
	for (int i = 1; i < maxn - 1; ++i) {
		f[i][0][0] = 1.0;
		for (int j = 0; j <= 2 * i; ++j)
			for (int k = 0; k <= 2 * i; ++k) {
				if (j == 2 * i) {
					if (k != 2 * i) f[i][j][k + 1] += f[i][j][k];
				} else {
					if (k == 2 * i) f[i][j + 1][k] += f[i][j][k];
					else f[i][j + 1][k] += f[i][j][k] / 2, 
						f[i][j][k + 1] += f[i][j][k] / 2;
				}
			}
	}
	return 0;
}

int proc(const int &id) {
	printf("Case #%d: ", id);
	scanf("%d%d%d", &n, &x, &y);
	int k = 1;
	while (k * (2 * k - 1) < n) ++k;
	double ans = 0.0;
	if ((2 * k - 1) * k == n) {
		if (y - x <= 2 * (k - 1) && y + x <= 2 * (k - 1)) ans = 1.0;
	} else {
		--k;
		n -= k * (2 * k - 1);
		if (y - x <= 2 * k - 2 && y + x <= 2 * k - 2) ans = 1.0;
		else if (y - x > 2 * k || y + x > 2 * k) ans = 0.0;
		else {
			if (x == 0 && y == 2 * k) ans = 0.0;
			else {
				int below = y + 1;
				for (int i = below; i <= n; ++i)
					ans += f[k][i][n - i];
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
