#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

const int MAXN = 59 ;

typedef long long LL ;

LL i , j , k , t , tt ;
LL b , m ;
LL e[MAXN][MAXN] , S , T , n ;
LL f[MAXN] ;

void Solve() {
	memset( e , 0 , sizeof(e) ) ;
	memset( f , 0 , sizeof(f) ) ;
	cin >> b >> m ;
	n = 2 ; e[1][2] = 1 ; f[1] = f[2] = 1 ;
	while ( f[n] < m ) {
		n ++ ;
		for ( int i = 1 ; i < n ; i ++ ) {
			e[i][n] = 1 ;
			f[n] += f[i] ;
		}
	}
	if ( n > b ) cout << "IMPOSSIBLE\n" ;
	else {
		cout << "POSSIBLE\n" ;
		tt = f[n] - m ;
		for ( int i = n-1 ; i >= 1 ; i -- ) if ( tt >= f[i] ) {
			tt -= f[i] ;
			e[i][n] = 0 ;
		}
		for ( int i = n ; i < b ; i ++ ) e[i][i+1] = 1 ;
		for ( int i = 1 ; i <= b ; i ++ ) {
			for ( int j = 1 ; j <= b ; j ++ )
				cout << e[i][j] ;
			cout << "\n" ;
		}
	}
}

int main() {
	int Test ; cin >> Test ;
	for ( int i = 1 ; i <= Test ; i ++ ) {
		cout << "Case #" << i << ": " ;
		Solve() ;
	}
}