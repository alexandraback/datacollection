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

ofstream fout ("1AB.out");
ifstream fin ("1AB.in");

int main() {
	int T;
	fin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Working on Case #" << t << endl;
		int E,R,N;
		int value[10005];
		fin >> E >> R >> N;
		for (int i = 0; i < N; i++) {
			fin >> value[i];
		}
		int dp[15][10];
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= E; j++) {
				dp[i][j] = 0;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= E; j++) {
				int usable = min(E,j+R);
				for (int k = 0; k <= usable; k++) {
					dp[i+1][k] = max(dp[i+1][k],dp[i][j]+value[i]*(usable-k));
				}
			}
		}
		int ans=0;
		for (int i = 0; i <= E; i++) {
			ans = max(ans,dp[N][i]);
		}
		fout << "Case #" << t << ": " << ans << endl;
	}
    return 0;
}