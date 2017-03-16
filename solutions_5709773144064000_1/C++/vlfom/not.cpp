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
using namespace std;
 
#define max(a,b) ((a)>(b)?(a):(b))
#define FOR0(i,n) for( i = 0 ; i < n ; ++i )
#define FOR1(i,n) for( i = 1 ; i <= n ; ++i )
#define sys_p system( "pause" )
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
 
typedef long long LL ;
const LL INF = (LL)1e18 ;
const LL MOD = (LL)1e9 + 9 ;
 
main()
{  
      //freopen( "input.txt", "r", stdin ) ;
      //freopen( "output.txt", "w", stdout ) ;
      int T, t ;
      scanf( "%d", &T ) ;
      FOR1(t,T)
      {
        long double c, f, s, cv, ct, cc, zn, t0, tc ; int tmp, i, mn ;
        cin >> c >> f >> s ;
        
          t0 = c/2. ; 
          if( (int)t0 != t0 ) 
            t0 = (int)t0 + 1 ;
          zn = s*0.5 ; mn = 0 ;
          ct = 0 ;
          FOR1(i,1000000)
          {
             ct += c / ( (i-1)*f+2. ) ;
             cv = i*f + 2 ; 
             tc = s/cv ;
             if( ct + tc < zn )
               zn = ct + tc, mn = i ;
          } 
          ct = 0 ; tc = s*0.5 ;
          FOR1(i,mn)
          {
             ct += c / ( (i-1)*f+2. ) ;
             cv = i*f + 2 ; 
             tc = s/cv ;
          }
          
          printf( "Case #%d: ", t ) ; 
          cout << setprecision(7) << fixed << ct+tc << endl ;
      }
}
