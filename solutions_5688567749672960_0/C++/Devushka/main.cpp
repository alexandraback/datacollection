#include <bits/stdc++.h>

using namespace std;

int rever(int x) {
	if (x % 10 == 0) return x;
	int res = 0;
	while (x != 0) {
		res = res * 10 + x % 10;
		x /= 10;
	}
	return res;
}

const int N = 1000010;
int dp[N];

int ddp(int pos) {
	if (pos < 1) {
		return 10000010;
	}
	if (pos == 1) {
		dp[pos] = 1;
		return 1;
	}
	if (dp[pos] != -1) {
		return dp[pos];
	}
	int r = rever(pos);
	if (r < pos) {
		dp[pos] = min(ddp(pos - 1), ddp(r)) + 1;
	} else {
		dp[pos] = ddp(pos - 1) + 1;
	}
	return dp[pos];
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int test;
	cin >> test;
	for (int i = 0; i < N; i++) {
		dp[i] = -1;
	}             
//	for (int i = 1; i < 24; i++) {
//		cout << ddp(i) << "  ";
//	}
	cout << endl;
	for (int t = 0; t < test; t++) {
		int n;
		cin >> n;
		cout << "Case #" << t + 1 << ": " << ddp(n) << endl;
	}

}

