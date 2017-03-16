#include <iostream>

using namespace std;

bool Solve(char board[51][51], int R, int C, int M, int d = 0)
{
    if ( R*C <= M || M < 0 || d && C<3 ) {
        return false;
    }

    for ( int r = 0; r < R; r++ ) {
        for ( int c = 0; c < C; c++ ) {
            board[r][c] = '*';
        }
    }

    int S = R*C-M;
    if ( C == 1 ) {
        for ( int i = 0; i < S; i++ ) {
            board[i][0] = '.';
        }
    } else {
        if ( S == 1 ) {

        } else if ( S%2 == 0 && 2 < S && S <= 2*R ) {
            for ( int r = 0; r < S/2; r++ ) {
                board[r][0] = board[r][1] = '.';
            }
        } else {
            if ( S/C < 2 ) {
                return Solve( board, R, C-1, M-R, d+1 );
            }
            if ( S % C == 1 ) {
                if ( C == 2 ) {
                    return false;
                }
                if ( S/C == 2 ) {
                    return Solve( board, R, C-1, M-R, d+1 );
                }
                for ( int r = 0; r < S/C; r++ ) {
                    for ( int c = 0; c < C; c++ ) {
                        board[r][c] = '.';
                    }
                }
                board[S/C-1][C-1] = '*';
                board[S/C][0] = board[S/C][1] = '.';
            } else {
                for ( int r = 0; r < S/C; r++ ) {
                    for ( int c = 0; c < C; c++ ) {
                        board[r][c] = '.';
                    }
                }
                for ( int c = 0; c < S%C; c++ ) {
                    board[S/C][c] = '.';
                }
            }
        }
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    for ( int t = 1; t <= T; t++ ) {
        printf( "Case #%d:\n", t );
        int R, C, M;
        cin >> R >> C >> M;

        bool trans = false;
        if ( R < C ) {
            trans = true;
            swap(R, C);
        }
        char board[51][51] = {0};
        if ( Solve(board, R, C, M) ) {
            board[0][0] = 'c';
            if ( trans ) {
                for ( int c = 0; c < C; c++ ) {
                    for ( int r = 0; r < R; r++ ) {
                        cout << board[r][c];
                    }
                    cout << endl;
                }
            } else {
                for ( int r = 0; r < R; r++ ) {
                    for ( int c = 0; c < C; c++ ) {
                        cout << board[r][c];
                    }
                    cout << endl;
                }
            }
        } else {
            puts("Impossible");
        }
    }
    return 0;
}