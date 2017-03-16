//In the name of God
#include <iostream>
using namespace std;
const int lg = 33;

long long dp[lg][8];

int main() {
	ios_base::sync_with_stdio(false);
	int test; cin >> test;
	for (int i = 1; i <= test; i++) {
		cout << "Case #" << i << ": ";
		int a[3] = {};
		cin >> a[0] >> a[1] >> a[2];
		dp[31][7] = 1;
		fill(dp[0], dp[31], 0);
		for (int i = 30; i >= 0; i--)
			for (int m1 = 0; m1 < 8; m1++)
				for (int cur = 0; cur < 8; cur++) {
					if (((cur & 1) && (cur & 2)) != (bool) (cur & 4))
						continue;
					bool flag = false;
					int mask = m1;
					for (int j = 0; j < 3; j++) {
						if ((m1 & 1 << j) && (a[j] >> i & 1) < (cur >> j & 1)) {
							flag = true;
							break;
						}
						if ((a[j] >> i & 1) != (cur >> j & 1))
							mask &= ~(1 << j);
					}
					if (flag)
						continue;
					dp[i][mask] += dp[i + 1][m1];
				}
		cout << dp[0][0] << '\n';
	}
	return 0;
}
