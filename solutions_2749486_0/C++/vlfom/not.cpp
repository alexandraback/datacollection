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
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

#define FOR0(i,n) for( i = 0 ; i < n ; ++i )
#define FOR1(i,n) for( i = 1 ; i <= n ; ++i )
#define sys_p system( "pause" )
#define pb push_back 
#define mp make_pair

typedef long long LL ;
typedef vector < LL > vl ;
typedef vector < vl > vvl ;
typedef vector < vvl > vvvl ;

ifstream Cin( "input.txt" );
ofstream Cout( "output.txt" );

const LL MOD = 1000000007 ;

main()
{ 
     LL T, t ; 
     Cin >> T ;
     FOR1( t, T )
     {
           LL x, y, i, j, k ;
           vvvl dp( 501, vvl( 401, vl( 401 ) ) ), p = dp ;
           Cin >> x >> y ; x += 200 ; y += 200 ; dp[0][200][200] = 1 ;
           FOR1( k, 500 )
           {
             FOR1( i, 400 ) FOR1( j, 400 ) 
             {
                      if( i >= k ) if( dp[k-1][i-k][j] ) dp[k][i][j] = 1, p[k][i][j] = 0 ;
                      if( j >= k ) if( dp[k-1][i][j-k] ) dp[k][i][j] = 1, p[k][i][j] = 1 ;
                      if( i+k <= 400 ) if( dp[k-1][i+k][j] ) dp[k][i][j] = 1, p[k][i][j] = 2 ;
                      if( j+k <= 400 ) if( dp[k-1][i][j+k] ) dp[k][i][j] = 1, p[k][i][j] = 3 ;
             }
             if( dp[k][x][y] ) break ;
           }
           vector < char > ans ; i = x ; j = y ; while( k != 0 ) 
           {
                      if( p[k][i][j] == 0 ) ans.pb( 'E' ), i -= k ;
                      else if( p[k][i][j] == 1 ) ans.pb( 'N' ), j -= k ;
                      else if( p[k][i][j] == 2 ) ans.pb( 'W' ), i += k ;
                      else ans.pb( 'S' ), j += k ;
                      k-- ;
           }
           reverse( ans.begin(), ans.end() ) ; Cout << "Case #" << t << ": " ; FOR0( i, (LL)ans.size() ) Cout << ans[i] ; Cout << endl ;
     }
}
