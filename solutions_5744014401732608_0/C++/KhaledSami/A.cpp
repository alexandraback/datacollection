#include <iostream>
#include <set>
#include <cstdio>
#include <map>
#include<vector>
#include<algorithm>
using namespace std;
bool mat[52][52];
int B;
long long dp[52][52];

long long getNumberOfPaths(int u, int v) {
   if (u == v) return 1;
   long long& count = dp[u][v];
   if (count != -1) return count;
   count = 0;
   for (int i = 0; i < B; i++)
       if (mat[u][i] == 1)
           count += getNumberOfPaths(i, v);
   return count;
}

int main() {
	freopen("A-large.in", "rt", stdin);
	freopen("A-large.out", "wt", stdout);
	int t;
	long long M;
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		cin >> B >> M;
		memset(mat, 0 , sizeof (mat));
		for (int i = 0; i < B; i++) {
			for (int j = i + 1; j < B; j++) {
				mat[i][j] = true;
			}
		}
		cout << "Case #" << tt <<": ";
		long long ans = 0;
		bool imp = false;
		while (true) {
			memset(dp, -1 , sizeof (dp));
			ans = getNumberOfPaths(0, B-1);
//			cout << ans << endl;
			if (ans < M) {
				cout <<"IMPOSSIBLE\n";
				imp = true;
				break;
			} else if (ans == M){
				break;
			} else {
				bool cut = true;
				for (int i = 0; i < B && cut; i++) {
					for (int j = i + 2; j < B; j++) {
						if (mat[i][j]) {
//							cout <<"edge" <<" "<< i + 1 << " "<<j + 1 << endl;
							mat[i][j] = false;
							cut = false;
							break;
						}
					}
				}
			}
		}
		if (!imp) {
			cout << "POSSIBLE"<< endl;
			for (int i = 0 ; i < B; i++) {
				for (int j = 0; j < B; j++) {
					cout << mat[i][j] ;
				}
				cout << endl;
			}
		}
	}
	return 0;
}
