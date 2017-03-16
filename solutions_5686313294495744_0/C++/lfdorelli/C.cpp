#include <bits/stdc++.h>

using namespace std;
const int N = 16;
string A[N], B[N];
int dp[(1<<N)];
int n;
int solve (int mask) {
	int &res = dp[mask];
	if (res != -1) return res;
	set <string> sa, sb;
	for (int i = 0; i < n; ++i) {
		if ((mask>>i)&1) sa.insert (A[i]), sb.insert (B[i]);
	}
	res = 0;
	for (int i = 0; i < n; ++i) {
		if (((mask>>i)&1)==0) {
			if (sa.count(A[i]) == 0 or sb.count(B[i]) == 0) res = max (res, solve (mask + (1<<i)));
			else res = max (res, 1 + solve (mask + (1<<i)));
		}
	}
	return res;
}

int main (void) {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		printf ("Case #%d: ", i);
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> A[i] >> B[i];
		memset (dp, -1, sizeof dp);
		cout << solve (0) << endl;
	}
	return 0;
}
