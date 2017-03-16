#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define ll long long
#define pii pair<int,int>

ofstream fout ("1BB.out");
ifstream fin ("1BB.in");

double dp[500][500];

int main() {
	int T;
	fin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Working on Case #" << t << endl;
		fout << "Case #" << t << ": ";
		int N,X,Y;
		fin >> N >> X >> Y;
		int level = (abs(X)+Y)/2;
		level++;
		ll cnt = 0;
		ll clvl = 0;
		while (cnt + clvl*4 + 1 <= N) {
			cnt += clvl*4 + 1;
			clvl++;
		}
		if (clvl >= level) {
			fout << "1.0" << endl;
		}
		else if (clvl < level-1) {
			fout << "0.0" << endl;
		}
		else {
			for (int i = 0; i < 500; i++) {
				for (int j = 0; j < 500; j++) {
					dp[i][j] = 0;
				}
			}
			ll toadd = N-cnt;
			ll req = Y+1;
			ll maxside = clvl*2;
			dp[0][0] = 1.0;
			for (int i = 0; i < toadd; i++) {
				for (int j = max((ll)0,i-maxside); j <= min((ll)i,maxside); j++) {
					if (j == maxside) dp[j][i-j+1] += dp[j][i-j];
					else if (i-j == maxside) dp[j+1][i-j] += dp[j][i-j];
					else {
						dp[j+1][i-j] += .5*dp[j][i-j];
						dp[j][i-j+1] += .5*dp[j][i-j];
					}
				}
			}
			double ans = 0;
			for (int i = req; i <= min(maxside,toadd); i++) ans += dp[i][toadd-i];
			fout << ans << endl;
		}
	}
    return 0;
}