#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

string dic[521196];
string s;
int l, maxlen, n;
int start[10], ans[5];
int dp[100][5];

void d_search(int pos, int len, int offset) {
	memset(ans, -1, sizeof(ans));
	
	for (int i = start[len - 1]; i < start[len]; i ++) {
		int cur = offset, r = 0;
		bool succ = true;
		
		for (int u = 0; u < len; u ++) {
			if(s[pos + u] == dic[i][u]) {
				if (cur != 0) {
					cur --;
				}
			} else {
				if (cur != 0) {
					succ = false;
					break;
				} else {
					r ++;
					cur = 4;
				}
			}
		}
		
		if (succ && (ans[cur] == -1 || ans[cur] > r)) {
			ans[cur] = r;
		}
	}
}

bool cmp(string a, string b) {
	return a.size() < b.size();
}

int main() {
	freopen("dict.txt", "r", stdin);
	n = 521196;
	maxlen = 0;
	for (int i = 0; i < n; i ++) {
		cin >> dic[i];
		maxlen = maxlen > dic[i].size() ? maxlen : dic[i].size();
	}
	
	sort(dic, dic + n, cmp);
	
	int cur = 1;
	for (int i = 0; i < n; i ++) {
		if (dic[i].size() == cur) {
			start[cur - 1] = i;
			cur ++;
		}
	}
	
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int Ncase;
	cin >> Ncase;
	for (int T = 1; T <= Ncase; T ++) {
		cout << "Case #" << T << ": ";
		
		cin >> s;
		int l = s.size();
		
		memset(dp, -1, sizeof(dp));
		dp[0][0] = 0;
		for (int i = 0; i < l ; i ++) {
			for (int j = 0; j < 5; j ++) {
				if (dp[i][j] != -1) {
					for (int u = 1; u <= maxlen; u ++) {
						if (i + u > l) {
							break;
						}
						d_search(i, u, j);
						
						for (int v = 0; v < 5; v ++) {
							if (ans[v] != -1 &&
								(dp[i + u][v] == -1 || dp[i + u][v] > dp[i][j] + ans[v])) {
									dp[i + u][v] = dp[i][j] + ans[v];
								} 
						}
					}
				}
			}
		}
		
		int best = -1;
		for (int i = 0; i < 5; i ++) {
			if (dp[l][i] != -1 && (best == -1 || best > dp[l][i])) {
				best = dp[l][i];
			}
		}
		cout << best << endl;
	}
}
