#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

int N ;
double A[1009] , B[1009] ;
bool used[1009] ;

int main() {
    freopen("d.in" , "r" , stdin) ;
    //freopen("D.out", "w" , stdout) ;
    int __ ; cin >> __ ;
    for ( int _ = 1 ; _ <= __ ; _ ++ ) {
        cin >> N ;
        for ( int i = 1 ; i <= N ; i ++ ) cin >> A[i] ; sort(A+1,A+N+1) ;
        for ( int i = 1 ; i <= N ; i ++ ) cin >> B[i] ; sort(B+1,B+N+1) ;
        int ans1 = 0 , ans2 = 0 ;
        for ( int i = 1 ; i <= N ; i ++ ) used[i] = false ;
        int L = 1 , R = N ;
        for ( int i = N ; i >= 1 ; i -- ) ( A[R] > B[i] ) ? ( ans1 ++ , R -- ) : ( L ++ ) ;
        for ( int i = 1 ; i <= N ; i ++ ) used[i] = false ;
        for ( int i = 1 ; i <= N ; i ++ ) {
            int j ;
            for ( j = 1 ; j <= N ; j ++ ) if ( !used[j] && B[j] > A[i] ) break ;
            if ( j == N+1 ) for ( j = 1 ; j <= N ; j ++ ) if ( !used[j] ) break ;
            if ( B[j] <= A[i] ) ans2 ++ ;
            used[j] = true ;
        }
        cout << "Case #" << _ << ": " << ans1 << " " << ans2 << "\n" ;
    }
}
