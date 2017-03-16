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

#define MAX 200000

int n ; 
int L ; 
double p [ MAX ] ; 

double calc_1( ) { 
    
    double sum =  2 * L - n + 2 ; 
    
    double tsum = L + 1 ; 
    for( int i = 0 ; i < n ; ++i ) { 
        
        tsum *= p [ i ] ; 
    }
    
    return sum - tsum ; 
}


double jisuan( int m , double pm ) { 
    
    double sum =  2 * L - 2 * m + n + 2 ;  
    
    double tsum = ( L + 1 ) * pm  ; 
        
    return sum - tsum ; 
}

void solve(  ) { 
   
   double ans = calc_1( ) ; 
   
   double pm = 1 ; 
   for( int i = n - 1 ; i >= 1 ; --i ) { 
        
        pm *= p[ n - 1 - i ] ; 
        
        double tans = jisuan( n - i , pm ) ; 
        
        if( ans > tans ) { 
            ans = tans ; 
        }
   }
   
   double select_3 = L + 2 ; 
   
   if( ans > select_3 ) { 
        ans = select_3 ; 
   }
   
   double EPS = pow( 10 , -6 ) ; //0.000001 ; 
   printf( "%.06lf\n" , ( ans + 0.5 * EPS ) ) ; 
   
   
}

void input( ) { 
    
    
    
    int T ; 
    scanf( "%d" , &T ) ; 
       
    for( int t = 1 ; t <= T ; ++t ) { 
        
        scanf ( "%d %d" , &n , &L ) ; 
        for( int i = 0 ; i < n ; ++i ) { 
        
            scanf( "%lf" , &p[ i ] ) ; 
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
    freopen( "out.txt" ,  "w" , stdout ) ; 
    
    run()  ; 
    
    fclose(stdin);
	fclose(stdout);
	
    return 0 ; 
} 
