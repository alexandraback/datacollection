#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

typedef long long LL ;

int N , J ;
LL legi[11] ;

LL Power(LL x , LL t , LL mm) {
	if ( t == 0 ) return 1LL ;
	if ( t == 1 ) return x ;
	if ( t % 2 == 0 ) {
		LL tmp = Power(x , t/2 , mm) ;
		return (tmp * tmp) % mm ;
	} else {
		LL tmp = Power(x , t-1 , mm) ;
		return (tmp * x) % mm ;
	}
}

bool Prime(LL x , LL base) {
	for ( LL fac = 2 ; fac * fac <= x ; fac ++ )
		if ( (x % fac + Power(base , 31 , fac)) % fac == 0 ) {
			legi[base] = fac ;
			return false ;
		}
	return true ;
}

void BiPrint(int d , LL x) {
	if ( d >= 1 ) {
		BiPrint(d-1 , x / 2) ;
		cout << x % 2 ;
	}
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
	cout << "1000000000000000" ;
	BiPrint(16 , ox) ;
	for ( LL base = 2 ; base <= 10 ; base ++ ) cout << " " << legi[base] ;
	cout << "\n" ;
	return true ;
}

void Solve() {
	for ( LL i = 1LL ; J >= 1 && i < (1LL<<16) ; i += 2LL )
		if ( Check(i) )
			J -- ;
}

int main() {
	freopen("C-large.out" , "w" , stdout) ;
	// N = 32 , J = 500 ;
	J = 500 ;
	cout << "Case #1:\n" ;
	Solve() ;
}