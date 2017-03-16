#include <cstdio>
int cas, n, m;
char f[52][52];
int main(){
    freopen( "B-small-attempt0.in" , "r" , stdin );
    freopen( "B.out" , "w" , stdout );
    scanf( "%d" , &cas );
    for( int T = 1 ; T <= cas ; T ++ ){
        scanf( "%d%I64d" , &n , &m );
        if( n == 2 ){
            if( m != 1 ){
                printf( "Case #%d: IMPOSSIBLE\n" , T );
                continue;          
            }else{
                printf( "Case #%d: POSSIBLE\n01\n00\n" , T );
                continue; 
            }    
        }
        
        if( m > ( 1LL << ( n - 2 ) ) ){
            printf( "Case #%d: IMPOSSIBLE\n" , T );
            continue;    
        }
        printf( "Case #%d: POSSIBLE\n" , T );
        long long delta = ( 1LL << ( n - 2 ) ) - m;
        //printf( "%I64d\n" , delta );
        for( int i = 0 ; i < n ; i ++ ){
            for( int j = 0 ; j < n ; j ++ ){
                if( j <= i )
                    f[i][j] = '0';
                else
                    f[i][j] = '1';
            }
            f[i][n] = '\0';
        }
        int y = 1;
        while( delta ){
            if( delta & 1 )
                f[y][n-1] = '0';
            delta >>= 1;
            y ++;
        }
        
        for( int i = 0 ; i < n ; i ++ )
            puts( f[i] );
        
        
    }
}
            
                
    
    

