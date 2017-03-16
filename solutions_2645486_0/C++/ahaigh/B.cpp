/*
 ID: aandrew
 PROG: gcj 2013, round 1a
 URL:
 LANG: C++
 
 */
#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <queue>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <map>
#include <cassert>
#include <set>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define CL(x) memset(x, 0, sizeof(x))
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MP make_pair
#define PB push_back

const int N = 100, V = 100; 
int T, e, r, n, v[N], dp[N][V];

int main() {
	int T;
	cin >> T;
	REP(qqq,T) {
		cin >> e >> r >> n;
		REP(i,n) cin >> v[i];
		
		CL(dp);
		for (int j = 0; j <= e; j++) dp[0][j] = 0;
		
		REP(i,n) {
			for (int j = 0; j <= e; j++) {
				//cout << dp[i][j] << " ";
				
				//try ...
				for (int k = 0; k <= e; k++) {
					int gain = k*v[i], end = min(min(e,j-k)+r,e);
					if (j-k >= 0) {
						dp[i+1][end] = max(dp[i+1][end], dp[i][j] + gain);
					}
				}
			}
			//cout << endl;
		}
		
		int ans = 0;
		for (int j = 0; j <= e; j++) ans = max(ans, dp[n][j]);
		cout << "Case #" << (qqq+1) << ": " << ans << endl;
	}
}
