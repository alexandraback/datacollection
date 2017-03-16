#include "bits/stdc++.h"

using namespace std;

typedef long long int ll;

template<typename T>T chmin( T &a , T b ){ return a = min( a , b ); }
template<typename T>T chmax( T &a , T b ){ return a = max( a , b ); }

int f( int a , int b ){
  int sygn = ( a/abs(a) )*( b/abs(b) );
  a = abs(a);
  b = abs(b);
  int res;
  
  if( a == b ) res = -1;
  else if( a == 1 ) res = b;
  else if( b == 1 ) res = a;
  else if( a == 2 && b == 3 ) res = 4;
  else if( a == 2 && b == 4 ) res = -3;
  else if( a == 3 && b == 2 ) res = -4;
  else if( a == 3 && b == 4 ) res = 2;
  else if( a == 4 && b == 2 ) res = 3;
  else if( a == 4 && b == 3 ) res = -2;
  
  return res * sygn;
}

char str[10010];
string s;

int a[10010];
int n;

int main(){

  int t;
  scanf( "%d" , &t );

  int l , x;
  
  for( int cnt = 1; cnt <= t; cnt++ ){
    scanf( "%d %d" , &l , &x );

    scanf( "%s" , str );

    s = "";
    for( int i = 0; i < x; i++ )
      s += str;

    //printf( "%s\n" , s.c_str() );
    
    n = s.length();
    
    for( int i = 0; i < n; i++ ){
      switch( s[i] ){
      case 'i':
	a[i] = 2;
	break;
      case 'j':
	a[i] = 3;
	break;
      case 'k':
	a[i] = 4;
	break;
      }
    }

    int sum = 1;
    for( int i = 0; i < n; i++ )
      sum = f( sum , a[i] );

    //printf( "%d\n" , sum );
    
    bool ans = false;
    int fo = 1;
    int la = sum;
    for( int i = 0; i < n; i++ ){
      fo = f( fo , a[i] );
      la = f( -a[i] , la );
      //printf( "####%d %d %d %d\n" , i  , la , fo , -a[i] );
      if( fo == 2 ){
	int nfo = 1;
	int nla = la;
	for( int j = i+1; j < n; j++ ){
	  nfo = f( nfo , a[j] );
	  nla = f( -a[j] , nla );
	  //if( nfo == 3 ) printf( "#%d %d\n" , j , nla );
	  if( nfo == 3 && nla == 4 ) ans = true;
	}
      }
    }

    printf( "Case #%d: " , cnt );
    if( ans ) printf( "YES\n" );
    else printf( "NO\n" );
  }

  return 0;
}
