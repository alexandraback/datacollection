#include "bits/stdc++.h"

using namespace std;

const int INF = 1e9;

template<typename T>T chmin( T &a , T b ){ return a = min( a , b ); }
template<typename T>T chmax( T &a , T b ){ return a = max( a , b ); }

int d;
int a[1024];
int ca[1024];

int main(){

  int t;
  scanf( "%d" , &t );

  for( int cnt = 1; cnt <= t; cnt++ ){
    scanf( "%d" , &d );

    for( int i = 0; i < 1024; i++ )
      a[i] = 0;

    int ans = INF;
    for( int i = 0; i < d; i++ ){
      int p;
      scanf( "%d" , &p );
      a[p]++;
      chmax( ans , p );
    }

    for( int i = 1; i <= ans; i++ ){
      int res = i;
      for( int j = 0; j < 1024; j++ )
	ca[j] = a[j];
      
      for( int j = 1023; j > i; j-- ){
	res += ca[j];
	ca[i] += ca[j];
	ca[j-i] += ca[j];
	ca[j] = 0;
      }

      chmin( ans , res );
    }


    printf( "Case #%d: %d\n" , cnt , ans );
    
  }
  
  return 0;
}
