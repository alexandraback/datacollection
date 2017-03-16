#include<iostream>
#include<cstring>

using namespace std;

int dp[20][10], v[20];
int main() {
	int Ncase;
	
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> Ncase;
	for (int T = 1; T <= Ncase; T ++) {
		int e, r, n, ans = 0;
		cin >> e >> r >> n;
		for (int i = 1; i <= n; i ++) {
			cin >> v[i];
		}
		
		memset(dp, -1, sizeof(dp));
		dp[0][e] = 0;
		for (int i = 1; i <= n; i ++) {
			for (int j = 0; j <= e; j ++) {
				if (dp[i - 1][j] != -1) {
					for (int k = j; k >= 0; k --) {
						int x = dp[i - 1][j] + k * v[i];
						int y = ((j - k) + r) < e ? ((j - k) + r) : e;
						
						if (dp[i][y] < x) {
							dp[i][y] = x;
							ans = ans > x ? ans : x;
						}
					}
				}
			}
		}
		
		cout << "Case #" << T << ": " << ans << endl;
	}
	
	return 0;
}
