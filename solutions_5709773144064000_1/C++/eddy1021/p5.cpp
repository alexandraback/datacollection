#include <stdio.h>
#define d double
#define eps 1e-8
d Min( d u , d v ){ return u<v?u:v; }
int t , cs;
d c , f , x , cst , p , tmin;
bool efi(){
    if( c / p + x / ( p + f ) < x / p + eps )
        return true;
    return false;
}
void solve(){
    cst = 0.0; p = 2.0;
    tmin = x / p;
    while( efi() ){
        cst += c / p; p += f;
        tmin = Min( tmin , cst + x / p );
    }
    printf( "%.10lf\n" , tmin );
}
int main(){

    freopen( "B-large.in" , "r" , stdin );
    freopen( "B-large.out" , "w" , stdout);

    scanf( "%d" , &t ); while( t -- ){
        scanf( "%lf%lf%lf" , &c , &f , &x );
        printf( "Case #%d: " , ++ cs );
        solve();
    }

    fclose( stdin ); fclose( stdout );
}
