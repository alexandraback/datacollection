#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

int N , M , Need ;
int F[100][100][100] ;

void Ref( int i2 , int j2 , int i , int j , int k ) {
    if ( j2 <= 0 || j2 > M ) return ;
    if ( j2 == 1 ) {
        if ( F[i2][j2][k+1] < F[i][j][k]+1 ) F[i2][j2][k+1] = F[i][j][k] + 1 ;
    } else {
        if ( F[i2][j2][k+2] < F[i][j][k]+j2 ) F[i2][j2][k+2] = F[i][j][k] + j2 ;
    }
}

int DP() {
    for ( int i = 1 ; i <= N ; i ++ )
        for ( int j = 1 ; j <= M ; j ++ )
            for ( int k = 1 ; k <= N+N+M+M ; k ++ )
                F[i][j][k] = -1 ;
    for ( int i = 1 ; i <= M ; i ++ )
        F[1][i][i] = i ;
    for ( int i = 1 ; i < N ; i ++ )
        for ( int j = 1 ; j <= M ; j ++ )
            for ( int k = 1 ; k <= N+N+M+M ; k ++ ) if ( F[i][j][k] != -1 ) {
                Ref(i+1,j,i,j,k) ;
                Ref(i+1,j-1,i,j,k) ;
                Ref(i+1,j-2,i,j,k) ;
                Ref(i+1,j+1,i,j,k) ;
                Ref(i+1,j+2,i,j,k) ;
            }
    int ans = N*M ;
    for ( int i = 1 ; i <= N ; i ++ )
        for ( int j = 1 ; j <= M ; j ++ )
            for ( int k = 1 ; k <= N+N+M+M ; k ++ ) {
                if ( F[i][j][k] >= Need ) {
                    if ( k + ( j > 2 ? j - 2 : 0 ) < ans ) ans = k + ( j > 2 ? j - 2 : 0 ) ;
                } else {
                    if ( k + ( j > 2 ? j - 2 : 0 ) + (Need-F[i][j][k]) < ans ) ans = k + (Need-F[i][j][k]) + ( j > 2 ? j - 2 : 0 ) ;
                }
            }
    return ans ;
}

int main() {
    freopen("C.in","r",stdin) ;
    freopen("C.out","w",stdout) ;
    int Test ; cin >> Test ;
    for ( int i = 1 ; i <= Test ; i ++ ) {
        cin >> N >> M >> Need ;
        cout << "Case #" << i << ": " << DP() << "\n" ;
    }
}
