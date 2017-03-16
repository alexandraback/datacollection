# include <stdio.h>
# include <string.h>

# define MAX 2000000


int pot( int val, int pt ){
  int r;
  if(pt == 0 ) return 1;
  if(pt == 1) return val;	
  r = pot( val, pt / 2);
  r = r*r;
  if( pt % 2 == 1 ) r*= val;
  return r;
}

long long solve( int a, int b){
  int x, value, MOD, w, cont;
  long long R = 0;
  for( x = a; x <= b; x++){
  	value = x;
  	for( cont = 0; value > 0; value /= 10, cont++);
  	value = x;
    MOD = pot( 10, cont - 1);
    for( w = 0 ; cont > 1 && w < cont + 2 ; w++){
      value = ( value / MOD + (value % MOD) * 10 );
      if( value == x ) break;
      if( value > x && value <= b ) {
        R++;
      }
    }
  }
  return R;
}

main(){
  int  ncases, cases, a, b;
    for( scanf("%d", &ncases), cases = 1; cases <= ncases ; cases++ ){
     scanf("%d %d", &a, &b);
     printf("Case #%d: %lld\n",cases, solve( a, b ));
  }
  return 0;
}