#include<iostream>
#include<cstring>

using namespace std;

int dp[1100000][21];
int keys[201], cur[201];
int chest[21], contain[21][41];
int q[1100000];

int judge(int x, int y, int tot) {
	if (!dp[y][0]) {
		return true;
	}
	
	for (int u = 1; u <= tot; u ++) {
		if (dp[x][u] < dp[y][u]) {
			return true;
		} else if (dp[x][u] > dp[y][u]) {
			break;
		}
	}
	
	return false;
}

int main() {
	int Ncase;
	
	cin >> Ncase;
	for (int t = 1; t <= Ncase; t ++) {
		int x, k, n;
		memset(dp, 0, sizeof(dp));
		memset(keys, 0, sizeof(keys));
		
		cin >> k >> n;
		int m = (1 << n) - 1;
		for (int i = 0; i < k; i ++) {
			cin >> x;
			keys[x] ++;
		}
		
		for (int i = 0; i < n; i ++) {
			cin >> chest[i] >> contain[i][0];
			
			for (int j = 1; j <= contain[i][0]; j ++) {
				cin >> contain[i][j];
			}
		}
		
		int head = -1, tail = 0;
		q[0] = 0;
		dp[0][0] = 1;
		while (head != tail) {
			int x = q[++ head], tot = 0;
			for (int i = 1; i <= 200; i ++) {
				cur[i] = keys[i];
			}
			
			for (int i = 0; i < n; i ++) {
				if (x & (1 << i)) {
					tot ++;
					cur[chest[i]] --;
				
					for (int j = 1; j <= contain[i][0]; j ++) {
						cur[contain[i][j]] ++;
					}
				}
			}
			
			for (int i = 0; i < n; i ++) {
				if (x & (1 << i)) {
					continue;
				}
				
				if (cur[chest[i]]) {
					int y = x | (1 << i);
					
					if (judge(x, y, tot)) {
						if (!dp[y][0]) {
							dp[y][0] = 1;
							q[++ tail] = y;
						}
						
						for (int j = 1; j <= tot; j ++) {
							dp[y][j] = dp[x][j];
						}
						dp[y][tot + 1] = i;
					}
				}
			}
		}
	
		cout << "Case #" << t << ":";
		if (!dp[m][0]) {
			cout << " IMPOSSIBLE";
		} else {
			for (int i = 1; i <= n; i ++) {
				cout << " " << dp[m][i] + 1;
			}
		}
		cout << endl;
	}
}
