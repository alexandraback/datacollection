#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<cmath>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cstdlib>

using namespace std;

const int debug = 0;
#define DEBUG(x) cout<<">> "<<#x<<':'<<(x)<<endl
const int inf = 1000000000;

int BF[1005];
int res;
int sp[1005];
int dp[1005];
int vis[1005];

int main() {
	int test, cases = 1;
	cin >> test;
	for (cases = 1; cases <= test; cases++) {
		int n;
		cin >> n;
		int indegree[1005] = {0};
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			BF[i] = a;
			indegree[a]++;
			sp[i] = 0;
			dp[i] = 0;
			vis[i] = 0;
		}

		for (int i = 1; i <= n; i++) {
			if (BF[ BF[i] ] == i) {
				sp[i] = 1;
				sp[ BF[i] ] = 1;
			}
		}

		for (int i = 1; i <= n; i++) {
			if (indegree[i] == 0) {
				int cnt = 1;
				int nd = i;
				while(cnt <= n) {
					nd = BF[nd];
					if (sp[nd]) {
						dp[ nd ] = max(dp[nd], cnt);
						break;
					}
					cnt++;
				}
			}
		}

		res = 0;
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (sp[i]) {
				sum += dp[i] + 1;
			}
		}

		res = sum;

		for (int i = 1; i <= n; i++) {
			int cnt = 1;
			int nd = i;
			for (int j = 1; j <= n; j++) {
				vis[j] = 0;
			}
			vis[i] = 1;
			while(true) {
				if (debug) cout << i << " --- " << nd << endl;
				nd = BF[nd];
				if (nd == i) {
					res = max(res, cnt);
					break;
				}
				if (vis[nd]) break;
				vis[nd] = 1;
				cnt++;
			}
		}

		printf("Case #%d: %d\n", cases, res);

	}
	return 0;
}
