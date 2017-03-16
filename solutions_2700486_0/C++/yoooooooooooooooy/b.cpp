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
#define ABS(a) ((a)<0?-(a):(a))
#define LL long long
#define PII pair<int,int>
#define PDI pair<double,int>
#define ISS istringstream
#define OSS ostringstream
#define gmin(a,b) { if ( b < a ) a = b; }
#define gmax(a,b) { if ( b > a ) a = b; }

int tc;
LL x, y, n;

double comp( int n, int k, int l ) {
	// compute 2^-n ( (n k) + (n k+1) + ... + (n n))
	// printf( "comp %d %d %d\n", n, k, l);
	long long den = 1, nu = 0;
	REP( i, n ) den *= 2;
	FOE( i, 0, n ) {
		if ( i >= k || ( n - i ) - l + i >= k )  {
			//printf( "%d %d\n", i, n );
			LL tmp = 1;
			FOE( j, 1, i ) {
				tmp *= n + 1 - j;
				tmp /= j;
			}
			nu += tmp;
		}
	}
	return (double) nu / den;
}

LL get( LL x, LL y ) {
	return ( ABS(x) + ABS(y) ) / 2;
}

LL getx( LL d ) {
	return 4 * ( d + 1 ) - 3;
}

LL getn( LL d ) {
	if ( d < 0 ) return 0;
	LL ans = 0;
	for( LL i = 0; i <= d; i++ ) ans += getx( i );
	return ans;
}

LL getl( LL x, LL y ) {
	return y + 1;
}

int main() {
	scanf( "%d", &tc );
	for( int cas = 1; cas <= tc; cas++ ) {
		scanf( "%lld%lld%lld", &n, &x, &y );
		LL d = get( x, y );
		double ans = 0.0;
		if ( n <= getn( d - 1 ) ) { 
			ans = 0.0;
		} else if ( n >= getn( d ) ) { 
			ans = 1.0;
		} else {
			LL k = getl( x, y );
			if ( k > 2 * d ) {
				ans = 0.0;
			} else {
				ans = comp( n - getn( d - 1 ), k, 2 * d );
			}
		}
		printf("Case #%d: %.9f\n", cas, ans );
	}
	return 0;
}
