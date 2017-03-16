#include <stdio.h>
#include <string.h>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <cmath>
#include <queue>

using namespace std ;
#define lint long long
#define FOREACH(it,v) for( typeof((v).begin()) it = (v).begin() ; it != (v).end() ; it++ )
#define ALL(v) (v).begin(),(v).end()

const int infinity = 0x3fffffff ;
const lint linfinity = 0x3fffffffffffffffLL ;

string G[] = { "ejp mysljylc kd kxveddknmc re jsicpdrysi" , "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd" , "de kr kd eoya kw aej tysr re ujdr lkgc jv" } ;
string E[] = { "our language is impossible to understand" , "there are twenty six factorial possibilities" , "so it is okay if you want to just give up" } ;

map< char , char > gToE ;

void init(){

    set<char> st ;
    for( int x = 0 ; x < 3 ; x++ ){
        for( int y = 0 ;y < G[x].size() ; y++ ){
            gToE[ G[x][y] ] = E[x][y] ;
            st.insert( E[x][y] ) ;
        }
    }

    gToE[ 'z' ] = 'q' ;
    gToE[ 'q' ] = 'z' ;
}

int main(){
	init() ;

    char line[1025] ;
    gets( line ) ;

    int cases ;
    sscanf( line , "%d" , &cases ) ;

    for( int cs = 1 ; cs <= cases ; cs++ ){
        gets( line ) ;
        
        for( int x = 0 , nc = strlen( line ) ; x < nc ; ++x )
            line[x] = gToE[ line[x] ] ;

        cout << "Case #" << cs << ": " << string( line ) << endl ;
    }

    return 0 ;
}
