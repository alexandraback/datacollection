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

#define pf printf
#define sf scanf
#define VI vector<int>
#define pb push_back
#define fo(a,b) for((a)=0;(a)<(b);a++)

#define debug 0
const int inf = 1000000000;

long long ncr[305][305] = {0}; void gen_ncr(int n) { int i, j; fo(i, n+1) ncr[i][0] = 1; for(i=1;i<=n;i++) for(j=1;j<=n;j++) ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];}
double dis(double x1, double y1, double x2, double y2) { return sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)); }

int n;
int one[1003];
int two[1003];

int dp[1<<20];

int memo(int state, int star) {
	if( dp[ state ] != -1 ) return dp[state];
	if( __builtin_popcount(state) == n )
		return 0;
	int res = inf;
	int i;
	for(i=1;i<n;i+=2) {
		if( !(state & (1<<i)) ) {
			if( two[ i/2 ] <= star ) {
				int cnt;
				if( state & (1<<(i-1))) cnt = 1;
				else cnt = 2;
				int k = 1 + memo(state | (1<<i) | (1<<(i-1)), star + cnt) ;
				res <?= k;
			}
		}
	}

	for(i=0; i<n; i+=2) {
		if( !(state & (1<<i) ) ) {
			if( one[i/2] <= star ) {
				int k = 1 + memo(state | (1<<i), star + 1);
				res <?= k;
			}
		}
	}

	return dp[state] = res;
}

int main() {
	int test, cases = 1;
	cin >> test;
	for( cases=1; cases<=test; cases++ ) {
		cin >> n;
		int i;
		for(i=0; i<n; i++) {
			cin >> one[i] >> two[i];
		}

		n *= 2;
		for(i=0; i < (1<<n); i++)
			dp[i] = -1;

		int res = memo(0, 0);
		if( res >= inf )
			pf("Case #%d: Too Bad\n", cases);
		else
			pf("Case #%d: %d\n", cases, res);
	}
	return 0;
}

