#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

int A , B , C , K ;

int AB[13][13] , AC[13][13] , BC[13][13] ;
bool F[13][13][13] ;

void Solve() {
	for ( int i = 1 ; i <= A ; i ++ )
		for ( int j = 1 ; j <= B ; j ++ )
			AB[i][j] = 0 ;
	for ( int i = 1 ; i <= A ; i ++ )
		for ( int j = 1 ; j <= C ; j ++ )
			AC[i][j] = 0 ;
	for ( int i = 1 ; i <= B ; i ++ )
		for ( int j = 1 ; j <= C ; j ++ )
			BC[i][j] = 0 ;
	
	int cnt = 0 ;
	int k = 1 ;
	for ( int i = 1 ; i <= A ; i ++ )
		for ( int j = 1 ; j <= B ; j ++ )
			for ( int k = 1 ; k <= C ; k ++ )
				F[i][j][k] = false ;
	for ( int i = 1 ; i <= A ; i ++ ) {
		int k = i ;
		for ( int j = 1 ; j <= B ; j ++ ) {
			for ( int nowcnt = 0 ; nowcnt < min(C,K) ; nowcnt ++ ) {
				if ( AB[i][j] < K && AC[i][k] < K && BC[j][k] < K ) {
					F[i][j][k] = true ;
					cnt ++ ;
					AB[i][j] ++ ;
					AC[i][k] ++ ;
					BC[j][k] ++ ;
				} else {
					fprintf(stderr , "ERROR\n") ;
				}
				k ++ ;
				if ( k == C+1 ) k = 1 ;
			}
		}
	}
	cout << cnt << "\n" ;
	
	for ( int i = 1 ; i <= A ; i ++ )
		for ( int j = 1 ; j <= B ; j ++ )
			for ( int k = 1 ; k <= C ; k ++ )
				if ( F[i][j][k] )
					cout << i << " " << j << " " << k << "\n" ;
}

int main() {
	int Test ; cin >> Test ;
	for ( int i = 1 ; i <= Test ; i ++ ) {
		cin >> A >> B >> C >> K ;
		cout << "Case #" << i << ": " ;
		Solve() ;
	}
}