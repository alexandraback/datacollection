#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int MAXR = 65;
const int MAXC = 65;
const char BOMB = '*';
const char START = 'c';
const char EMPTY = '.';

int r, c, m;
char field[MAXR][MAXC];
bool used[MAXR][MAXC];

bool unpack_mask( int mask ){
    int bombs = 0;
    for ( int i = 0; i < r && bombs <= m; ++i ){
        for ( int j = 0; j < c && bombs <= m; ++j ){
            if ( mask & ( 1 << (i*c + j) ) ){
                field[i][j] = BOMB;
                ++bombs;
            } else {
                field[i][j] = EMPTY;
            }
        }
    }

    return bombs == m;
}

int neightbour_bombs ( int i, int j ) {
    const int D = 8;
    const int DI[D] = { -1, -1, -1,  0,  0, +1, +1, +1 };
    const int DJ[D] = { -1,  0, +1, -1, +1, -1,  0, +1 };
    int result = 0;
    for ( int d = 0; d < D; ++d ){
        if ( i + DI[d] >= 0 && i + DI[d] < r && j + DJ[d] >= 0 && j + DJ[d] < c ){
            result += field[i+DI[d]][j+DJ[d]] == BOMB;
        }
    }
    return result;
}

bool check( int i0, int j0 ){
    queue < pair < int, int > > q;
    memset ( used, false, sizeof ( bool ) * MAXR * MAXC );
    used[i0][j0] = true;
    if ( neightbour_bombs ( i0, j0 ) == 0 ){
        q.push ( make_pair ( i0, j0 ) );
    }
    while ( !q.empty() ){
        static const int D = 8;
        static const int DI[D] = { -1, -1, -1,  0,  0, +1, +1, +1 };
        static const int DJ[D] = { -1,  0, +1, -1, +1, -1,  0, +1 };

        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        for ( int d = 0; d < D; ++d ){
            if ( i + DI[d] < 0 || i + DI[d] >= r || j + DJ[d] < 0 || j + DJ[d] >= c || used[i + DI[d]][j + DJ[d]] ){
                continue;
            }
            used[i + DI[d]][j + DJ[d]] = true;
            if ( neightbour_bombs ( i + DI[d], j + DJ[d] ) ){
                continue;
            }
            q.push ( make_pair ( i + DI[d], j + DJ[d] ) );
        }
    }

    for ( int i = 0; i < r; ++i ){
        for ( int j = 0; j < c; ++j ){
            if ( !used[i][j] && field[i][j] != BOMB ){
                return false;
            }
        }
    }
    return true;
}

int main(){

    freopen ( "C-small-attempt3.in", "r", stdin );
    freopen ( "C-small-attempt3.out", "w", stdout );

    int t;
    scanf ( "%d ", &t );
    for ( int testcase = 1; testcase <= t; ++testcase ){
        scanf ( "%d %d %d ", &r, &c, &m );
        bool success = false;
        for ( int mask = 0; !success && mask < (1 << (r*c)); ++mask ){
            if ( !unpack_mask( mask ) ){
                continue;
            }
            for ( int i = 0; i < r && !success; ++i ){
                for ( int j = 0; j < c && !success; ++j ){
                    if ( field[i][j] == EMPTY ){
                        field[i][j] = START;
                        if ( check( i, j ) ){
                            success = true;
                            break;
                        }
                        field[i][j] = EMPTY;
                    }
                }
            }
        }
        printf ( "Case #%d:\n", testcase );
        if ( !success ){
            printf ( "Impossible\n" );
            continue;
        }
        for ( int i = 0; i < r; ++i ){
            for ( int j = 0; j < c; ++j ){
                putchar ( field[i][j] );
            }
            putchar ( '\n' );
        }
    }

    return 0;
}
