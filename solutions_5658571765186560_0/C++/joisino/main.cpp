#include "bits/stdc++.h"
 
using namespace std;

int main(){

  int t;
  scanf( "%d" , &t );

  for( int cnt = 1; cnt <= t; cnt++ ){
    int x , r , c;
    scanf( "%d %d %d" , &x , &r , &c );

    bool f = true;
    if( x >= 8 ) f = false;
    if( max(r,c) < x ) f = false;
    if( min(r,c) < (x+1)/2 ) f = false;
    if( (r*c)%x != 0 ) f = false;
    
    printf( "Case #%d: " , cnt );
    if( f ) printf( "GABRIEL\n" );
    else printf( "RICHARD\n" );
  }
  
}
