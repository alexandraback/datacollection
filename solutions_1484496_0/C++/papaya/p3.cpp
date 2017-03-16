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

#define MAX ( 2*1000000 ) 

int a[ 612 ] ; 
int n ; 
int sum ; 
int up_sum ; 

//vector<int> f[ 2 ] ; 

bool f[ 20 ] [ MAX ] ; 

bool used[ 610 ] ; 

vector<int> v ; 

vector<int> all_v ; 

set<int> set1 ; 

void init_dp( ) { 
    
    v.clear( ) ; 
    
    for( int i = 0 ; i < n ; ++i ) { 
        
        if( !used[ i ] ) { 
            
            v.push_back( a[ i ] ) ; 
        }
    }
    sort( v.begin() , v.end( ) ) ; 
    
    memset( f , false , sizeof( f ) ) ; 
    
    f[ 0 ] [ 0 ] = true ; 
    f[ 0 ] [ v[ 0 ] ] = true ; 
    
    all_v.clear( ) ; 
    set1.clear( ) ; 
    
    all_v.push_back( v[ 0 ] ) ; 
    set1.insert( v[ 0 ] ) ; 
}

bool dp( int flag_sum , int &index ) { 
    
    
    init_dp( ) ; 
    
    if( v[ 0 ] == flag_sum ) { 
        return true ; 
    }
    
    for( int i = 1 ; i < v.size( ) ; ++i ) { 
                
        int size = all_v.size( ) ; 
        for( int k = 0 ; k < size ; ++k ) { 
            
            int next = all_v[ k ] + v[ i ] ; 
            
            if(  next <= flag_sum &&  set1.count( next ) <= 0  ) { 
                
                set1.insert( next ) ; 
                all_v.push_back( next ) ; 
                
                f[ i ] [ next ] = true ; 
                
                if( next == flag_sum ) { 
                    
                    index = i ; 
                    return true ; 
                }
            }               
        }
    }
    return false ;
}

void print1( ) { 
    
    bool first = true ; 
    
    for( int i= 0 ; i < n ; ++i ) { 
        
        if( used[ i ] ) { 
            
            if( !first ) { 
                printf( " " ) ; 
            }
            first = false ; 
            
            cout << a[ i ] ; 
        }
    }
    cout << endl ; 
    

}

void print( int index , int value ) { 
    
    if( index < 0 || value == 0 ) { 
        return ; 
    }
    
    if( f[ index ] [ value ]) { 
        
        //printf( "index; %d %d %d value: %d \n" , index , value , f[ index] [ value ] , v[ index ] ) ; 
    
    
        print( index - 1 , value - v[ index ] ) ; // - v
        
        if( value == v[ index ] ) { 
            
            printf( "%d" , v[ index ] ) ; 
        }
        else { 
            printf( " %d" , v[ index ] ) ; 
        }
    }
    else { 
        print( index - 1 , value ) ; 
    }
}

void print_ans( int index , int flag_sum ) { 
    
    
    print1( ) ; 
    
    //cout << "sum: " << flag_sum << endl ; 
    
    //cout << "index: " << index << endl ; 
    print( index , flag_sum ) ; 
    
    cout << endl ;           
                
}
      


bool dfs( int level , int now_sum ) { 
    
    if( level >= n ) { 
        return false ; 
    }
    if( now_sum > up_sum ) { 
        return false ; 
    }
    
    int next_sum = now_sum + a[ level ] ;
    if( next_sum <= up_sum ) { 
        
         
        
        used[ level ] = true ; 
        
        int index = 0 ; 
        if( dp( next_sum , index ) ) { 
            
            print_ans( index , next_sum ) ; 
            return true ; 
        }
        
        bool is_yes = dfs( level + 1 , next_sum ) ; 
        
        if( is_yes ) { 
            return true ; 
        }
        
        used[ level ] = false ; 
    }
    
    
    return dfs( level + 1 , now_sum ) ; 
        
}

void solve( ) { 
    
    sort( a , a + n ) ; 
    
    memset( used , 0 , sizeof( used ) ) ; 
    
    up_sum = sum / 2 ;
    
    if( ! dfs( 0 , 0 ) ) {         
        
        cout << "Impossible" << endl ; 
    }
}

void input( ) { 
    
    int T ; 
    cin >> T ; 
    
    for( int num_case = 1 ; num_case <= T ; ++num_case ) { 
        
        cin >> n ; 
        
        sum = 0 ; 
        for( int i = 0 ; i < n ; ++i ) { 
            
            cin >> a[ i ] ; 
            
            sum += a[ i ] ; 
        }
         
         printf( "Case #%d:\n" , num_case ) ; 
         solve( ) ;    
    }    
}
 
void run( void ) {
    
    input( ) ; 
}
 
int main( void ){
    
    freopen( "in.txt" , "r" , stdin ) ;
    //freopen( "out.txt" , "w" , stdout ) ; 
    
    run( ) ; 
    
    //while( true ) ; 
    return 0 ; 
}
 
