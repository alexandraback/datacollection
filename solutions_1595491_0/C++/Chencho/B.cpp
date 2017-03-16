#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std ;

int caso() {
    int N, S, P ;
    int arr[105] ;
    int res = 0 ;

    scanf("%d%d%d", &N, &S, &P ) ;
    for( int i=0; i<N; i++ )
        scanf("%d", &arr[i] ) ;

    sort( arr, arr+N ) ;
    for( int i=N-1; i>=0; i-- ) {
        int Q ;
        if( S==0 || arr[i]<=1 || arr[i]%3==1 )
            Q = arr[i]/3 + (arr[i]%3!=0) ;
        else if( arr[i]%3==2 ) {
            if( arr[i]/3 + (arr[i]%3!=0) < P ) {
                Q = (arr[i]-2)/3 + 2 ;
                S -- ;
            }
            else {
                Q = arr[i]/3 + (arr[i]%3!=0) ;
            }
        }
        else {
            if( arr[i]/3 + (arr[i]%3!=0) < P ) {
                Q = (arr[i]-3)/3 + 2 ;
                S -- ;
            }
            else {
                Q = arr[i]/3 + (arr[i]%3!=0) ;
            }
        }
        if( Q>=P )
            res ++ ;
    }

    return res ;
}

int main() {
    freopen( "B.in", "r", stdin ) ;
    freopen( "B.out", "w", stdout ) ;

    int T ;

    scanf("%d", &T ) ;
    for( int i=0; i<T; i++ ) {
        printf("Case #%d: %d\n", i+1, caso() ) ;
    }

    return 0 ;
}
