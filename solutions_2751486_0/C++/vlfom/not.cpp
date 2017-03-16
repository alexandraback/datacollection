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

ifstream Cin( "input.txt" );
ofstream Cout( "output.txt" );

const LL MOD = 1000000007 ;

bool gl( char x )
{
     return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' ;
}

main()
{ 
     LL T, t ; 
     Cin >> T ;
     FOR1( t, T )
     {
           string x ; LL n, i, c, ans = 0, l, r, la_l ; vector < LL > b ;
           Cin >> x >> n ; 
           c = 0 ; FOR0( i, x.length() ) if( gl(x[i]) ) c = 0 ; else
           {
             c++ ; if( c >= n ) b.pb( i ) ;
           }
           FOR0( i, (LL)b.size() )
           {
             l = b[i]-n+1 ; r = b[i] ;
             if( i ) la_l = b[i-1]-n+1 ; else la_l = -1 ;
             ans += (l-la_l)*(x.length()-r) ; 
           }
           Cout << "Case #" << t << ": " << ans << endl ;
     }
}
