#include<algorithm>
#include<iostream>
#include<cstring>

using namespace std;

long long a, dp[110][210], l[110];
int n;

int main() {
	int Ncase;
	
	freopen("A-small-attempt2.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> Ncase;
	for (int T = 1; T <= Ncase; T ++) {
		cout << "Case #" << T << ": ";
		
		memset(dp, 0, sizeof(dp));
		cin >> a >> n;
		
		for (int i = 0; i < n; i ++) {
			cin >> l[i];
		}
		sort(l, l + n);
		
		dp[0][0] = a;
		int ans = n;
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < 210; j ++) {
				if (dp[i][j] > 0) {
					if (dp[i][j] > l[i]) {
						dp[i + 1][j] = dp[i + 1][j] > (dp[i][j] + l[i]) ? dp[i + 1][j] : (dp[i][j] + l[i]); 
					}
					
					dp[i + 1][j + 1] = dp[i + 1][j + 1] > dp[i][j] ? dp[i + 1][j + 1] : dp[i][j];
					
					if (dp[i][j] > 1 && dp[i][j] <= l[i] && j < 209) {
						long long x = dp[i][j] * 2 - 1;
						if (x > l[i]) {
							dp[i + 1][j + 1] = dp[i + 1][j + 1] > (x + l[i]) ? dp[i + 1][j + 1] : (x + l[i]);
						} else {
							dp[i + 1][j + 1] = dp[i + 1][j + 1] > x ? dp[i + 1][j + 1] : x;
						}
						
						dp[i][j + 1] = dp[i][j + 1] > x ? dp[i][j + 1] : x;
					}
				} 
			}
		}
		
		for (int i = 0; i < 210; i ++) {
			if (dp[n][i] > 0) {
				ans = i;
				break;
			}
		}
		
		cout << ans << endl;
	}
	
	return 0;
}
