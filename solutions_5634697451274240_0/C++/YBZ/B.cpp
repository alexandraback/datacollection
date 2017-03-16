#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

string S ;

int Solve() {
	char o = '+' ;
	int N = S.size() ;
	int ans = 0 ;
	for ( int i = N-1 ; i >= 0 ; i -- ) {
		if ( S[i] == o ) continue ;
		else {
			ans ++ ;
			o = (o == '+' ? '-' : '+') ;
		}
	}
	return ans ;
}

int main() {
	freopen("B-small-attempt0.in" , "r" , stdin) ; freopen("B-small-attempt0.out" , "w" , stdout) ;
	int T ; cin >> T ;
	for ( int i = 1 ; i <= T ; i ++ ) {
		cin >> S ;
		cout << "Case #" << i << ": " << Solve() << "\n" ;
	}
}