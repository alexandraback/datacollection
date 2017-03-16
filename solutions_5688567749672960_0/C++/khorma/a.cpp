//In the name of God
//...
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef long double LD;

const int N = 1e6 + 6, MAX = 1e8;

int dp[MAX], n;


int main() {
	fill(dp, dp + MAX, -1);
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
		if (dp[y] == -1) {
			dp[y] = dp[f] + 1;
			q.push(y);
		}
		if (f < MAX - 2 && dp[f + 1] == -1) {
			dp[f + 1] = dp[f] + 1;
			q.push(f + 1);
		}
	}
	cerr << "OK\n";
	int test = 0;
	cin >> test;
	for (int tt = 1; tt <= test; tt++) {
		cin >> n;
		cout << "Case #" << tt << ": " << dp[n] << '\n';
	}
	return 0;
}
