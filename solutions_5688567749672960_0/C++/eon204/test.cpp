#include <bits/stdc++.h>

using namespace std;

int dp[1000005];

int reverse(int n) {
	stack<int> s;
	while (n != 0) {
		s.push(n%10);
		n /= 10;
	}
	int pwr = 1, ret = 0;
	while (!s.empty()) {
		ret += s.top() * pwr;
		pwr *= 10;
		s.pop();
	}
	return ret;
}

int main() {
	
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	int i, j;
	memset(dp, -1, sizeof(dp));
	queue<int> q;
	q.push(1);
	dp[1] = 1;
	while (!q.empty()) {
		int f = q.front(); q.pop();
		if (f > 1000000) continue;
		if (dp[f+1] == -1) {
			dp[f+1] = dp[f] + 1;
			q.push(f+1);
		}
		int rev = reverse(f);
		if (dp[rev] == -1) {
			dp[rev] = dp[f] + 1;
			q.push(rev);
		}
	}
	
	int n, x;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		cout << "Case #"<<i+1<<": " << dp[x] << "\n";
	}
	
	
	return 0;
}
