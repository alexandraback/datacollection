#include "stdio.h"
#include "vector"
#include "algorithm"
#include "string"

using namespace std;

typedef long long int ll;

template<typename T>T chmin( T &a , T b ){ return a = min( a , b ); }
template<typename T>T chmax( T &a , T b ){ return a = max( a , b ); }

int a[1024];
char str[1024];

int main(){

  int t;
  scanf( "%d" , &t );

  for( int cnt = 1; cnt <= t; cnt++ ){
    int smax;
    scanf( "%d " , &smax );

    scanf( "%s" , str );
    
    for( int i = 0; i <= smax; i++ )
      a[i] = str[i]-'0';


    int ans = 0;
    int st = 0;
    for( int i = 0; i <= smax; i++ ){
      if( st < i ){
	ans += i-st;
	st = i;
      }
      st += a[i];
    }

    printf( "Case #%d: %d\n" , cnt , ans );
  }
  
  return 0;
}
