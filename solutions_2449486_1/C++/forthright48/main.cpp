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
int arr[200][200], temp[200][200];
int mxrow[200];
int mxcol[200];
int row, col;
void mowrow ( int r, int h ) {
    int j;
    for ( j = 0; j < col; j++ ){
        if ( temp[r][j] > h ) temp[r][j] = h;
    }
}
void mowcol ( int c, int h ) {
    int i;
    for ( i = 0; i < row; i++ ) {
        if ( temp[i][c] > h ) temp[i][c] = h;
    }
}

int main ()
{
    freopen ( "B-large.in", "r", stdin );
    freopen ( "B-large.out", "w", stdout );
    int kase, count = 0;
    scanf ( "%d", &kase );
    while ( kase-- ) {
        memset ( mxrow, 0, sizeof mxrow );
        memset ( mxcol, 0, sizeof mxcol );

        scanf ( "%d %d", &row, &col );

        int i, j;

        for ( i = 0; i < row; i++ ) {
            for ( j = 0; j < col; j++ ) {
                scanf ( "%d", &arr[i][j] );
                if ( arr[i][j] > mxrow[i] ) mxrow[i] = arr[i][j];
                if ( arr[i][j] > mxcol[j] ) mxcol[j] = arr[i][j];
            }
        }

        for ( i = 0; i < row; i++ ) for ( j = 0; j < col; j++ ) temp[i][j] = 100;

        bool pos = true;
        for ( i = 0; i < row; i++ ) {
            for ( j = 0; j < col; j++ ) {
                if ( temp[i][j] == arr[i][j] ) continue;
                //Try to mow row wise
                if ( mxrow[i] == arr[i][j] ) mowrow ( i, arr[i][j] );
                else if ( mxcol[j] == arr[i][j] ) mowcol ( j, arr[i][j] );
                else {
                    pos = false;
                    break;
                }
            }
            if ( pos == false ) break;
        }
        printf ( "Case #%d: ", ++count );
        if ( pos ) printf ( "YES\n" );
        else printf ( "NO\n" );
    }

    return 0;
}
