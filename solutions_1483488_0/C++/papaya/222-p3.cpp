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


int A ; 
int B ; 

#define MAX 200

void outAns( int ans ) { 
    
    printf( "%d\n" , ans ) ; 
}

int build( char *str , int start , int len ) { 
    
    int sum = 0 ; 
    for( int i = 0 ; i < len ; ++i ) { 
        
        int pos = ( i + start ) % len ; 
        
        sum = 10 * sum + ( str[ pos ] -'0' ) ; 
    }
    
    return sum ; 
}

set<int> set1 ; 

int solve( int a ) { 
    
    char str[ MAX ] ; 
    sprintf( str , "%d" , a ) ; 
    
    
    int count = 0 ; 
    
    set1.clear( ) ; 
    
    int len = strlen( str ) ; 
    for( int i = 1 ; i < len ; ++i ) { 
        
        if( str[ i ] == '0' ) { 
            continue ; 
        }
        
      
        int b = build( str , i , len ) ;  
        
        if( b > a &&  b <= B ) { 
            
            if( set1.count( b ) > 0 ) { 
                continue ; 
            }
            
            set1.insert( b ) ; 
            
            //printf( "a: %d b: %d\n" , a , b ) ; 
            ++count ; 
        }  
              
    } 
    return count ;    
}

void solve(  ) { 
    
    int ans_count = 0 ; 
    for( int i = A ; i < B ; ++i ) {
        
         ans_count += solve( i )  ; 
    }
    outAns( ans_count ) ; 
}

void input( ) { 
    
    freopen( "in.txt" , "r" , stdin) ;    
    freopen(  "out.txt" ,  "w" , stdout ) ; 
    
    int T ; 
    scanf( "%d" , &T ) ; 
    
    for( int i = 1 ; i <= T ; ++i ) { 
   
        
        scanf( "%d %d" , &A , &B ) ; 
        
        printf( "Case #%d: " , i ) ; 
        solve(  ) ; 
    }
    
    fclose(stdin);
	fclose(stdout);
}

void run( ) { 
    
    input( ) ;     
}

int main( void ) { 
    
    run()  ; 
    return 0 ; 
} 