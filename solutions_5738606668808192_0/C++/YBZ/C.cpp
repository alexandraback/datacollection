#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

typedef long long LL ;

int N , J ;
int legi[11] ;

bool Prime(LL x , int base) {
	for ( LL fac = 2 ; fac * fac <= x ; fac ++ )
		if ( x % fac == 0 ) {
			legi[base] = fac ;
			return false ;
		}
	return true ;
}

void BiPrint(LL x) {
	if ( x >= 2 ) BiPrint(x / 2) ;
	cout << x % 2 ;
}

bool Check(LL ox) {
	for ( LL base = 2 ; base <= 10 ; base ++ ) {
		LL x = ox , y = 0 , b = 1 ;
		while ( x > 0 ) {
			y += b * (x % 2) ;
			b *= base ;
			x /= 2 ;
		}
		if ( Prime(y , base) ) return false ;
	}
	BiPrint(ox) ;
	for ( LL base = 2 ; base <= 10 ; base ++ ) cout << " " << legi[base] ;
	cout << "\n" ;
	return true ;
}

void Solve() {
	for ( LL i = (1<<(N-1))+1 ; J >= 1 && i < (1<<N) ; i += 2 ) 
		if ( Check(i) )
			J -- ;
}

int main() {
	int Test ; cin >> Test ;
	for ( int i = 1 ; i <= Test ; i ++ ) {
		cin >> N >> J ;
		cout << "Case #" << i << ":\n" ;
		Solve() ;
	}
}