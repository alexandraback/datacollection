#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

int N , M ;
int A[109][109] ;
int Mi[109] , Mj[109] ;

void Init() {
	cin >> N >> M ;
	for ( int i = 1 ; i <= N ; i ++ )
		for ( int j = 1 ; j <= M ; j ++ )
			cin >> A[i][j] ;
}

string Solve() {
	for ( int i = 1 ; i <= N ; i ++ ) {
		Mi[i] = A[i][1] ;
		for ( int j = 1 ; j <= M ; j ++ ) Mi[i] = max(Mi[i] , A[i][j]) ;
	}
	for ( int j = 1 ; j <= M ; j ++ ) {
		Mj[j] = A[1][j] ;
		for ( int i = 1 ; i <= N ; i ++ ) Mj[j] = max(Mj[j] , A[i][j]) ;
	}
	for ( int i = 1 ; i <= N ; i ++ )
		for ( int j = 1 ; j <= M ; j ++ )
			if ( A[i][j] >= Mi[i] || A[i][j] >= Mj[j] ) ;
			else return "NO" ;
	return "YES" ;
}

int main() {
	freopen( "B.in" , "r" , stdin ) ;
	freopen( "B.out", "w" , stdout) ;
	
	int Test ; cin >> Test ;
	for ( int i = 1 ; i <= Test ; i ++ ) {
		Init() ;
		cout << "Case #" << i << ": " << Solve() << "\n" ;
	}
}
