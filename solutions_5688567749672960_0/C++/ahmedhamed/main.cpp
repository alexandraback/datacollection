#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

void fastInOut();

const int OO = 1e9;

int rev(int cur) {
	int ret = 0;
	while (cur != 0)
		ret *= 10, ret += (cur % 10), cur /= 10;
	return ret;
}

int n, memo[1000001];
int solve(int cur) {
	if (cur == n)
		return 0;
	if (cur > n)
		return OO;
	int &ret = memo[cur];
	if (ret != -1)
		return ret;
	int ret1 = solve(cur + 1), ret2 = OO;
	int rv = rev(cur);
	if (rv > cur)
		ret2 = solve(rv);
	return ret = 1 + min(ret1, ret2);
}

int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	fastInOut();
	int t;
	cin >> t;
	for (int tst = 1; tst <= t; ++tst) {
		cin >> n;
		memset(memo, -1, sizeof memo);
		for (int u = n; u > 1; --u)
			solve(u);
		cout << "Case #" << tst << ": " << solve(1) + 1 << "\n";
	}
	return 0;
}

void fastInOut() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
