#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

vector<int> solve() {
	const int N = 1e8;
	vector<int> dp(N + 1, 1e9);
	queue<int> q;
	dp[1] = 1;
	q.push(1);
	while (!q.empty()) {
		int i = q.front();
		q.pop();
		if (i + 1 <= N && dp[i + 1] > dp[i] + 1) {
			dp[i + 1] = dp[i] + 1;
			q.push(i + 1);
		}
		int x = i, num = 0;
		while (x) {
			num = num * 10 + x % 10;
			x /= 10;
		}
		if (num <= N && dp[num] > dp[i] + 1) {
			dp[num] = dp[i] + 1;
			q.push(num);
		}
	}	
	return dp;
}

int main() {
	ios_base::sync_with_stdio(false);
	const auto& dp = solve();
	int t;
	cerr << "Done\n";
	cin >> t;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> t;	
	for (int i = 1; i <= t; ++i) {
		int n;
		cin >> n;
		cout << "Case #" << i << ": " << dp[n] << "\n";
	}
	return 0;
}