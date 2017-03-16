#include <bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> DP;

int dp(int m, int w) {
	auto it = DP.find({m, w});
	if(it != DP.end()) return it->second;

	int res = numeric_limits<int>::max();

	if(m == w) return w;

	for(int i=1; i<=m; i++) {
		res = min(res, max({i > w ? dp(i - 1, w) + 1 + (m - i) / w : 0, (m - i) >= w ? dp(m - i, w) + 1 + (i - 1) / w : 0, w + 1}));
	}

	return  DP[{m, w}] = res;
}

int test() {
	int n, m, w;
	cin >> n >> m >> w;
	return (n - 1) * (m / w) + dp(m, w);
}

int main() {
	int t;
	cin >> t;
	for(int i=1; i<=t; i++) {
		cout << "Case #" << i << ": " << test() << endl;
	}
}
