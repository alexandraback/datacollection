#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;
#define lim 2000005

int carg[lim] ;

int dig( int pos ) {
    int pot = 1 ;
    for( ; pot*10<=pos; pot*=10 ) ;
    return pot ;
}

int sig( int pos, int pot ) {
    return (pos/10) + (pos%10)*pot ;
}

long long caso() {
    int A, B ;
    long long res = 0LL ;

    scanf("%d%d", &A, &B ) ;
    A = max( 10, A ) ;

    for( int i=A; i<=B; i++ )
        carg[i] = 0 ;
    for( int i=A; i<=B; i++ ) {
        res += carg[i] ;
        int pos = i, d=dig(i) ;
        do {
            pos = sig(pos,d) ;
            if( pos<=B )
                carg[pos] ++ ;
        } while( pos!=i ) ;
    }

    return res ;
}

int main() {
    freopen( "C.in", "r", stdin ) ;
    freopen( "C.out", "w", stdout ) ;

    int T ;

    scanf("%d", &T ) ;
    for( int i=1; i<=T; i++ )
        printf("Case #%d: %d\n", i, caso() ) ;

    return 0 ;
}
