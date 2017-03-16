#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>
#include <utility>
#include <list>
#include <set>
#include <bitset>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FOE(i,a,b) for (int i = (a); i <= (b); i++)
#define FR(i,e) for(__typeof(e.begin()) i = e.begin(); x != e.end(); i++)
#define SQR(x) ((x)*(x))
#define REP(i,n) FOR(i,0,n)
#define CLR(a,b) memset(a, b, sizeof(a))
#define INF (1<<29)
#define LL long long
#define PII pair<int,int>
#define PDI pair<double,int>
#define ISS istringstream
#define OSS ostringstream
#define gmin(a,b) { if ( b < a ) a = b; }
#define gmax(a,b) { if ( b > a ) a = b; }

int a, n, s[111], dd[111][1111], tc;
int dp[111][1111];

int main() {
	cin >> tc;

	for( int cas = 1; cas <= tc; cas++ ) {
		scanf( "%d%d", &a, &n );
		FOE( i, 1, n ) scanf( "%d", &s[i] );

		sort( s + 1, s + n + 1 );
		CLR( dp, -1 );
		dp[0][0] = a;

		for( int i = 1; i <= n; i++) {
			for( int j = 0; j < 1111; j++ ) {
				if ( dp[i - 1][j] >= 0 ) {
					dp[i][j + 1] = max( dp[i][j + 1], dp[i - 1][j] );
					if ( dp[i - 1][j] > 1 ) {
						int tmp = dp[i - 1][j], cnt = 0;
						while( tmp <= s[i] ) {
							tmp *= 2;
							tmp--;
							cnt++;
						}
						if ( j + cnt <= n ) dp[i][j + cnt] = max( dp[i][j + cnt], tmp + s[i] );
					}
				}
			}
		}

		int ans = -1;
		for( int i = 0; i < 1111; i++ ) {
			if ( ans == -1 && dp[n][i] >= 0 ) {
				ans = i;
			}
		}

		printf( "Case #%d: %d\n", cas, ans );
	}

	return 0;
}
