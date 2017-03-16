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
char buf[30];
bool ispalin ( vlong num ) {
    sprintf ( buf, "%lld", num );
    int i, len = strlen ( buf ), j;
    for ( i = 0, j = len - 1; i < j; i++, j-- ) {
        if ( buf[i] != buf[j] ) return false;
    }
    return true;
}

vlong arr[10000010];
void init () {
    vlong i;
    for ( i = 1; i <= 10000000; i++ ) {
        if ( ispalin( i ) && ispalin( i * i ) ) arr[i] = 1;
        arr[i] += arr[i-1];
    }
}
int main ()
{
    init();
    freopen ( "C-large-1.in", "r", stdin );
    freopen ( "C-large-1.out", "w", stdout );

    int kase, count = 0;
    scanf ( "%d", &kase );

    while ( kase-- ) {
        vlong a, b;
        scanf ( "%lld %lld", &a, &b );
        //printf ( "%lld %lld\n", a, b );

        a = ceil ( sqrt ( a ) - eps );
        b = sqrt ( b ) + eps;

        //printf ( "%lld %lld\n", a, b );
        //printf ( "%lld %lld\n", arr[b], arr[a-1] );

        printf ( "Case #%d: %lld\n", ++count, arr[b] - arr[a-1] );
    }

    return 0;
}
