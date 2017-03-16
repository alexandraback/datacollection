#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

int X , N , M ;

bool Solve() {
    if ( (N*M) % X != 0 ) return true ;
    if ( X >= 7 ) return true ;
    if ( X == 1 || X == 2 ) return false ;
    if ( X == 3 ) {
        if ( N == 1 ) return true ;
        return false ;
    }
    if ( X == 4 ) {
        if ( N == 1 || N == 2 ) return true ;
        return false ;
    }
    if ( X == 5 ) {
        if ( N == 1 || N == 2 ) return true ;
        if ( N == 3 ) {
            int U = (M*N) / 5 ;
            if ( U < 6 ) return true ; else return false ;
        }
        return false ;
    }
    if ( X == 6 ) {
        if ( N == 1 ) return true ;
        if ( N == 2 ) return true ;
        if ( N == 3 ) return true ;
        return false ;
    }
}

int main() {
    //freopen("D-small-attempt1.in" , "r" , stdin) ; freopen("D-small-attempt1.out", "w" ,stdout) ;
    freopen("D-large.in" , "r" , stdin) ; freopen("D-large.out", "w" ,stdout) ;
    
    int Test ; cin >> Test ;
    
    for ( int i = 1 ; i <= Test ; i ++ ) {
        cin >> X >> N >> M ;
        if ( N > M ) swap( N , M ) ;
        if ( Solve() ) cout << "Case #" << i << ": RICHARD\n" ;
        else           cout << "Case #" << i << ": GABRIEL\n" ;
    }
}
