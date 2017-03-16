#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std  ; 

typedef unsigned long long uint64 ; 

uint64 f[ 2 ] [ 100 ] ;

uint64 E , R  , n ; 
uint64 a[ 100 ] ;


uint64 dp( ) { 
    
    memset( f[ 0 ] , 0 , sizeof( f[0] ) ) ; 
    
    int now_pos = 1 ; 
    for( int t = 0 ; t <= E ; t++ ) { 
        
        uint64 e = E - t + R ; 
        if( e >= E ) { 
            e = E ;
        }
        
        f[ 0 ] [ e ] = max( f[0][e] ,  t * a[ 0 ] ) ; 
    }
    
    for ( int i = 1 ; i < n ; ++i ) { 
        
        memset( f[now_pos ] , 0 , sizeof( f[now_pos] ) ) ; 
        
        for ( int x = 0 ; x <= E  ; ++x ) { 
            
            uint64 max_v = 0 ;
            
            for( int t = 0 ; t <= x ; t++ ) { 
                
                //cout << f[1-now_pos] [ x  - t ] << endl ;
                
                uint64 v = f[ 1 - now_pos ] [ x  ] + t * a[ i ] ;
                
                uint64 e = x - t  + R ;
                if( e >= E ) { 
                    e = E ;
                }
                f[now_pos ] [ e ] = max( f[now_pos][e] , v ) ;
                
              
            }   
            
            
        }
        
        now_pos = 1 - now_pos ; 
    }
    
    
    
    uint64 max_v = 0 ;
    for ( int t = 0 ; t <= E ; t++ ) { 
        
        if( max_v < f[1-now_pos][t] ) { 
            
            max_v = f[ 1 - now_pos ] [ t ] ;
        }
        
        //cout << "t: " << t << " " << f[ 1- now_pos ] [ t ] << endl ; 
    }
    
    return max_v ; 
       
}

void run( ) { 
    
    cout << dp( ) << endl ; 
}

int main( void ) { 
    
    int T ; 
    cin >> T ; 
    
    for( int t = 1 ;  t <= T ; ++t ) { 
        
        cin >> E >> R  >> n ; 
        for ( int i = 0 ; i < n ; ++i ) { 
            
            cin >> a[ i ] ; 
        }
        
        printf( "Case #%d: " , t ) ;
        run( ) ;   
        
    }   
    
}