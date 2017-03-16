#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

int X , N , M ;

bool Solve() {
    if ( (N*M) % X != 0 ) return true ;
    
    if ( X >= 7 ) return true ;
    if ( X == 1 ) return false ;
    if ( X == 2 ) return false ;
    if ( X == 3 ) {
        if ( N == 1 ) return true ;
        return false ;
    }
    if ( X == 4 ) {
        if ( N == 1 ) return true ;
        if ( N == 2 ) return true ;
        return false ;
    }
    // X = 5
    // X = 6
}

int main() {
    freopen("D-small-attempt1.in" , "r" , stdin) ;
    freopen("D-small-attempt1.out", "w" ,stdout) ;
    
    int Test ; cin >> Test ;
    
    for ( int i = 1 ; i <= Test ; i ++ ) {
        cin >> X >> N >> M ;
        if ( N > M ) swap( N , M ) ;
        if ( Solve() ) cout << "Case #" << i << ": RICHARD\n" ;
        else           cout << "Case #" << i << ": GABRIEL\n" ;
    }
}
