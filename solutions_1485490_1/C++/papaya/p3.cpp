#include <stdio.h>
#include <iostream>
#include <time.h>
#include <set>
#include <cstdlib>
#include <ctype.h> 
#include <string.h>
#include <vector>
#include <assert.h>

using namespace std ; 

typedef unsigned long long uint64 ; 

#define MAX 110

typedef struct Node { 

    uint64 type ; 
    uint64 num ; 
} Node ; 

Node a[ MAX ] ; 
Node b[ MAX ] ; 

uint64 f[ MAX ] [ MAX ] ; 

int n ; 
int m; 

void init( ) { 
    
}

uint64 min2( uint64 a, uint64 b ) { 

    return a > b ? b : a ; 
}

uint64 max2( uint64 a, uint64 b ) { 

    return a > b ? a : b ; 
}

void init_dp( ) { 
    
    memset( f , 0 , sizeof( f ) ) ; 
    
    uint64 sum = 0 ; 
    
    for( int j = 0 ; j < m ; ++j ) { 
         
         if( b[ j ].type == a[ 0 ].type ) { 
         
            sum += b[ j ].num ; 
         }
         
         f[ 0 ] [ j ] = min2( sum , a[ 0 ].num ) ;     
         
        // cout << "0 : j: " << j << " " << f[ 0 ] [ j ] << endl ;      
    }

}

uint64 jisuan( uint64 di_sum , uint64 type , int di , int dj ) { 
    
    uint64 sum = 0 ; 
    uint64 max_ans = 0 ; 
    
    for( int k = dj ; k >= 0 ; --k ) { 
        
        if( b[ k ] .type == type ) { 
        
            sum += b[ k ].num ; 
        }
        
        uint64 tans = min2( sum ,  di_sum ) ; 
        
        if( k - 1 >= 0 && di >= 0  ) { 
        
            tans += f[ di ] [ k - 1 ] ; 
        }   
        
        if ( max_ans < tans ) { 
        
            max_ans = tans ; 
        }    
    }
    return max_ans ; 
}

uint64 jisuan( int i , int dj ) { 
    
    uint64 di_sum = 0 ; 
    
    uint64 max_ans = 0 ; 
    for( int di = i ; di >= 0 ; --di ) { 
        
        if( a[ di ].type == a[ i ].type ) { 
            
            di_sum += a[ di].num ;  
            
            uint64 tans = jisuan( di_sum , a[i].type , di - 1 , dj ) ;
            
            if ( max_ans < tans ) { 
            
                max_ans = tans ; 
            }     
        }
    }
    
    return max_ans ; 
}

uint64 dp ( ) { 
    
    init_dp( ) ; 
    
    uint64 ans = 0 ; 
    
    for( int i = 1 ; i < n ; ++i ) { 
    
        for( int j = 0 ; j < m ; ++j ) { 
            
            f[ i ] [ j ] = f[ i - 1 ] [ j ] ; 
        }
        
        for( int j = 0 ; j < m ; ++j ) { 
            
            uint64 tans = jisuan( i , j ) ; 
            
            f[ i ] [ j] = max2( f[i][j] , tans ) ; 
            
            if( j >= 1 ) { 
                f[ i ][ j  ] = max2( f[ i] [ j - 1 ] , f[ i ][j ]  ) ;                 
            }
            
            
            if( ans < f[ i ][ j ] ) { 
                ans = f[ i][ j ] ; 
            }
            
            //cout << "i: " << i << " j: " << j << " " << f[ i] [ j] << endl ; 
        }
    }
    
    return ans ; 

}

void solve(  ) { 
   
   cout << dp( ) <<endl ; 
}

void input( ) { 
    
    int T ; 
    scanf( "%d" , &T ) ; 
       
    for( int t = 1 ; t <= T ; ++t ) { 
        
        cin >> n >> m ; 
        
        for( int i = 0 ; i < n; ++i ) { 
        
            cin >> a[ i ].num >> a[ i ].type ; 
        }
        
        for( int j = 0 ; j < m ; ++j ) { 
        
            cin >> b[ j ].num >> b[ j ] .type ; 
        }
        
        printf( "Case #%d: " , t ) ; 
        solve(  ) ; 
    }
}

void run( ) { 
    
    input( ) ;     
}

int main( void ) { 
    
    freopen( "in.txt" , "r" , stdin) ;    
    //freopen( "out.txt" ,  "w" , stdout ) ; 
    
    run()  ; 
    
    fclose(stdin);
	fclose(stdout);
	
    return 0 ; 
} 
