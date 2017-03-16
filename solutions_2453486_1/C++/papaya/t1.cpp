#include <iostream>

#include <stdio.h>
#include <stdlib.h>

using namespace std;

const int N = 100  ; 
char board[ N ] [ N ] ;

const int M = 4 ;


bool is_win_row( char t ) { 
    
    for( int i = 0 ; i < M ; i++ ) {
        
        int num = 0;
        int num_T = 0;
        
        for( int j =0 ;j < M;   j++ ){
        
            if(  board[i][j] == t ) {
                num +=1;
                
            }
            if( board[i][j] == 'T' ) {
                num_T +=1 ;
            }
                
        }
        if( num == 4 ) {
            return true ;
        }
        if( num == 3 && num_T == 1 ){
            return true ;
        }
    }
    
    return false ;
}


bool is_win_col( char t ) { 
    
    for( int i = 0 ; i < M ; i++ ) {
        
        int num = 0;
        int num_T = 0;
        
        for( int j =0 ;j < M;   j++ ){
        
            if(  board[j][i] == t ) {
                num +=1;
                
            }
            if( board[j][i] == 'T' ) {
                num_T +=1 ;
            }
                
        }
        if( num == 4 ) {
            return true ;
        }
        if( num == 3 && num_T == 1 ){
            return true ;
        }
    }
    
    return false ;
}

bool is_win_x ( char t ) {
    
    int num = 0;
    int num_T = 0;
    
     for( int i = 0 ; i < M ; i++ ) {
        
         if(  board[i][i] == t ) {
            num +=1;
            
        }
        if( board[i][i] == 'T' ) {
            num_T +=1 ;
        }
            
    }
    if( num == 4 ) {
        return true ;
    }
    if( num == 3 && num_T == 1 ){
        return true ;
    }
       
    return false ;
}


bool is_win_y ( char t ) {
    
    int num = 0;
    int num_T = 0;
    
     for( int i = 0 ; i < M ; i++ ) {
        
        int j = M - 1 -i ;
         if(  board[i][j] == t ) {
            num +=1;
            
        } 
        if( board[i][j] == 'T' ) {
            num_T +=1 ;
        }
            
    }
    if( num == 4 ) {
        return true ;
    }
    if( num == 3 && num_T == 1 ){
        return true ;
    }
       
    return false ;
}

bool is_win( char t ) { 
    
    return is_win_row( t )  || is_win_col( t ) || is_win_x( t )  || is_win_y( t ) ;
        
        
}

int get_empty_num(  ) {
    
    int sum=0;
    for(int i = 0; i < M ; ++i ){
        
        for(int j=0;  j<M ;++j) { 
            
            
            if(board[i][j]=='.'){
                sum+=1;
            }
        }
    }
    return sum  ;
}
        

void solve( ) { 
    
    if( is_win( 'X') ) { 
        cout << "X won" << endl ;
        return;
    }
    
    
    if( is_win( 'O' ) ) {
        cout << "O won" << endl;
        return ;
        
        
    }
    
    
    if( get_empty_num( ) > 0 ){
        
        cout << "Game has not completed" << endl;
    }
    else {
        cout << "Draw" << endl;
    }
    
    
}


int main(void ) {
    
    int T ;
    cin >> T ; 
    
    
    for( int t =1 ; t <=T ;++t ) { 
        
        for ( int i = 0 ; i < 4 ; ++i ) { 
            cin >> board[ i ] ;
        }
        
        printf( "Case #%d: " ,  t ) ;
        solve( ) ;
    }
    return 0 ;
}

        
        
        
        
        
 
