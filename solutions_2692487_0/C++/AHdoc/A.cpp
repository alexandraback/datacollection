#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;

typedef long long LL ;

LL A , N , Ans , Cnt ;
LL Mx[1000009] ;

void Init() {
	cin >> A >> N ;
	for ( LL i = 1 ; i <= N ; i ++ ) cin >> Mx[i] ;
	sort(Mx+1 , Mx+N+1) ;
}

void Solve() {
	Ans = N ;
	Cnt = 0 ;
	for ( LL i = 1 ; i <= N ; i ++ ) {
		if ( Cnt + (N+1-i) < Ans ) Ans = Cnt + (N+1-i) ;
		if ( Mx[i] < A ) { A += Mx[i] ; continue ; }
		if ( A-1 == 0 ) { Cnt += N ; break ; }
		for ( ;; ) {
			A = A+A-1 ;
			Cnt ++ ;
			if ( A > Mx[i] ) break ;
		}
		A += Mx[i] ;
	}
	if ( Cnt < Ans ) Ans = Cnt ;
}

int main() {
	freopen("A.in" , "r" , stdin) ;
	freopen("A.out", "w" , stdout) ;
	LL Test ; cin >> Test ;
	for ( LL i = 1 ; i <= Test ; i ++ ) {
		Init() ;
		Solve() ;
		cout << "Case #" << i << ": " << Ans << "\n" ;
	}
}



