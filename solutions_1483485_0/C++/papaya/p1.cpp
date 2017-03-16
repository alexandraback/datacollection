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

#define MAX 1000
char str[ MAX ] ; 

char in_flag[ ] = "ejp mysljylc kd kxveddknmc re jsicpdrysi \
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd\
de kr kd eoya kw aej tysr re ujdr lkgc jv " ; 

char out_flag [ ] = "our language is impossible to understand \
there are twenty six factorial possibilities \
so it is okay if you want to just give up" ; 


int c_map[ MAX ] ; 

int ff[ MAX ] ; 

void ins( vector<char> &v , char *str ) { 
    
    v.clear( ) ; 
    int len = strlen( str) ; 
    
    for( int i = 0 ; i < len ; ++i ) { 
        
        if( isalpha( str[ i ] ) ) { 
            
            v.push_back( str[ i ] ) ; 
        }
    }    
}

void init( ) { 
    
    memset( c_map , 0xff , sizeof( c_map ) ) ; 
    
    
    vector<char>a ; 
    vector<char> b ; 
    
    ins( a , in_flag ) ; 
    ins( b , out_flag ) ; 
    
    memset( ff , 0xff , sizeof( ff ) ) ; 
    
    for( int i = 0 ; i < a.size( ) ; ++i ) { 
        
        
        c_map[ a[ i ] ] = b[ i ] ; 
        
        ff[ b[ i ] ] = 1 ; 
    }
    /*
    for( int i = 'a' ; i <= 'z' ; ++i ) { 
        
        if( ff[ i ] != -1 ) { 
            
            c_map[ 'z' ] = i ; 
            break ; 
        }
        //printf( "%c %d\n" , i , c_map [ i ] ) ; 
    }*/
    
    c_map[ 'q' ] = 'z' ; 
    c_map[ 'z' ] = 'q' ; 
    for( int i = 'a' ; i <= 'z' ; ++i ) { 
        
        ; //printf( "%c %d\n" , i , c_map [ i ] ) ; 
    }
    
}
void outAns( int ans ) { 
    
    printf( "%d\n" , ans ) ; 
}

char get_change( char c ) { 
    
    if( c_map[ c ] != -1 ) { 
        return c_map [ c ] ; 
    }
    else { 
        return c ; 
    }
}

void solve(  ) { 
    
    int len = strlen( str ) ; 
    for( int i = 0 ; i < len ; ++i ) { 
        
        putchar( get_change( str[ i ] ) ) ;    
    }
    putchar( '\n' ) ; 
}

void input( ) { 
    
    //freopen( "in.txt" , "r" , stdin) ;    
    //freopen(  "out.txt" ,  "w" , stdout ) ; 
    
    int T ; 
    scanf( "%d" , &T ) ; 
    getchar( ) ; 
    
    
    for( int i = 1 ; i <= T ; ++i ) { 
            
        gets( str ) ; 
        
        printf( "Case #%d: " , i ) ; 
        solve(  ) ; 
    }
    
    fclose(stdin);
	fclose(stdout);
}

void run( ) { 
    
    init( ) ; 
    input( ) ;     
}

int main( void ) { 
    
    run()  ; 
    return 0 ; 
} 