#include <bits/stdc++.h>
using namespace std;
int T, L, dp[10050][10050];
long long X;
char s[10050];
int m[5][5] = { {0, 0, 0, 0, 0}, 
				{0, 1, 2, 3, 4}, 
				{0, 2, -1, 4, -3}, 
				{0, 3, -4, -1, 2}, 
				{0, 4, 3, -2, -1} 
			};
int mult(int x, int y) { // i = 2, j = 3, k = 4
	if (x < 0) return -mult(-x, y);
	if (y < 0) return -mult(x, -y);
	return m[x][y];
}
int power(int x, long long e) {
	if (x == 1) return 1;
	if (x == -1) {
		if (e % 2 == 0) return 1;
		return -1;
	}
	if (e%4 == 1) return x;
	if (e%4 == 2) return -1;
	if (e%4 == 3) return -x;
	return 1; 
}
int query(long long x, long long y) {
	y -= x - x%L;
	x %= L;
	if (y < L) return dp[x][y];
	return mult(dp[x][L-1], mult(power(dp[0][L-1], y/L-1), 
	dp[0][y%L]));
}
int main () {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d%lld", &L, &X);
		scanf("%s", s);
		long long minI = -1, maxI = -1;
		int cur = 1;
		for (int i = 0; i < L; ++i) cur = mult(cur, s[i]-'i'+2);
		if (power(cur, X) != -1) {
			printf("Case #%d: NO\n", t);
			continue;
		}
		cur = 1;
		for (long long i = 0; i < L*X && i < L*4ll; ++i) {
			cur = mult(cur, s[i%L]-'i'+2);
			if (cur == 2) {
				minI = i;
				break;
			}
		}
		if (minI == -1) {
			printf("Case #%d: NO\n", t);
			continue;
		}
		cur = 1;
		for (long long i = L*X-1; i >= 0 && i >= L*(X-4); --i) {
			cur = mult(s[i%L]-'i'+2, cur);
			if (cur == 4) {
				maxI = i;
				break;
			}
		}
		if (maxI == -1) {
			printf("Case #%d: NO\n", t);
			continue;
		}
		if (minI+1 <= maxI-1) printf("Case #%d: YES\n", t);
		else printf("Case #%d: NO\n", t);
	}
}
