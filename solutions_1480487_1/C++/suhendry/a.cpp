#include <cstdio>
#include <cmath>
#include <numeric>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int (i)=0,_n=(n);(i)<_n;(i)++)
#define FOR(i,a,b) for(int (i)=(a),_n=(b);(i)<=_n;(i)++)

const double eps = 1E-10;

int n, x;
int s[205];

bool safe(int p, double y) {
	double val = s[p] + x * y;
	double r = 1 - y;
	REP(i,n) if ( i != p ) r -= max(0.0,(val - s[i]) / x);	
	return r < eps;
}

int main()
{
	int T;
	scanf( "%d", &T );
	FOR(tcase,1,T) {
		printf( "Case #%d:", tcase );
		
		scanf( "%d", &n );
		REP(i,n) scanf( "%d", &s[i] );
		
		x = accumulate(s,s+n,0);
		
		REP(i,n) {
			double ans = 1.0, L = 0.0, R = 2.0;
			while ( fabs(L-R) > eps ) {
				double mid = (L + R) / 2;
				if ( safe(i,mid) ) ans = mid, R = mid;
				else L = mid;
			}
			cout << " " << fixed << setprecision(7) << 100 * ans;
		}

		puts("");

	}
	return 0;
}
