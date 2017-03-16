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

using namespace std ; 

#define MAX 2000

typedef struct Node { 

    int id ; 
    
    int a ; 
    int b ; 
    
    Node( ) { }
    Node( int id , int a  , int b ) { 
    
        this->id = id ; 
        this->a = a ; 
        this->b = b ; 
    }
    
    
    
    
} Node ; 

Node a[ MAX ] ; 
Node b[ MAX ] ; 
int n ; 

bool cmpa ( const Node &a , const Node &b ) { 
    
    if( a.a != b.a ) { 
        return a.a < b.a ; 
    }
    else { 
        return a.b > b. b ; 
    }     
}
bool cmpb ( const Node &a , const Node &b ) { 
    
    return a.b < b.b ; 
}

int flag[ MAX ] ; 
int flag1[ MAX ] ; 


int sum1 = 0 ; 
int sum = 0 ; 

void ins( int sum_b ) { 
  
  for( int i = 0 ; i < n ; ++i ) { 
       
       if( flag[ a[i].id ] == 2 ) { 
            continue ; 
       }
         
       if( sum1 + sum_b >= a[ i ] .a  ) { 
            
            if( flag1[ a[i].id ] == 1 ) { 
                continue ; 
            }
            
            sum1++ ;          
            flag1[ a[i].id ] = 1 ;               
       }
       else { 
            break ; 
       }
  }
}


int solve2(  ) { 
   
   sort( a , a + n , cmpa ) ; 
   sort( b , b + n , cmpb ) ; 
   
   memset( flag , 0 , sizeof( flag ) ) ; 
   memset( flag1 , 0 , sizeof( flag1 ) ) ; 
   
   sum1 = 0 ; 
   sum = 0 ; 
   
   ins( 0 ) ; 
   /*
   cout << "a: " << endl ; 
   for( int i = 0 ; i < n ; ++i ) { 
        
        printf( "%d %d \n" , a[i].a , a[i].b ) ; 
        
    }
    
   for( int i = 0 ; i < n ; ++i ) { 
        
        printf( "%d %d \n" , b[i].a , b[i].b ) ; 
        
    }*/
   
  
   
   int count = 0 ; 
   
   for( int i = 0 ; i < n ; ++i ) { 
       
       //printf( "i: %d sum: %d\n" , i , sum ) ; 
       
       if( b[ i ].b == 0 ) { 
            
           sum += 2 ; 
           count++ ; 
           
           flag[ b[i].id ] = 2 ; 
           
           if( flag1[ b[i].id ] == 1 ) { 
           
                sum1-- ; 
           }
       }
       else if( sum >= b[i].b ) { 
           
           if( flag1[ b[i].id ] == 1 ) { 
               sum1-- ; 
           }
                      
           sum += 2 ; 
           count++ ;            
       }
       
       else { 
            
            ins( sum ) ; 
            
            if( sum + sum1 < b[i].b ) { 
                return -1 ; 
            }
            else { 
                            
                int d = b[i].b - sum ; 
                
                //cout << "i: " << i << " b[i]: " << b[i].b << " sum: " << sum << endl ;  
                //cout << "d: " << d << endl ;                 
                
                count += d + 1 ; 
                                
                sum += d ; 
                sum += 2 ; 
                
                if( flag1[ b[i].id ] == 1 ) { 
                    sum1-- ;                     
                }
                
                //printf( "count: %d\n" , count ) ;  
            }
       }
   }
   return count ;  
}
void solve( ) { 

    int ans = solve2( ) ; 
    
    if( -1 == ans ) { 
        printf( "Too Bad\n" ) ; 
    }
    else { 
        printf( "%d\n" , ans ) ;         
    }
}


void input( ) { 
    
    int T ; 
    scanf( "%d" , &T ) ; 
       
    for( int t = 1 ; t <= T ; ++t ) { 
        
        scanf( "%d" , &n ) ; 
        
        for( int i = 0 ; i < n ; ++i ) {             
            
            int ta ; 
            int tb ;         
            scanf( "%d %d" ,&ta , &tb ) ;   
            
            a[ i ] = Node( i , ta , tb ) ;
            b[ i ] = Node( i , ta, tb ) ;            
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
