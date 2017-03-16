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
const LL MOD = (LL)1e9 + 7 ;

LL t, T, n, ans, occ[30], ab[200][200] ; string r[200] ;

vector < int > lef[30], rig[30], all[30], ins[30] ;

bool bad( string x )
{
     char c ; int i, f ;
     for( c = 'a' ; c <= 'z' ; ++c )
     {
       f = -1 ;
       for( i=0;i<(int)x.length();++i )
         if( x[i] == c )
         {
           if( f == -1 )
             f = i ;
           else if( f != i-1 )
             return true ;
           else
             f = i ;
         }
     }
     return false ;
}

LL fac( LL x )
{
     LL ret = 1, i ;
     for( i=2; i<=x; ++i )
       ret = (ret*i)% MOD ;
     return ret ;   
}
     
main()
{       
     freopen( "input.txt", "r", stdin ) ;
     freopen( "output.txt", "w", stdout ) ;
     
     int i, j, c, nn ;
     cin >> T ;
     for( t = 1 ; t <= T ; ++t )
     {
          cin >> n ; 
          FOR1(i,n)
            cin >> r[i] ;
          FOR1(i,n)
            if( bad( r[i] ) )
              break ;
          if( i <= n )
          {
            cout << "Case #" << t << ": " << 0 << endl ;
            continue ;
          }
          FOR0(c,30)
            lef[c].clear(),
            rig[c].clear(),
            all[c].clear(),
            ins[c].clear(),
            occ[c] = 0 ;
          FOR0(c,30)
          {
            FOR1(i,n)
            {
              int s = -1, f = -1 ;
              FOR0(j,(int)r[i].size())
                if( r[i][j] == 'a'+c )
                {
                  if( s == -1 )
                    s = f = j ;
                  else
                    f = j ;
                }
              if( s == -1 ) 
                continue ;
              ++occ[c] ;
              if( s == 0 && f == (int)r[i].length()-1 )
                all[c].pb(i) ;
              else if( s == 0 )
                lef[c].pb(i) ;
              else if( f == (int)r[i].length()-1 )
                rig[c].pb(i) ;
              else
                ins[c].pb(i) ;
            }
          }
          FOR0(i,100)
            FOR0(j,100)
              ab[i][j] = 0 ;
          ans = 1 ; nn = n ;
          FOR0(c,30)
            if( occ[c] > 1 )
            {
              if( (int)lef[c].size() > 1 ||
                  (int)rig[c].size() > 1 ||
                  (int)ins[c].size() > 1 ||
                  ( !ins[c].empty() && ( !all[c].empty() || !lef[c].empty() || !rig[c].empty() ) ) 
                 )
              break ;
              
              if( !all[c].empty() )
              {
                ans = ( ans * fac( (int)all[c].size() ) ) % MOD ;
                
                if( lef[c].empty() )
                {
                  if( rig[c].empty() )
                    nn -= (int)all[c].size()-1 ;
                  else
                    nn -= (int)all[c].size() ;
                }
                else
                {
                  if( rig[c].empty() )
                    nn -= (int)all[c].size() ;
                  else
                    nn -= (int)all[c].size()+1 ;
                }
              }
              else
              {
                if( lef[c].empty() )
                {
                  if( rig[c].empty() )
                    nn = nn ;
                  else
                    nn = nn ;
                }
                else
                {
                  if( rig[c].empty() )
                    nn = nn ;
                  else
                    nn -= 1 ;
                }
              }
              if( !lef[c].empty() && !rig[c].empty() )
                ab[ rig[c][0] ][ lef[c][0] ] = 1 ;
            }
          if( c < 30 )
          {
            cout << "Case #" << t << ": " << 0 << endl ;
            continue ;
          }
          FOR0(i,100)
          {
            FOR0(j,100)
              if( ab[i][j] && ab[j][i] )
                break ;
            if( j < 100 )
              break ;
          }
          if( i < 100 )
          {
            cout << "Case #" << t << ": " << 0 << endl ;
            continue ;
          }
          ans = ( ans * fac(nn) ) % MOD ;
          cout << "Case #" << t << ": " << ans << endl ;
          
     } 
} 
