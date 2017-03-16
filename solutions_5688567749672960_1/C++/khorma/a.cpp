//In the name of God
//...
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double LD;

long long a[20], t[20];


long long res(long long n) {
	if (n % 10 == 0)
		return res(n - 1) + 1;
	int d = 0;
	while (t[d + 1] <= n)
		d++;
//	cerr << d << '\n';
	long long ans = (n - t[d]) + a[d];
//	cerr << ans << '\n';
	int x = n, y = 0;
	while (x) {
		y = y * 10 + x % 10;
		x /= 10;
	}
	for (int i = 0; i <= d; i++) {
		int u = n % t[i], v = y % t[d - i + 1];
//		cerr << i << ": " << u << ' ' << v << '\n';
		if (u && v)
			ans = min(ans, a[d] + u + (v - 1) + 1);
	}
	return ans;
}
int main() {
/*	fill(dp, dp + MAX, -1);
	dp[1] = 1;
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int f = q.front();
		q.pop();
		int x = f, y = 0;
		while (x) {
			y = y * 10 + x % 10;
			x /= 10;
		}
		if (y > f)
			if (dp[y] == -1) {
				dp[y] = dp[f] + 1;
				q.push(y);
			}
		if (f < MAX - 2 && dp[f + 1] == -1) {
			dp[f + 1] = dp[f] + 1;
			q.push(f + 1);
		}
	}*/
	a[1] = 1; t[0] = 1;
	for (int i = 1; i < 16; i++)
		t[i] = t[i - 1] * 10;
	for (int i = 1; i < 16; i++) {
		a[i] = (t[(i + 1) / 2] - 2) + (t[i / 2] - 1) + 2 + a[i - 1];
		//		if (i < 7 && a[i] != dp[t[i]])
		//			cerr << t[i] << ": " << a[t[i]] << ' ' << dp[t[i]] << '\n';
	}
	a[0] = 1;
//	for (int i = 0; i < 7; i++)
//		cerr << t[i] << ": " << dp[t[i]] << ' ' << a[i] << '\n';
	int test = 0;
	cin >> test;
	for (int tt = 1; tt <= test; tt++) {
		long long n;
		cin >> n;
		cout << "Case #" << tt << ": " << res(n) << '\n';
	}
	return 0;
}
