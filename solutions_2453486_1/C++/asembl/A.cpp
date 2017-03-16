#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std ;
char map[4][4] ;

bool win( char T )
{
    bool row[4] = {false} , col[4] = {false} ;
    bool dia1 = false , dia2 = false ;
    
    for ( int i = 0 ; i < 4 ; ++i )
        for ( int j = 0 ; j < 4 ; ++j )
        {
            if ( map[i][j] != T && map[i][j] != 'T' )
            {
                row[i] = true , col[j] = true ;
                if ( i == j )
                    dia1 = true ;
                if ( i+j == 3 )
                    dia2 = true ;
            }
        }
    bool res = (dia1 && dia2) ;
    for ( int i = 0 ; i < 4 ; ++i )
        res = ( res && row[i] && col[i] ) ;
    return !res ;
}
int main()
{
    int test , nowtest = 0 ;
    
    cin >> test ;
    while ( test-- )
    {
        ++nowtest ;
        
        scanf(" ");
        for ( int i = 0 ; i < 4 ; ++i )
            for ( int j = 0 ; j < 4 ; ++j )
                cin >> map[i][j] ;
        
        printf("Case #%d: ",nowtest);
        if ( win('X') )
            printf("%c won",'X');
        else if ( win('O') )
            printf("%c won",'O');
        else
        {
            bool complete = true ;
            
            for ( int i = 0 ; i < 4 ; ++i )
                for ( int j = 0 ; j < 4 ; ++j )
                    if ( map[i][j] == '.' )
                        complete = false ;
            if ( complete == false )
                printf("Game has not completed");
            else
                printf("Draw");
        }
        printf("\n");
    }
    return 0;
}
