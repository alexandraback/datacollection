#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

const int dx[ 8 ] = { -1, -1, -1, 0, 0, 1, 1, 1 };
const int dy[ 8 ] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int N, M, K;

int table[ 13 ][ 13 ];

bool click( int x, int y ) {
    queue< pair<int, int> > Que;
    int cnt = 0;

    table[ x ][ y ] = -2;
    Que.push( make_pair( x, y ) );

    while( ! Que.empty() ) {
        pair<int, int> now = Que.front();
        Que.pop();
        cnt ++;

        bool check = false;
        for( int i = 0; i < 8; i ++ ) {
            int px = now.first + dx[ i ];
            int py = now.second + dy[ i ];
            if( table[ px ][ py ] == 1 ) {
                check = true;
            }
        }
        if( check ) {
            continue;
        }

        for( int i = 0; i < 8; i ++ ) {
            int px = now.first + dx[ i ];
            int py = now.second + dy[ i ];
            if( px < 1 || py < 1 || px > N || py > M || table[ px ][ py ] == -2 ) {
                continue;
            }
            table[ px ][ py ] = -2;
            Que.push( make_pair( px, py ) );
        }
    }
    for( int i = 1; i <= N; i ++ ) {
        for( int j = 1; j <= M; j ++ ) {
            if( table[ i ][ j ] == -2 ) {
                table[ i ][ j ] = 0;
            }
        }
    }
    if( cnt == N * M - K ) {
        table[ x ][ y ] = -1;
        return true;
    }
    return false;
}

bool check() {
    for( int i = 1; i <= N; i ++ ) {
        for( int j = 1; j <= M; j ++ ) {
            if( table[ i ][ j ] == 1 ) {
                continue;
            }
            if( click( i, j ) ) {
                return true;
            }
        }
    }
    return false;
}

bool back( int x, int y, int cnt ) {
    if( cnt > K ) {
        return false;
    }
    if( y == M + 1 ) {
        return back( x + 1, 1, cnt );
    }
    if( x == N + 1 ) {
        if( cnt != K ) {
            return false;
        }
        return check();
    }

    table[ x ][ y ] = 1;
    if( back( x, y + 1, cnt + 1 ) ) {
        return true;
    }
    table[ x ][ y ] = 0;
    if( back( x, y + 1, cnt ) ) {
        return true;
    }

    return false;
}

int main() {
    int T;
    scanf( "%d", &T );
    for( int tt = 1; tt <= T; tt ++ ) {
        scanf( "%d %d %d", &N, &M, &K );
        printf( "Case #%d:\n", tt );
        if( back( 1, 1, 0 ) ) {
            for( int i = 1; i <= N; i ++ ) {
                for( int j = 1; j <= M; j ++ ) {
                    if( table[ i ][ j ] == 1 ) {
                        printf( "*" );
                    } else if( table[ i ][ j ] == 0 ) {
                        printf( "." );
                    } else {
                        printf( "c" );
                    }
                }
                printf( "\n" );
            }
        } else {
            printf( "Impossible\n" );
        }
        memset( table, 0, sizeof( table ) );
    }
    return 0;
}
