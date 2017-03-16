#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 100005;

double a[maxn] , p[maxn] , sum[maxn] , ans , t;
int n , m;

void init() {
	scanf( "%d%d" , &n , &m );
	for ( int i = 1; i <= n; i++ ) scanf( "%lf" , &p[i] );
	double s = 1;
	for ( int i = 1; i <= n; i++ ) {
		a[i] = s * (1-p[i]);
		s *= p[i];
	}
	t = s;
	sum[n] = a[n];
	for ( int i = n-1; i >= 0; i-- ) {
		sum[i] = sum[i+1] + a[i];
	}
	double s1 = s*(m-n+1) , s2 = (1-s)*(m-n+1+m+1);
	ans = s1+s2;
}

void work( int cas ) {
	ans = min( ans , double(m+2) );
	for ( int i = 1; i <= n; i++ ) {
		double s = (sum[n-i+1]+t)*(i+m-n+i+1) + (sum[1]-sum[n-i+1])*(i+m-n+i+1+m+1); 
		ans = min( ans , s );
	}
	printf( "Case #%d: %.6lf\n" , cas , ans );
}

int main() {
	int cas;
	scanf( "%d" , &cas );
	for ( int i = 1; i <= cas; i++ ) {
		init();
		work(i);
	}
	return 0;
}
