#include <stdio.h>
#include <iostream>
#include <time.h>
#include <set>
#include <cstdlib>
#include <ctype.h> 
#include <string.h>
#include <vector>
#include <assert.h>
#include <math.h>

using namespace std ; 

#define MAX 2000

int n ; 
int m ; 

int a[ MAX ] ; 
vector<int> v[ MAX ] ; 

bool visited[ MAX ] ; 


bool dfs( int i ) { 
    
    for( int k = 0 ; k < v[ i ].size( ) ; ++k ) { 
        
        int id = v[ i ] [ k ] ; 
        
        if( !visited[ id ] ) { 
            
            visited[ id ] = true ; 
            
            bool ret = dfs( id ) ; 
            
            if( !ret ) { 
                return false ; 
            }
        }
        else { 
            return false ; 
         }
            
    }
    return true ; 
}

bool solve2( ) { 
    
    for( int i = 0 ; i < n ; ++i ) { 
    
        if( a[ i ] == 0 ) { 
            
            //cout << "i:" << i << " a[ i ] : " << a[ i ] << endl ; 
            
            memset( visited , 0 , sizeof( visited ) ) ; 
            visited[ i ] = true ; 
            
            if( ! dfs( i ) ) { 
                return true ; 
            }
        }
    }
    
    return false ; 
}

void solve( ) { 
    
    if( ! solve2( ) ) { 
        cout << "No" << endl ; 
        
    }
    else { 
        
        cout << "Yes" << endl ; 
    }
}

void init( ) { 
    
    for( int i = 0 ; i < n ; ++i ) { 
    
        v[ i ].clear( ) ; 
    }
}

void input( ) { 

    int T ; 
    scanf( "%d" , &T ) ; 
       
    for( int t = 1 ; t <= T ; ++t ) { 
        
        cin >> n ; 
        
        init( ) ; 
        
        for( int i = 0 ; i < n ; ++i ) { 
        
            cin >> a[ i ] ; 
            
            for( int j = 0 ; j < a[ i ]  ; ++j ) { 
                
                int id ; 
                cin >> id ; 
                
                id -= 1 ; 
                
                //cout << " i: " << i << " j: " << id << endl ; 
                
                v[ id ].push_back( i ) ; 
            }
        }
        /*
        for( int i = 0 ; i < n; ++i ) { 
            
            cout << " i: " << i <<  " " ; 
            for( int j  = 0 ; j < v[ i ].size( ) ; ++j ) { 
            
                cout << " " << v[ i ][ j ]  ; 
             }
             cout << endl ; 
        }*/
        
        printf( "Case #%d: " , t ) ; 
        solve(  ) ; 
    }
}

void run( ) { 
    
    input( ) ;     
}

int main( void ) { 
    
    freopen( "in.txt" , "r" , stdin) ;    
    freopen( "out.txt" ,  "w" , stdout ) ; 
    
    run()  ; 
    
    fclose(stdin);
	fclose(stdout);
	
    return 0 ; 
} 
