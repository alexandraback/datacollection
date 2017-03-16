#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#define MAXN 1002
using namespace std;

int n , m;
bool sync_with_stdio( bool sync = false );
int ind[ MAXN ] , lnk[ MAXN ];
int w[ MAXN ][ MAXN ];
bool con[ MAXN ][ MAXN ];
bool ans;

void init()
{
  int i , j , k;

  ans = false;
  memset( w , 0 , sizeof( w ) );
  memset( ind , 0 , sizeof( ind ) );
  memset( con , 0 , sizeof( con ) );

  cin>>n;
  for( i = 1 ; i <= n ; ++ i )
    {
      cin>>lnk[ i ];
      for( j = 1 ; j <= lnk[ i ] ; ++ j )
        {
          cin>>k;
          ++ w[ i ][ k ];
          ++ ind[ k ];
        }
    }
  return ;
}

void dfs( int pos , int s )
{
  if( ans ) return ;

  for( int i = 1 ; i <= n ; ++ i )
    if( w[ pos ][ i ] and con[ s ][ i ] )
      {
        ans = true; 
        return;
      }
    else if( w[ pos ][ i ] )
      {
        con[ s ][ i ] = true;
        dfs( i , s );
      }
  return ;
}

int main()
{
  int tot , tt=1;
  cin>>tot;
  while( tt <= tot )
    {
      init();
      
      for( int i = 1 ; i <= n ; ++ i )
        dfs( i , i );
      
      cout<<"Case #"<<tt++<<": ";
      if( ans ) cout<<"Yes\n";
      else cout<<"No\n";
    }
  
  return 0;
}
