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

#define MAX 2000


int n ; 
int S ; 
int p ; 

int t[ MAX ] ; 

typedef struct Node { 
    
    int no_max_p ; 
    int yes_max_p ; 
    
    Node( ) { }    
} Node ; 

Node a[ MAX ] ; 
int now_id = 0 ; 

bool isvalid( int *stack ) { 
    
    const int n = 3 ; 
    for( int i = 0 ; i < n ; ++i ) { 
        
        for( int j = i + 1 ; j < n ; ++j ) { 
            
            if( abs( stack[j] - stack[ i ] ) > 2 ) { 
                return false; 
            }
        }
    }
    return true ; 
} 

int get_max_d( int *stack ) { 
    
    const int n = 3 ; 
    
    int max_d = 0 ; 
    for( int i = 0 ; i < n ; ++i ) { 
        
        for( int j = i + 1 ; j < n ; ++j ) { 
            
            int d = abs( stack[j] - stack[ i ] )  ; 
            
            if( max_d < d ) { 
                max_d = d ; 
            }
        }
    }
    return max_d ; 
} 
int get_max_value( int *stack ) { 
    
    int max_value = stack [ 0 ] ; 
    for( int i = 1 ; i < 3 ; ++i ) { 
        
        if( max_value < stack[ i ] ) { 
            
            max_value = stack[ i ] ; 
        }
    }
    return max_value ;     
}
void ins( int &max_value , int value ) { 
    
    if( max_value < value ) { 
        max_value = value ; 
    }
} 

void process( int *stack ) { 
    
    if( ! isvalid( stack ) ) { 
        return ; 
    }
    
    int max_value = get_max_value( stack ) ; 
    
    if( get_max_d( stack ) == 2 ) {   
        
        ins( a[ now_id ].yes_max_p , max_value ) ;  
    }
    else { 
        ins( a[ now_id ].no_max_p , max_value ) ;
    }
} 

void dfs( int *stack , int stack_len ,  int start , int sum ) { 
    
    if( stack_len == 3 ) { 
        
        if( sum != 0 ) { 
            return ; 
        }
        process( stack ) ; 
        return ; 
    }
    if( sum < 0 ) { 
        return ; 
    }
    
    for( int i = start - 2 ; i <= start + 2 ; ++i ) { 
        
        if( i < 0 ) { 
            continue ; 
        }
        if( i > 10 || i > sum ) { 
            break ; 
        }
        
        stack[ stack_len ] = i ;
        dfs( stack ,  stack_len  + 1 , i , sum - i  ) ;  
    }    
}

void jisuan( int id ) { 
    
    now_id = id ; 
    int sum = t[ id ] ; 
    
    int a_stack[ MAX ] ;  
    
    for( int i = 0 ; i <= 10 && i <= sum ; ++i ) { 
        
        
        a_stack [ 0 ] = i ; 
        dfs( a_stack , 1 , i , sum - i ) ; 
    }    
}

void init( ) { 
    
    memset( a , 0 , sizeof( a ) )  ; 
    for( int i = 0 ; i < n ; ++i ) { 
        
        jisuan( i ) ;         
    } 
}

int max_count = 0 ; 

void update_ans( int status ) { 
    
    int count = 0 ; 
    
    for( int i = 0 ; i < n ; ++i ) { 
        
        //cout << "i: " << i << " " << a[i].yes_max_p << " " << a[i].no_max_p << endl ; 
        int max_p = 0 ; 
        if( (status>>i)&1 ) { 
            
            max_p = a[ i ].yes_max_p ;             
        }
        
        else { 
            max_p = a[i] .no_max_p ; 
        }
        
        //cout << "i: " << i << " max_p " << max_p << endl ; 
        if( max_p >= p ) { 
            count++ ; 
        }
    }
    if( max_count < count ) { 
        max_count = count ; 
    }
    
}

int count_ones( int n ) { 
    
    int sum = 0 ; 
    
    while( n ) { 
        
        ++sum ; 
        n &= n - 1 ; 
    }
    return sum ;     
}



vector<Node > b ; 
vector<Node> c ; 
vector<Node> d ; 

int get_ans( ) { 
    
    b.clear( ) ; 
    c.clear( ) ;
    d.clear( ) ; 
    
    for( int i = 0 ; i < n ; ++i ) { 
        
        if( a[ i ].yes_max_p >= p && 
            a[ i ].no_max_p >= p ) { 
            
            b.push_back( a[ i ] ) ;
        }
        else if( a[ i ].yes_max_p >= p ) { 
            
            c.push_back( a[ i ] ) ; 
        }
        else if( a[ i ].no_max_p >= p ) { 
            
            d.push_back( a[ i ] ) ; 
        }
    }
    
    int both_num = b.size( ) ;
    int yes_max_p = c.size( ) ; 
    int no_max_p = d.size( ) ; 
    
    int ans_count = both_num + no_max_p ; 
    
    if( yes_max_p >= S ) { 
        
        ans_count = S + both_num + no_max_p ;    
    }
    else { 
        ans_count =  yes_max_p  + both_num + no_max_p ; 
    }
    return ans_count ;  
}

void solve(  ) {    
   
   init( ) ;    
   printf( "%d\n" , get_ans( ) ) ; 
}  
void input( ) { 
    
    //freopen( "in.txt" , "r" , stdin) ;    
    //freopen(  "out.txt" ,  "w" , stdout ) ; 
    
    int T ; 
    scanf( "%d" , &T ) ; 
       
    for( int i = 1 ; i <= T ; ++i ) { 
        
        scanf( "%d %d %d" , &n , &S , &p ) ;
        
        for( int j = 0 ; j < n ; ++j ) {
            
            scanf( "%d" , &t[ j ] ) ; 
            
            //cout << "j: " << j << " " << t[j]<< endl ; 
        }
        
        
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
