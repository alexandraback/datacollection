#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <memory.h>
#include <cmath>
using namespace std;

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define FOR0(i,n) for( i = 0 ; i < n ; ++i )
#define FOR1(i,n) for( i = 1 ; i <= n ; ++i )
#define sys_p system( "pause" )
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define sz(a) (int)a.size()

typedef long long LL ;

int rev( int x ) {
    int r = 0;
    while (x) {
        r = r * 10 + x % 10;
        x /= 10;
    }
    return r ;
}

int n, dp[2000000], r, i ;

int main() {
    freopen("input.txt", "r", stdin) ;
    freopen("output.txt", "w", stdout) ;

    FOR0(i,2000000)
        dp[i] = (int)1e9 ;
    dp[0] = 0 ;
    dp[1] = 1 ;
    for( i = 1 ; i <= 1000000 ; ++i ) {
        dp[i+1] = min( dp[i+1], dp[i] + 1 ) ;
        r = rev(i) ;
        if( r > i )
            dp[r] = min( dp[r], dp[i] + 1 ) ;
    }

    int T, _T ;
    cin >> T ;
    for( _T = 1 ; _T <= T ; ++_T ) {
        cin >> n ;
        cout << "Case #" << _T << ": " ;
        cout << dp[n] << endl ;
    }
}