/***********Template Starts Here***********/
#pragma comment (linker,"/STACK:16777216")
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <deque>
#include <functional>
#include <string>
#include <iostream>
#include <cctype>

#define pb push_back
#define nl puts ("")
#define sp printf ( " " )
#define phl printf ( "hello\n" )
#define all(c) (c).begin(),(c).end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define sz(a) int((a).size())

typedef long long vlong;
typedef unsigned long long uvlong;

const vlong inf = 2147383647;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;
const vlong maxint = 2147483647;
const vlong minint = -2147483648;

using namespace std;

/***********Template Ends Here***********/

char grid[4][6];
bool flag, flag2;
int ti, tj;

bool check ( char c ) {
    if ( flag ) grid[ti][tj] = c;

    int i;
    //Check row
    for ( i = 0; i < 4; i++ ) {
        if ( grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2] && grid[i][2] == grid[i][3] && grid[i][3] == c ) return true;
        if ( grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i] && grid[2][i] == grid[3][i] && grid[3][i] == c ) return true;
    }

    if ( grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] && grid[2][2] == grid[3][3] && grid[3][3] == c ) return true;
    if ( grid[0][3] == grid[1][2] && grid[1][2] == grid[2][1] && grid[2][1] == grid[3][0] && grid[3][0] == c ) return true;
    return false;
}

int main ()
{
    freopen ( "A-small-attempt0.in", "r", stdin );
    freopen ( "A-small-attempt0.out", "w", stdout );
    int kase, count = 0;
    scanf ( "%d", &kase );

    while ( kase-- ) {

        int i, j;
        for ( i = 0; i < 4; i++ ) {
            scanf ( "%s", &grid[i][0] );
        }
        flag = false;
        flag2 = false;
        for ( i = 0; i < 4; i++ ) {
            for ( j = 0; j < 4; j++ ) {
                if ( grid[i][j] == 'T' ) {
                    flag = true;
                    ti = i; tj = j;
                }
                if ( grid[i][j] == '.' ) flag2 = true;
            }
        }

        printf ( "Case #%d: ", ++count );

        if ( check ( 'X' ) ) printf ( "X won\n" );
        else if ( check ( 'O' ) ) printf ( "O won\n" );
        else if ( flag2 ) printf ( "Game has not completed\n" );
        else printf ( "Draw\n" );
    }

    return 0;
}
