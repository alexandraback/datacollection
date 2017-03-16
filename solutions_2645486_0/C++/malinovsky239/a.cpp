#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <complex>
#include <cstdio>
#include <vector>
#include <cctype>
#include <string>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

typedef long double LD;
typedef long long LL;

using namespace std;

#define sz(A) (int)(A).size()
#define mp make_pair
#define pb push_back

const int N = int(1e4 + 5), M = 100;
const LL INF = LL(1e18);

int v[N];
LL dp[N][M];

int main() {
	int t;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		int e, r, n;
		scanf("%d%d%d", &e, &r, &n);		

		for (int j = 0; j < n; j++) {
			scanf("%d", &v[j]);
			for (int k = 0; k <= e; k++)
				dp[j][k] = -INF;
		}
		for (int k = 0; k <= e; k++)
			dp[n][k] = -INF;

		dp[0][e] = 0;
	
	    for (int j = 0; j < n; j++)
	    	for (int k = 0; k <= e; k++) {
	    		for (int sp = 0; sp <= k; sp++) {
		    		int nxt = min(e, k - sp + r);
		    		dp[j + 1][nxt] = max(dp[j + 1][nxt], dp[j][k] + v[j] * sp);
				}
	    	}
	    	
		LL res = 0;
		for (int k = 0; k <= e; k++)
			res = max(res, dp[n][k]);	

		printf("Case #%d: %I64d\n", i + 1, res);		
	}

	return 0;
}

