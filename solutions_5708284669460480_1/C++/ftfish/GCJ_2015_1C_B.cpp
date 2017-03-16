#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;

int N , M , K ;
string S , T ;
int Cnt[26] , P[109] ;
double Pro[26] ;
char B[109] ;
double F[109][109] , G[109][109] ;
bool used[26] ;

int Init() {
    for ( int i = 0 ; i < 26 ; i ++ ) Cnt[i] = 0 ;
    for ( int i = 1 ; i <= N ; i ++ ) Cnt[S[i-1]-'A'] ++ ;
    for ( int i = 0 ; i < 26 ; i ++ ) Pro[i] = (double)Cnt[i] / (double)N ;

    for ( int i = 1 ; i <= M ; i ++ ) B[i] = T[i-1] ;

    P[0] = 0 ;
    P[1] = 0 ;
    for ( int i = 2 , j = 0 ; i <= M ; i ++ ) {
        while ( B[i] != B[j+1] && j > 0 ) j = P[j] ;
        if ( B[j+1] == B[i] ) j ++ ;
        P[i] = j ;
        //cout << P[i] << " " ;
    }

    for ( int i = 1 ; i <= M ; i ++ ) if ( Cnt[B[i]-'A'] == 0 ) return 0 ;
    return 1 + (K-M) / (M-P[M]) ;
}

double DP() {
    for ( int i = 0 ; i <= K ; i ++ )
        for ( int j = 0 ; j <= M ; j ++ ) {
            F[i][j] = 0.0 ;
            G[i][j] = 0.0 ;
        }
    F[0][0] = 1.0 ;
    for ( int i = 0 ; i < K ; i ++ ) {
        for ( int j = 0 ; j <= M ; j ++ ) {
            if ( F[i][j] == 0.0 ) G[i][j] = 0.0 ;
            else                  G[i][j] /= F[i][j] ;
            //cout << "F[" << i << "][" << j << "]=" << F[i][j] << "   " << G[i][j] << "\n" ;
            for ( int l = 0 ; l < 26 ; l ++ ) used[l] = false ;
            int jj = j ;
            if ( jj == M )
                jj = P[jj] ;
            for (;;) {
                if ( !used[B[jj+1]-'A'] ) {
                    F[i+1][jj+1] += F[i][j] * Pro[B[jj+1]-'A'] ;

                    //cout << i << " " << j << " " << jj << " " << Pro[B[jj+1]-'A'] << "\n" ;

                    if ( jj+1 == M ) G[i+1][jj+1] += (G[i][j] + 1.0) * F[i][j] * Pro[B[jj+1]-'A'] ;
                    else             G[i+1][jj+1] += (G[i][j] + 0.0) * F[i][j] * Pro[B[jj+1]-'A'] ;
                }
                used[B[jj+1]-'A'] = true ;
                if ( jj == 0 ) {
                    double u = 0.0 ;
                    for ( int l = 0 ; l < 26 ; l ++ )
                        if ( !used[l] )
                            u += Pro[l] ;
                    F[i+1][0] += F[i][j] * u ;
                    G[i+1][0] += G[i][j] * F[i][j] * u ;
                    break ;
                } else
                    jj = P[jj] ;
            }
        }
    }
    for ( int j = 0 , i = K ; j <= M ; j ++ ) {
        if ( F[i][j] == 0.0 ) G[i][j] = 0.0 ;
        else                  G[i][j] /= F[i][j] ;
        //cout << "F[" << i << "][" << j << "]=" << F[i][j] << "   " << G[i][j] << "\n" ;
    }

    double ans = 0.0 ;
    for ( int j = 0 ; j <= M ; j ++ ) ans += F[K][j] * G[K][j] ;
    return ans ;
}

int main() {
//    freopen("B.in" , "r" , stdin) ;
//    freopen("B.out", "w" ,stdout) ;

    cout.precision(12) ;

    int Test ; cin >> Test ;
    for ( int i = 1 ; i <= Test ; i ++ ) {
        cin >> N >> M >> K ;
        cin >> S >> T ;

        double Need = (double)Init() ;
        //cout << fixed << "Need=" << Need << "\n" ;

        double Pay  = DP() ;

        cout << "Case #" << i << ": " << fixed << Need-Pay << "\n" ;
    }
}
