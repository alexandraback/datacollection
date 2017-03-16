#include <cstdio>
#include <algorithm>
using namespace std;

#define N 2048

int abs(int x) {
	return x < 0 ? -x : x;
}

int cp[N], T, n, x, y;
double C[N][N], p2[N];

double f(int n, int x, int y) {
	int k = lower_bound(cp, cp + N, n) - cp;
	int layer = (abs(x) + y >> 1);
	if (layer < k) return 1.;
	if (k < layer) return 0.;
	if (n == cp[k]) return 1.;
	if (x == 0) return 0.;
	int a = n - cp[k - 1], b = y + 1;
	if (a >= b + k + k) return 1.;
	double r = 0.;
	for (int i = b; i <= a; ++i) r += C[a][i];
	return r/p2[a];
}

int main() {
	cp[0] = 1;
	for (int i = 1; i < N; ++i)
		cp[i] = cp[i - 1] + i*4 + 1;
	for (int i = 0; i < N; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}
	p2[0] = 1;
	for (int i = 1; i < N; ++i)
		p2[i] = p2[i - 1] + p2[i - 1];
	scanf("%d", &T);
	for (int r = 1; r <= T; ++r) {
		scanf("%d%d%d", &n, &x, &y);
		printf("Case #%d: %.10f\n", r, f(n, x, y));
	}
	return 0;
}
