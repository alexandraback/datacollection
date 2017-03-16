#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>

using namespace std;
#define MAX 15

struct Data{
    int a ,b , c;
    Data( int aa ){
        b = 1; c = 1;
        a = aa;
    }
    Data( int aa , int bb ){
        a = aa; b = bb; c = 1;
    }
    Data( int aa , int bb , int cc ) : a( aa ) , b( bb ) , c( cc ){}
    Data(){}
};

vector< Data > v;
int R , N , M , K;

void gen(){
    int i;
    for( i = 2 ; i <= M ; ++i ) v.push_back( Data( i ) );
}

void gen2(){
    int i , j;
    for( i = 2 ; i <= M ; ++i ){
        for( j = 2 ; j <= M ; ++j ){
            v.push_back( Data( i , j ) );
        }
    }
}

void gen3(){
    int i , j , k;
    for( i = 2 ; i <= M ; ++i ){
        for( j = 2 ; j <= M ; ++j ){
            for( k = 2 ; k <= M ; ++k ){
                v.push_back( Data( i , j , k ) );
            }
        }
    }
}
int p[ MAX ];

bool possible( Data act ){
    set< int > s;
    s.insert( act.a ); s.insert( act.b ); s.insert( act.c );
    s.insert( act.a * act.b ); s.insert( act.a * act.c );
    s.insert( act.b * act.c ); s.insert( act.a * act.b * act.c );
    int i , j;
    for( i = 0 ; i < K ; ++i ){
        if( p[ i ] == 1 ) continue;
        if( s.find( p[ i ] ) == s.end() ) return false;
    }
    return true;
}

int main(){
    int t, q , i,  j;
    freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );

    scanf("%d" , &t );
    for( q = 1 ; q <= t && scanf("%d %d %d %d" , &R , &N , &M , &K ); ++q ){
        printf("Case #%d:\n" , q  );
        if( N == 1 ) gen( );
        else if( N == 2 ) gen2();
        else gen3();
        for( i = 0 ; i < R ; ++i ){
            for( j = 0 ; j < K && scanf("%d" , &p[ j ] ) ; ++j );
            vector< Data > aux;
            for( j = 0 ; j < v.size() ; ++j ){
                if( possible( v[ j ] ) ) aux.push_back( v[ j ] );
            }
            if( N == 1 ){
                aux.push_back( Data( 2 ) );
                printf("%d\n" , aux[ 0 ].a );
            }
            else if( N == 2 ){
                aux.push_back( Data( 2 , 2 ) );
                printf("%d%d\n" , aux[ 0 ].a , aux[ 0 ].b );
            }
            else{
                aux.push_back( Data( 2 , 2 , 2 ) );
                printf("%d%d%d\n" , aux[ 0 ].a  , aux[ 0 ].b , aux[ 0 ].c );
            }
        }
    }
    return 0;
}
