#include <bits/stdc++.h>
using namespace std;
int n;
int solve(vector<int> S, int eat) {
	int ans = 0;
	for (int i = 0; i < (int)S.size(); i++) {
		int x = S[i];
		while (x > eat) {
			ans++;
			x -= eat;
		}
	}
	return ans;
}
void solve() {
	vector<int> S;
	scanf("%d", &n);
	int mx = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		S.push_back(x);
		mx = max(mx, x);
	}
	int ans = mx;
	for (int k = 1; k <= mx; k++) {  	
		ans = min(ans, k + solve(S, k));
  } 
	printf("%d\n", ans);
}
int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int ti = 1; ti <= T; ti++) {
		printf("Case #%d: ", ti);
		solve();
	}
	return 0;
}