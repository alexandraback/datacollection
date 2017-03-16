#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

typedef long long LL ;

LL K , C , S ;

void Solve() {
	for ( int i = 1 ; i <= K ; ) {
		int j = i + C - 1 , l = 0 ;
		if ( j > K ) { l = j - K ; j = K ; }
		
		LL ans = 0 ;
		for ( int k = i ; k <= j ; k ++ )
			ans = ans * K + (LL)k - 1 ;
		
		while ( l -- ) ans = ans * K ;
		
		ans ++ ;
		cout << " " << ans ;
		
		i = j + 1 ;
	}
	cout << "\n" ;
}

int main() {
	int Test ; cin >> Test ;
	for ( int i = 1 ; i <= Test ; i ++ ) {
		cin >> K >> C >> S ;
		cout << "Case #" << i << ":" ;
		if ( C * S < K ) cout << " IMPOSSIBLE\n" ;
		else             Solve() ;
	}
}