#include <iostream>

#define MAX_SIZE 500

using namespace std;

int main()
{
    int T, N, M;
    int value[ MAX_SIZE ][ MAX_SIZE ];
    bool vertical[ MAX_SIZE ][ MAX_SIZE ];
    bool horizontal[ MAX_SIZE ][ MAX_SIZE ];

    int max_row[ MAX_SIZE ];
    int max_col[ MAX_SIZE ];

    cin >> T;

    for ( int t = 0; t < T; t++ )
    {
        bool possible = true;

        cin >> N >> M;

        for ( int j = 0; j < M; j++ )
        {
            max_col[ j ] = 0;
        }

        for ( int i = 0; i < N; i++ )
        {
            max_row[ i ] = 0;
            for ( int j = 0; j < M; j++ )
            {
                cin >> value[ i ][ j ];
                vertical[ i ][ j ] = true;
                horizontal[ i ][ j ] = true;

                if ( value[ i ][ j ] > max_row[ i ] ) max_row[ i ] = value[ i ][ j ];
                if ( value[ i ][ j ] > max_col[ j ] ) max_col[ j ] = value[ i ][ j ];
            }
        }

        for ( int j = 0; j < M; j++ )
        {
            if ( value[ 0 ][ j ] < max_row[ 0 ] ) horizontal[ 0 ][ j ] = false;
            if ( value[ 0 ][ j ] < max_col[ j ] ) vertical[ 0 ][ j ] = false;

            if ( value[ N-1 ][ j ] < max_row[ N-1 ] ) horizontal[ N-1 ][ j ] = false;
            if ( value[ N-1 ][ j ] < max_col[ j ] ) vertical[ N-1 ][ j ] = false;

            if ( !horizontal[ 0 ][ j ] and !vertical[ 0 ][ j ] ) possible = false;
            if ( !horizontal[ N-1 ][ j ] and !vertical[ N-1 ][ j ] ) possible = false;
        }

        for ( int i = 0; i < N; i++ )
        {
            if ( value[ i ][ 0 ] < max_row[ i ] ) horizontal[ i ][ 0 ] = false;
            if ( value[ i ][ 0 ] < max_col[ 0 ] ) vertical[ i ][ 0 ] = false;

            if ( value[ i ][ M-1 ] < max_row[ i ] ) horizontal[ i ][ M-1 ] = false;
            if ( value[ i ][ M-1 ] < max_col[ M-1 ] ) vertical[ i ][ M-1 ] = false;

            if ( !horizontal[ i ][ 0 ] and !vertical[ i ][ 0 ] ) possible = false;
            if ( !horizontal[ i ][ M-1 ] and !vertical[ i ][ M-1 ] ) possible = false;
        }

        for ( int i = 1; i < N-1; i++ )
        {
            for ( int j = 1; j < M-1; j++ )
            {
                if ( value[ i ][ j ] >= max_row[ i ] )
                {
                    horizontal[ i ][ j ] = true;
                }
                else
                {
                    horizontal[ i ][ j ] = false;
                    if ( value[ i ][ j ] >= max_col[ j ] )
                    {
                        vertical[ i ][ j ] = true;
                    }
                    else
                    {
                        vertical[ i ][ j ] = false;
                        possible = false;
                    }
                }
            }
        }

        cout << "Case #" << t+1 << ": " << ( possible ? "YES" : "NO" ) << endl;
    }
    return 0;
}
