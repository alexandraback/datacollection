#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

typedef long long LL ;

LL N ;
bool used[10] ;

void Bang( LL x ) {
	if ( x <= 9 ) used[x] = true ;
	else {
		Bang(x / 10) ;
		used[x % 10] = true ;
	}
}

bool OK() {
	for ( int i = 0 ; i < 10 ; i ++ ) if ( !used[i] ) return false ;
	return true ;
}

LL Solve() {
	for ( int i = 0 ; i < 10 ; i ++ ) used[i] = false ;
	for ( LL i = 1 ;; i ++ ) {
		Bang(N * i) ;
		if ( OK() ) return N * i ;
	}
}

int main() {
	freopen("A-large.in" , "r" , stdin) ; freopen("A-large.out" , "w" , stdout) ;
	int T ; cin >> T ;
	for ( int i = 1 ; i <= T ; i ++ ) {
		cin >> N ;
		LL ans ;
		if ( N == 0 )
			cout << "Case #" << i << ": INSOMNIA\n" ;
		else {
			ans = Solve() ;
			cout << "Case #" << i << ": " << ans << "\n" ;
		}
	}
}