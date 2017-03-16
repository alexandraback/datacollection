#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<iostream>
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
#define MAX 4

char board[MAX+5][MAX+5];

void performtest(){
    for( int i=0; i<MAX; i++ )
        scanf( "%s", board[i] );
/*
   for( int i=0; i<MAX; i++ )
        printf( "%s\n", board[i] );
*/

    for( int i=0; i<MAX; i++ ){
        if( ( board[i][0] == 'X' || board[i][0] == 'T' ) && ( board[i][1] == 'X' || board[i][1] == 'T' )
           && ( board[i][2] == 'X' || board[i][2] == 'T' ) && ( board[i][3] == 'X' || board[i][3] == 'T' ) ){
                printf( "X won\n" );
                return;
        }
        if( ( board[i][0] == 'O' || board[i][0] == 'T' ) && ( board[i][1] == 'O' || board[i][1] == 'T' )
           && ( board[i][2] == 'O' || board[i][2] == 'T' ) && ( board[i][3] == 'O' || board[i][3] == 'T' ) ){
                printf( "O won\n" );
                return;
        }
    }

    for( int j=0; j<MAX; j++ ){
        if( ( board[0][j] == 'X' || board[0][j] == 'T' ) && ( board[1][j] == 'X' || board[1][j] == 'T' )
           && ( board[2][j] == 'X' || board[2][j] == 'T' ) && ( board[3][j] == 'X' || board[3][j] == 'T' ) ){
                printf( "X won\n" );
                return;
        }
        if( ( board[0][j] == 'O' || board[0][j] == 'T' ) && ( board[1][j] == 'O' || board[1][j] == 'T' )
           && ( board[2][j] == 'O' || board[2][j] == 'T' ) && ( board[3][j] == 'O' || board[3][j] == 'T' ) ){
                printf( "O won\n" );
                return;
        }
    }

    if( ( board[0][0] == 'X' || board[0][0] == 'T' ) && ( board[1][1] == 'X' || board[1][1] == 'T' ) &&
        ( board[2][2] == 'X' || board[2][2] == 'T' ) && ( board[3][3] == 'X' || board[3][3] == 'T' ) ){
            printf( "X won\n" );
            return;
        }

    if( ( board[0][0] == 'O' || board[0][0] == 'T' ) && ( board[1][1] == 'O' || board[1][1] == 'T' ) &&
        ( board[2][2] == 'O' || board[2][2] == 'T' ) && ( board[3][3] == 'O' || board[3][3] == 'T' ) ){
            printf( "O won\n" );
            return;
        }

    if( ( board[0][3] == 'X' || board[0][3] == 'T' ) && ( board[1][2] == 'X' || board[1][2] == 'T' ) &&
        ( board[2][1] == 'X' || board[2][1] == 'T' ) && ( board[3][0] == 'X' || board[3][0] == 'T' ) ){
            printf( "X won\n" );
            return;
        }

    if( ( board[0][3] == 'O' || board[0][3] == 'T' ) && ( board[1][2] == 'O' || board[1][2] == 'T' ) &&
        ( board[2][1] == 'O' || board[2][1] == 'T' ) && ( board[3][0] == 'O' || board[3][0] == 'T' ) ){
            printf( "O won\n" );
            return;
        }

    for( int i=0; i<MAX; i++ )
        for( int j=0; j<MAX; j++ )
            if( board[i][j] == '.' ){
                printf( "Game has not completed\n" );
                return;
            }

    printf( "Draw\n" );
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
