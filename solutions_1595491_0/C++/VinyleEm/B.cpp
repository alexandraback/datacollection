#include <stdio.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>

using namespace std ;
#define lint long long
#define FOREACH(it,v) for( typeof((v).begin()) it = (v).begin() ; it != (v).end() ; it++ )
#define ALL(v) (v).begin(),(v).end()

const int infinity = 0x3fffffff ;
const lint linfinity = 0x3fffffffffffffffLL ;

const int maxn = 105 ;

int dp[maxn][maxn] ;
int n , A[ maxn ] ;
vector<pair<int,int> > vlist[32] ;

void init(){
    for( int x = 0 ;x < 32 ; x++ )
        vlist[x].clear() ;

    for( int a = 0 ;a <= 10 ; a++ )
        for( int b = a ; b <= a+2 and b <= 10 ; b++ )
            for( int c = b ; c <= a+2 and c <= 10 ; c++ ){
                vlist[a+b+c].push_back( make_pair( a , c ) ) ;
            }
}

int solve( int x , int s , int P ){
    if( x == n ) {
        return 0 ;
    }

    int& ans = dp[x][s] ;
    if( ans >= 0 ) return ans ;

    ans = 0 ;
    FOREACH( it , vlist[ A[x] ] ){
        int sur = 0 ;
        if( it->second == it->first + 2 ){
            sur = 1 ;
        }

        if( sur <= s ){
            ans = max( ans , solve( x+1 , s - sur , P ) + (it->second >= P) ) ;
        }
    }

    return ans ;
}

int main(){
    init() ;

    int cases ;
    cin >> cases ;

    for( int cs=1 ; cs <= cases ; cs++ ){
        cin >> n ;
        int S , P ;
        cin >> S >> P ;
        for( int x = 0 ;x < n ; x++ )
            cin >> A[x] ;

        memset( dp, -1 , sizeof dp ) ;
        cout << "Case #" << cs <<": " << solve( 0 , S , P ) << endl ;
    }
	return 0 ;
}
