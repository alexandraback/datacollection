#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;

const ll L = 100005, l2 = 105;
ll T, A, m[L], N, idx, t, dp[l2][l2], ans;

int main() {
	cin >> T;

	int cn = 0;
	while (T--) {
		printf("Case #%d: ", ++cn);

		cin >> A >> N;
		for (int i = 0; i < N; i++)
			cin >> m[i];

		sort(m, m + N);
		memset(dp, 0, sizeof dp);
		dp[0][0] = A;
		for (int i = 1; i <= N; i++)
			dp[0][i] = 2 * dp[0][i-1] - 1;

		for (int i = 1; i <= N; i++) {
			if (dp[i-1][0] > m[i-1])
				dp[i][0] = max(dp[i][0], dp[i-1][0] + m[i-1]);
			for (int j = 1; j <= N; j++) {
				dp[i][j] = 2 * dp[i][j-1] - 1;
				if (dp[i-1][j] > m[i-1])
					dp[i][j] = max(dp[i][j], dp[i-1][j] + m[i-1]);

				dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
			}
		}

		ans = 0;
		for (int i = 0; i <= N; i++) {
			if (dp[N][i] != 0) {
				ans = i;
				break;
			}
		}
		cout << ans << endl;

	}	

	return 0;
}
