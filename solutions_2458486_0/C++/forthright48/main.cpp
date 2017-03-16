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
vector < int > key;
int type[30], n;
vector < int > chest[30];

int check_bit ( int mask, int i ) {
    if ( mask & ( 1 << i ) ) return 1;
    else return 0;
}
int reset ( int mask, int i ) {
    return ( mask & ~( 1 << i ) );
}
int memo[1<<20], done[1<<20], cc = 1;
int path[1<<20];
int dp ( int mask ) {
    if ( mask == 0 ) return 1;
    if ( done[mask] == cc ) return memo[mask];

    //Find all the current keys
    vector < int > arr ( 210 );
    int i, j;
    for ( i = 0; i < key.size(); i++ ) arr[key[i]]++;

    for ( i = 0; i < n; i++ ) {
        if ( check_bit( mask, i ) == 0 ) {
            arr[type[i]]--;
            for ( j = 0; j < chest[i].size(); j++ ) {
                arr[chest[i][j]]++;
            }
        }
    }
    //Now open new chests
    int res = 0;
    for ( i = 0; i < n; i++ ) {
        if ( check_bit( mask, i ) == 1 && arr[type[i]] > 0 ) {
            res = dp ( reset ( mask, i ) );
            if ( res == 1 ) {
                path[mask] = reset ( mask, i );
                break;
            }
        }
    }
    done[mask] = cc;
    memo[mask] = res;
    return res;
}

void print ( int mask ) {
    if ( mask == 0 ) {
        nl;
        return;
    }
    int nmask = path[mask];
    int i;
    for ( i = 0; i < n; i++ ) {
        if ( check_bit( mask, i ) == 1 && check_bit( nmask, i ) == 0 ) {
            printf ( " %d", i + 1 );
            break;
        }
    }
    print ( nmask );
}

int main ()
{
    freopen ( "D-small-attempt0.in", "r", stdin );
    freopen ( "D-small-attempt0.out", "w", stdout );

    int kase, count = 0;
    scanf ( "%d", &kase );

    while ( kase-- ) {
        int k;
        scanf ( "%d %d", &k, &n );

        int i, temp;
        key.clear();
        for ( i = 0; i < n; i++ ) chest[i].clear();

        for ( i = 0; i < k; i++ ) {
            scanf ( "%d", &temp );
            key.pb ( temp );
        }

        for ( i = 0; i < n; i++ ) {
            scanf ( "%d", &type[i] );
            int size;
            scanf ( "%d", &size );
            while ( size-- ) {
                scanf ( "%d", &temp );
                chest[i].pb ( temp );
            }
        }

        int target = ( 1 << n ) - 1;
        int res = dp ( target );
        printf ( "Case #%d:", ++count );
        if ( res == 0 ) printf ( " IMPOSSIBLE\n" );
        else print ( target );

        cc++;
    }

    return 0;
}
