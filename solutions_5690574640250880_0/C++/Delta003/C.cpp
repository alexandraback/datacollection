#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int dx[] = { 1, 1, 1, -1, -1, -1, 0, 0 };
const int dy[] = { 1, 0, -1, 1, 0, -1, 1, -1 };
const int maxn = 50 + 5;

int rows, cols, mines, cases, sol_i, sol_j;
bool no_mine[ maxn ][ maxn ], mark[ maxn ][ maxn ], sol;

bool in( int x, int y )
{
    if ( x < 0 || x >= rows ) return false;
    if ( y < 0 || y >= cols ) return false;
    return true;
}

bool touch_mine( int x, int y )
{
    for ( int i = 0; i < 8; i++ )
        if ( in( x + dx[ i ], y + dy[ i ] ) && ! no_mine[ x + dx[ i ] ][ y + dy[ i ] ] ) return true;
    return false;
}

void dfs( int x, int y )
{
    mark[ x ][ y ] = true;
    for ( int i = 0; i < 8; i++ )
        if ( in( x + dx[ i ], y + dy[ i ] ) &&
             ! mark[ x + dx[ i ] ][ y + dy[ i ] ] &&
             no_mine[ x + dx[ i ] ][ y + dy[ i ] ] )
        {
            if ( touch_mine( x + dx[ i ], y + dy[ i ] ) ) mark[ x + dx[ i ] ][ y + dy[ i ] ] = true;
            else dfs( x + dx[ i ], y + dy[ i ] );
        }
}

void solve( int curr, int whites, bool placed )
{
    if ( whites == 0 )
    {
        int temp_x = -1, temp_y;
        for ( int i = 0; i < rows; i++ )
            if ( no_mine[ i ][ 0 ] && ! touch_mine( i, 0 ) )
            {
                temp_x = i;
                temp_y = 0;
                break;
            }
        if ( temp_x == -1 ) return;
        memset( mark, false, sizeof( mark ) );
        dfs( temp_x, temp_y );
        bool found_sol = true;
        for ( int i = 0; i < rows; i++ )
        {
            int j = 0;
            while ( no_mine[ i ][ j ] )
            {
                if ( ! mark[ i ][ j ] )
                {
                    found_sol = false;
                    break;
                }
                j++;
            }
            if ( ! found_sol ) break;
        }
        if ( found_sol )
        {
            sol = true;
            sol_i = temp_x;
            sol_j = temp_y;
        }
        return;
    }
    if ( curr == rows && whites ) return;
    if ( ! placed ) solve( curr + 1, whites, false );
    if ( sol ) return;
    for ( int i = 0; i < min( whites, cols ); i++ )
    {
        no_mine[ curr ][ i ] = true;
        solve( curr + 1, whites - i - 1, true );
        if ( sol ) return;
    }
    for ( int i = 0; i < min( whites, cols ); i++ ) no_mine[ curr ][ i ] = false;
}

void solve_special()
{
    printf( "c" );
    for ( int i = 1; i < cols; i++ ) printf( "*" );
    printf( "\n" );
    for ( int i = 1; i < rows; i++ )
    {
        for ( int j = 0; j < cols; j++ ) printf( "*" );
        printf( "\n" );
    }
}

int main()
{
    freopen( "C.in", "r", stdin );
    freopen( "C.out", "w", stdout );
    scanf( "%d", &cases );
    for ( int k = 1; k <= cases; k++ )
    {
        scanf( "%d %d %d", &rows, &cols, &mines );
        printf( "Case #%d:\n", k );
        if ( mines == rows * cols - 1 )
        {
            solve_special();
            continue;
        }
        sol = false;
        memset( no_mine, false, sizeof( no_mine ) );
        solve( 0, rows * cols - mines, false );
        if ( ! sol ) printf( "Impossible\n" );
        else
            for ( int i = 0; i < rows; i++ )
            {
                for ( int j = 0; j < cols; j++ )
                    if ( i == sol_i && j == sol_j ) printf( "c" );
                    else if ( no_mine[ i ][ j ] ) printf( "." );
                    else printf( "*" );
                printf( "\n" );
            }
    }
    return 0;
}
