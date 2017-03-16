#include <iostream>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <cstdio>
using namespace std;

int reverse (int n) {
	int ret = 0;
	while (n > 0) {
		ret += n%10;
		ret *= 10;
		n /= 10;
	}
	return ret/10;
}

int dp[1000005];
	
int main () {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	int t, n;
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		
		// limpio dp
		for (int i = 0; i <= n; i++) {
			dp[i] = i+3;
		}
		
		dp[1] = 1;
		for (int i = 2; i <= n; i++) {
			dp[i] = dp[i-1] + 1;
			int revi = reverse(i);
			if (revi < i && reverse(revi) == i) {
				//cout << revi << " " << i << endl;
				dp[i] = min(dp[i-1] + 1, dp[revi] + 1);
			}
		}
		cout << "Case #" << tc << ": " << dp[n] << endl;
	}
	return 0;
}
