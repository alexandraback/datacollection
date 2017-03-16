#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 1000+5;
int T, N, D[MAXN], H[MAXN], M[MAXN];
int main() {
	// freopen("put.in", "r", stdin);
	int d[2] = {}, m[2] = {};
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++)
			scanf("%d%d%d", &D[i], &H[i], &M[i]);
		int ans = 0;
		if (N == 1) {
			ans += int(D[1] == 0);
		} else if (N >= 2) {
			if (N == 1) {
				d[0] = D[1]; m[0] = M[1];
				d[1] = D[1]; m[1] = M[1]+1;
			} else if (N == 2) {
				d[0] = D[1]; m[0] = M[1];
				d[1] = D[2]; m[1] = M[2];
			}
			ans += int(d[0] == 0);
			ans += int(d[1] == 0);
			if (m[0] > m[1]) {
				swap(d[0], d[1]);
				swap(m[0], m[1]);
			}
			double t = (720-d[0])/360.0*m[0];
			double x = 360.0/m[1]*t;
			int f[2] = {};
			if (x <= 360-d[1])
				f[0] = 1;
			t = (360-d[0])/360.0*m[0];
			x = 360.0/m[1]*t;
			if (x < 360-d[1])
				f[1] = 1;
			ans += min(f[0], f[1]);
			// printf("%d %d %d %d\n", d[0], m[0], d[1], m[1]);
			// ans += (720-d[0])*m[0]*m[1]/360/(m[1]-m[0]);
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}