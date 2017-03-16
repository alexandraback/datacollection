#include <cstdio>
#include <cstring>

const int maxn = 205;
const double eps = 1e-10;

int data[maxn] , n , s;
double ans[maxn];

bool check( double key , int x ) {
	double tmp[maxn] , sc = data[x]+key*s;
	memset( tmp , 0 , sizeof(tmp) );
	for ( int i = 0; i < n; i++ ) {
		if ( i == x ) tmp[i] = key;
		else {
			if ( data[i] > sc ) continue;
			else tmp[i] = double(sc-data[i])/s;
		}
	}
	double ss = 0;
	for ( int i = 0; i < n; i++ ) ss += tmp[i];
	return ss > 1;
}

double solve( int x ) {
	double lower = 0 , upper = 1 , ret = 1;
	while ( upper-lower > eps ) {
		double mid = ( lower + upper ) * 0.5;
		if ( check(mid,x) ) {
			upper = mid;
			ret = mid;
		} else lower = mid;
	}
	return ret;
}

int main() {
	int cas;
	scanf( "%d" , &cas );
	for ( int t = 1; t <= cas; t++ ) {
		scanf( "%d" , &n );
		for ( int i = 0; i < n; i++ ) scanf( "%d" , &data[i] );
		s = 0;
		for ( int i = 0; i < n; i++ ) s += data[i];
		for ( int i = 0; i < n; i++ ) ans[i] = solve(i);
		printf( "Case #%d:" , t );
		for ( int i = 0; i < n; i++ ) printf( " %.6lf" , ans[i]*100 );
		printf( "\n" );
	}
	return 0;
}
