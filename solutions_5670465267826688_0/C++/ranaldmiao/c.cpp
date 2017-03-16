#include <bits/stdc++.h>
using namespace std;
int T, L, dp[10050][10050];
long long X;
vector<long long> v1, v2;
char s[120050];
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
		for (int i = 0; i < L; ++i) {
			dp[i][i] = s[i] - 'i' + 2;
			for (int j = i+1; j < L; ++j) {
				dp[i][j] = mult(dp[i][j-1], s[j] - 'i' +2);
			}
		}
		for (long long i = 0; i < min(L*X, L*4ll); ++i) {
			if (query(0, i) == 2) v1.push_back(i);
			if (query(L*X-i-1, L*X-1) == 4) v2.push_back(L*X-i-1);
		}
		
		//printf("ALL: %d %d %d\n", query(0, L*X-1), v1.size(), v2.size());
		bool pass = 0;
		for (int i = 0; i < v1.size() && !pass; ++i) {
			for (int j = 0; j < v2.size() && !pass; ++j) {
				if (v1[i]+1 > v2[j]-1) break;
				if (query(v1[i]+1, v2[j]-1) == 3) {
					 //printf("%d %d %d: %d\n", query(0, v1[i]), query(v1[i]+1, v2[j]-1), query(v2[j], L*X-1), query(0, L*X-1));
					pass = true;
				}
			}
		}
		if (pass) printf("Case #%d: YES\n", t);
		else printf("Case #%d: NO\n", t);
		v1.clear();
		v2.clear();
	}
}
