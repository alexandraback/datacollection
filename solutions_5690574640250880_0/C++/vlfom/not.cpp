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

char **ans, found ; int n, m, k, dx[8] = { 0,0,1,1,1,-1,-1,-1 }, dy[8] = { -1,1,0,1,-1,0,1,-1 } ;

void write( char **mas )
{
     int i, j ; 
     FOR1(i,n){FOR1(j,m)cout<<(bool)mas[i][j];cout<<endl;}cout<<endl;
}

bool dfs( char **cur, int I, int J, int bomb )
{
      //cout << I << " " << J << endl ; write(cur) ;
      if( bomb < k ) 
        return false ;
      if( bomb == k )
      {
        ans = cur ; found = 1 ;
        return true ;
      }
      
      int l, l2, x, y, add, i, j ; 
      FOR0(l,8)
      {
        x = I+dx[l] ;
        y = J+dy[l] ;
        if( x >= 1 && x <= n && y >= 1 && y <= m && cur[x][y] )
        {
          FOR0(l2,8)
          {
            i = x+dx[l2] ;
            j = y+dy[l2] ;
            if( i >= 1 && i <= n && j >= 1 && j <= m && !cur[i][j] )
              break ;
          }
          if( l2 == 8 ) continue ; //nothing to do here
          
          char **go = new char *[n+1] ;
          FOR1(i,n)
            go[i] = new char [m+1] ;
          FOR1(i,n)FOR1(j,m)
            go[i][j] = 0 ;
            
          FOR1(i,n)FOR1(j,m)
            go[i][j] = cur[i][j] ;
          add = 0 ;
          FOR0(l2,8)
          {
            i = x+dx[l2] ;
            j = y+dy[l2] ;
            if( i >= 1 && i <= n && j >= 1 && j <= m && !go[i][j] )
              ++add, go[i][j] = 1 ;
          }
          if( dfs( go, x, y, bomb-add ) ) 
            return true ;
        }
      }
      return false ;
}
 
main()
{  
      freopen( "input.txt", "r", stdin ) ;
      freopen( "output.txt", "w", stdout ) ;
      int T, t ;
      scanf( "%d", &T ) ;
      FOR1(t,T)
      {
          printf( "Case #%d:\n", t ) ; 
          
          found = 0 ;
          
          int i, j, x, y, l, add ; 
          cin >> n >> m >> k ;
          
          if( n*m == k+1 )
          {
            printf( "c" ) ;
            FOR1(i,n)
            {
              FOR1(j,m-1)
                printf( "*" ) ;
              if(i>1)
                printf("*") ;
              printf( "\n" ) ;
            }
            continue ;
          }
          
          
          FOR1(i,n)
          {
                   
          FOR1(j,m)
          {
            char **mas = new char *[n+1] ;
            FOR1(x,n)
              mas[x] = new char [m+1] ;
            FOR1(x,n)FOR1(y,m)
              mas[x][y] = 0 ;
             
            mas[i][j] = 1 ; add = 1 ;
            FOR0(l,8)
            {
              x = i+dx[l] ;
              y = j+dy[l] ;
              if( x >= 1 && x <= n && y >= 1 && y <= m )
                mas[x][y] = 1, ++add ;
            }
            //write(mas) ; cout << "GOOOO" << endl ;
            dfs( mas, i, j, n*m-add ) ;
            if( found ) break ;
          }
          if( found ) break ;
          
          }
          if( !found )
            printf( "Impossible\n" ) ;
          else
          {
            FOR1(x,n)
            {
              FOR1(y,m)
                if( x == i && y == j )
                  printf( "c" ) ;
                else if( ans[x][y] )
                  printf( "." ) ;
                else
                  printf( "*" ) ;
              printf( "\n" ) ;
            }
          }
      }
}
