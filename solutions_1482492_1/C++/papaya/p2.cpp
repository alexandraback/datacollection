#include <stdio.h>
#include <iostream>
#include <time.h>
#include <set>
#include <cstdlib>
#include <ctype.h> 
#include <string.h>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <math.h>

using namespace std ; 

#define MAX 2100


typedef struct Node { 

    double t ;
    double x ;
} Node ; 

Node a[ MAX ] ; 

int n ; 
int m ; 

double D ; 
double G ; 


double get_a( double a , double b , double c ) { 

    
    double x = ( -b + sqrt( b * b - 4 * a * c ) ) / ( 2.0 * a ) ; 
    
    //printf( "a: %lf %lf %lf x: %lf\n" , a , b , c ,  x ) ; 
    
    //printf( "y: %lf\n" , a * x * x + b * x + c ) ; 
    
    return x ; 
}

double solve( int i ,  double x , double v ) { 
        
    if( i < n - 1 ) { 
        
        double t =  a[ i + 1 ] .t - a[ i ].t ; 
        double tv = ( a[ i  + 1 ].x - a[ i ] .x ) / t ; 
        
        
        double  dx = v * t + 1.0 / 2 * G * t * t + x ; 
        
        if( dx >= a[i+1].x ) { 
            
            //printf( "t: %lf\n" , t ) ; 
            return t + solve( i + 1 , a[i+1].x , tv ) ; 
        }
        else { 
            
            //printf( "t: %lf dx: %lf v: %lf\n" , t , dx , v + G * t ) ; 
            
            return t + solve( i + 1 , dx ,    v + G * t ) ;
        }
    }
    
    else { 
        double dt = ( a[ n  ] .t - a[ n - 1] . t ) ; 
        double tv = ( a[ n  ].x - a[ n - 1 ] .x ) / dt ; 
        
        double t = ( D - a[ n - 1 ] .x ) / tv ; 
    
    
        //printf( "x: %lf v: %lf\n" , x ,  v ) ;         
        //cout << "t: " << t << endl ; 
        double  dx = v * t + 1.0 / 2 * G * t * t + x ; 
        
        //printf( "dx: %lf D : %lf\n" , dx , D ) ; 
        if( dx >= D ) { 
            
            return t ; 
        }
        else { 
            
            double now_t = get_a( 1.0 / 2 * G , v , x - D  ) ; 
            
            
            return now_t  ;
        }
    }
    
}

void solve( ) { 
    
    while( n > 0 && a[ n - 1 ].x >= D ) { 
    
        --n ; 
    }
    //cout << "n: " << n << endl ; 
    /*
    for( int i = 0 ; i < n ; ++i ) { 
    
        printf( "%lf " , a[ i ].x ) ; 
    }
    
    cout << endl ; 
    */
    
    double t = 0 ; 
    if( n == 0 ) { 
        
        t = sqrt( 2 * D / G ) ; 
    }
    else { 
        t = solve( 0 , 0 , 0 ) ; 
    }
    
    printf( "%.6lf\n" , t ) ; 
}


void input( ) { 
    
    int T ; 
    scanf( "%d" , &T ) ; 
    
    for( int case_num = 1 ; case_num <= T ; ++case_num ) { 
        
        cin >> D >> n >> m ; 
        
        for( int i = 0 ; i  < n ; ++i ) { 
        
            cin >> a[ i ].t >> a[ i ].x ; 
        }
        
        printf( "Case #%d:\n" , case_num ) ; 
        for( int j = 0 ; j < m ; ++j ) { 
        
            cin >> G ;
            solve( ) ;  
        }
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
