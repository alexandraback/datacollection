#include <cstdio>
#include <algorithm>
using namespace std;

long double nm[1234], kn[1234]; int t, n, dp[1234][1234], w, dw; char s[1234];
int main() {
	freopen("d.in", "r", stdin); freopen("d.out", "w", stdout);
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%Lf", nm+i);
		for (int i = 0; i < n; i++) scanf("%Lf", kn+i);
		w = n; dw = 0;
		for (int i = 0; i < n; i++) s[i] = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) dp[i][j] = 0;
		sort(nm, nm+n); sort(kn, kn+n);
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (!s[j] && kn[j] > nm[i]) {
			s[j] = 1; w--; break;
		}
		for (int d = n-1; d; d--) for (int st = 0, end = d; end < n; st++, end++) {
			int pl = n-d-1;
			if (nm[pl] > kn[st]) dp[st+1][end] = max(dp[st+1][end], dp[st][end]+1);
			if (nm[pl] < kn[end]) dp[st][end-1] = max(dp[st][end-1], dp[st][end]);
		}
		for (int i = 0; i < n; i++) dw = max(dw, dp[i][i] + (nm[n-1] > kn[i]));
		printf("Case #%d: %d %d\n", tc, dw, w);
	}

	return 0;
}