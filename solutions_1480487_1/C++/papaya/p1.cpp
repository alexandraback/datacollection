#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <math.h>

using namespace std ; 

#define MAX 500 

int s[ MAX ] ; 
int n ; 
double X ; 

#define EPS 1e-10 

bool is_ok( int i , double mid ) { 
    
    double sum = 100 - mid ; 
    
    double flag = s[ i ] + X * mid / 100 ; 
    
    for( int j = 0 ; j < n ; ++j  ) { 
        
        if( j == i) { 
            continue ; 
        }   
        if( s[ j ] >= flag ) { 
            continue ; 
        }
        
        double pk = ( flag - s[ j ] ) * 100.0 / X ; 
        sum -= pk  ; 
    }
    return sum > EPS ;
} 

/*
bool is_ok( int i , double mid ) { 
    
    double sum = 0 ;     
    for( int j = 0 ; j < n ; ++j  ) { 
        
        if( j == i) { 
            continue ; 
        }   
        
        double pk = ( s[ i ] - s[ j ] ) * 100 / X + mid ; // - s[ j ] ) * 100.0 / X ; 
        
        
        sum += pk + EPS  ; 
    }
    return sum <= 100 - mid ;
}
*/

double solve2( int i ) { 
    
    double low = 0 ; 
    double high = 100 ; 
    
    double ans = 100 ; 
    do { 
        double mid= ( low + high ) / 2 ;     
        
        if( is_ok( i ,  mid ) ) { 
            
            low = mid + EPS ;
        }
        else { 
            
            ans = mid ; 
            high = mid - EPS ;
        }
        
    } while( low + EPS < high ) ; 
    
    return ans ; 
}

void solve( ) { 
    
    
    for( int i = 0 ; i < n ; ++i ) { 
        
        double mi = solve2( i ) ; 
        
        printf( " %.6lf" , mi ) ; 
    }
    cout << endl ; 
}

void input( ) { 
    
    int T ; 
    cin >> T ; 
    
    for( int num_case = 1 ; num_case <= T ; ++num_case ) { 
        
         cin >> n ; 
         
         X = 0 ; 
         for( int i = 0 ; i < n ; ++i ) { 
                
              cin >> s[ i ] ;
              
              X += s[ i ] ;
         }
         
         printf( "Case #%d:" , num_case ) ; 
         solve( ) ;    
    }    
}
 
void run( void ) {
    
    input( ) ; 
}
 
int main( void ){
    
    freopen( "in.txt" , "r" , stdin ) ;
    freopen( "out.txt" , "w" , stdout ) ; 
    
    run( ) ;     
    return 0 ; 
}
 
