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
      freopen( "input.txt", "r", stdin ) ;
      freopen( "output.txt", "w", stdout ) ;
      int T, t ;
      scanf( "%d", &T ) ;
      FOR1(t,T)
      {
          int n, i, j, s1, s2, s3 ;
          cin >> n ; 
          vector < double > r1(n), r2(n) ; multiset < double > u ;
          FOR0(i,n)
            cin >> r1[i] ;
          FOR0(i,n)
            cin >> r2[i] ;
          sort(r1.begin(),r1.end());
          sort(r2.begin(),r2.end());
          /*
          cout << endl ;
          FOR0(i,n)
            cout << 1000*r1[i] << " " ;
          cout << endl ;
          FOR0(i,n)
            cout << 1000*r2[i] << " " ;
          cout << endl ;
          */
          u.clear() ; 
          FOR0(i,n)
            u.insert(r2[i]) ;
          s2 = 0 ;
          FOR0(i,n)
            if( r1[i] > *(--u.end()) )
              u.erase( u.begin() ), ++s2 ;
            else
              u.erase( u.upper_bound( r1[i] ) ) ;
              
          u.clear() ; 
          FOR0(i,n)
            u.insert(r2[i]) ;
          s3 = 0 ;
          FOR0(i,n)
            if( r1[i] > *(u.end()) )
              u.erase( u.begin() ), ++s3 ;
            else
              u.erase( --u.end() ) ;
              
          u.clear() ; 
          FOR0(i,n)
            u.insert(r2[i]) ;
          s1 = 0 ;
          FOR0(i,n)
            if( r1[i] > *u.begin() )
              u.erase( u.begin() ), ++s1 ;
            else
              u.erase( --u.end() ) ;
              
          printf( "Case #%d: %d %d\n", t, s1, max(s2,s3) ) ; 
      }
}
