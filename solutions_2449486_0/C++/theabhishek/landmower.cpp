#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

typedef pair< string, int > P;
typedef pair< P, int > TRI;
#define first( a ) ( (a).first.first )
#define second( a ) ( (a).first.second )
#define third( a ) ( (a).second )
#define ceil( a, b ) ( (a)/(b) + ( (a)*(b) >= 0 ? ( (a)%(b) != 0 ) : 0 ) )
#define floor( a, b ) ( (a)/(b) - ( (a)*(b) < 0 ? ( (a)%(b) != 0 ) : 0 ) )
#define sqr( a ) ( (a)*(a) )
#define swap( a, b ) ( (a) = (a) + (b) - ( (b) = (a) ) )

#define INF 2000000000
#define MAX 100

int land[MAX+10][MAX+10];

bool check_horizontal( int r, int c, int M ){
    for( int j=0; j<M; j++ )
        if( land[r][j] > land[r][c] )
            return false;
    return true;
}

bool check_vertical( int r, int c, int N ){
    for( int i=0; i<N; i++ )
        if( land[i][c] > land[r][c] )
            return false;
    return true;
}

void performtest(){
    int N, M;
    scanf( "%d %d", &N, &M );
    for( int i=0; i<N; i++ )
        for( int j=0; j<M; j++ ){
            scanf( "%d", &land[i][j] );
        }

    for( int i=0; i<N; i++ )
        for( int j=0; j<M; j++ )
            if( !check_horizontal( i, j, M ) && !check_vertical( i, j, N ) ){
                printf( "NO\n" );
                return;
            }

    printf( "YES\n" );
}

int main(){
    int T;
    scanf( "%d", &T );
    for( int i=1; i<=T; i++ ){
        printf( "Case #%d: ", i );
        performtest();
    }
    return 0;
}
