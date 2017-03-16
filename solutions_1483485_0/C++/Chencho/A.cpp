#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std ;
#define lim 10000

char mapa[lim] ;

int main() {
    freopen( "A.in", "r", stdin ) ;
    freopen( "A.out", "w", stdout ) ;

    int N, T ;
    char S[lim] ;

    mapa[' '] = ' ' ;
    mapa['a'] = 'y' ;
    mapa['b'] = 'h' ;
    mapa['c'] = 'e' ;
    mapa['d'] = 's' ;
    mapa['e'] = 'o' ;
    mapa['f'] = 'c' ;
    mapa['g'] = 'v' ;
    mapa['h'] = 'x' ;
    mapa['i'] = 'd' ;
    mapa['j'] = 'u' ;
    mapa['k'] = 'i' ;
    mapa['l'] = 'g' ;
    mapa['m'] = 'l' ;
    mapa['n'] = 'b' ;
    mapa['o'] = 'k' ;
    mapa['p'] = 'r' ;
    mapa['q'] = 'z' ;
    mapa['r'] = 't' ;
    mapa['s'] = 'n' ;
    mapa['t'] = 'w' ;
    mapa['u'] = 'j' ;
    mapa['v'] = 'p' ;
    mapa['w'] = 'f' ;
    mapa['x'] = 'm' ;
    mapa['y'] = 'a' ;
    mapa['z'] = 'q' ;

    scanf("%d", &T ) ;
    gets(S) ;
    for( int i=0; i<T; i++ ) {
        gets(S) ;
        N = strlen(S) ;
        for( int j=0; j<N; j++ )
            S[j] = mapa[S[j]] ;
        printf("Case #%d: %s\n", i+1, S ) ;
    }



    return 0 ;
}
