# include <stdio.h>
# include <string.h>

int data[1000], N, S, p;
int din[101][101];
int vis[101][101];

int max( int a, int b ){ return a > b ? a : b; }
int abso( int a ){ return a < 0 ? -a: a;  }

int solve( int pos, int s ){
  int res = -(1<<28), x, y, z;
  if( s < 0 ) return -(1<<28);
  if( pos == N ) return s == 0 ? 0 : res;	
  if( vis[pos][s] == 1 ) return din[pos][s];
  vis[ pos ][ s ] = 1;
  for( x = 0; x <= 10; x++){
    for( y = 0 ; y <= 10 ; y++) if( x + y <= data[ pos ]){
      z = data[ pos ] - x - y;	
      if( abso( x - y ) > 2 || abso( x - z ) > 2 || abso( y - z ) > 2 ) continue;
      if( z > 10 ) continue;
      if( abso( x - y ) >= 2 || abso( x - z ) >= 2 || abso( y - z ) >= 2 ){
        res = max( res, solve( pos + 1, s - 1 ) + ( ( max( max( x, y ), z ) >= p ) ? 1 : 0 ) );	
      }else{
        res = max( res, solve( pos + 1, s ) + ( ( max( max( x, y ), z ) >= p ) ? 1 : 0 ) );	
      }
    }
  }
  return din[pos][s] = res;
}

main(){
  int ncases, cases, x;
  for( scanf("%d", &ncases), cases = 1; cases <= ncases ; cases++ ){
     scanf("%d %d %d", &N, &S, &p);	
     for( x = 0; x < N; x++) scanf("%d", &data[ x ]);
     memset( vis, 0, sizeof( vis ));
     printf("Case #%d: %d\n", cases, solve( 0, S ));
  }
  return 0;	
}