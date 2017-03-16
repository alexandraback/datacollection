// Google Code Jam 2016 Round 1C
// Problem B. Slides!

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

string solve(int B, int M) {
	string ans;
	int bm = 1 << (B * (B - 1)) / 2;
	for (int b = 1; b < bm; ++b) {
		int a = b;
		int dp[8] = {};
		dp[1] = 1;
		for (int i = 1; i < B; ++i) {
			for (int j = i + 1; j <= B; ++j) {
				if (a & 1) {
					dp[j] += dp[i];
				}
				a >>= 1;
			}
		}
		if (dp[B] == M) {
			int c[8][8] = {};
			a = b;
			for (int i = 1; i < B; ++i) {
				for (int j = i + 1; j <= B; ++j) {
					if (a & 1) {
						c[i - 1][j - 1] = 1;
					}
					a >>= 1;
				}
			}
			for (int i = 0; i < B; ++i) {
				for (int j = 0; j < B; ++j) {
					if (j > 0) {
						ans += " ";
					}
					ans += ('0' + c[i][j]);
				}
				ans += "\n";
			}
			break;
		}
	}
	return ans;
}

int main(int argc, char *argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int B, M;
		cin >> B >> M;
		string ans = solve(B, M);
		cout << "Case #" << t << ": ";
		cout << (ans.empty() ? "IMPOSSIBLE" : "POSSIBLE") << endl;
		cout << ans;
	}
	return 0;
}
