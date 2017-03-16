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
#define MAX 1005

int n;
int degree[ MAX ], seen[ MAX ], outdegree[ MAX ];
vector<int> ady[ MAX ];
int possible[ MAX ][ MAX ];
vector<int> last[ MAX ];
void dfs( int source , int x ){
    seen[ x ] = 1;
    for( int i = 0 ; i < ady[ x ].size() ; ++i ){
        if( !seen[ ady[ x ][ i ] ] ){
            possible[ source ][ ady[ x ][ i ] ] = 1;
            dfs( source , ady[ x ][ i ] );
        }
    }
}
int direct[ MAX ][ MAX ];
//int cnt[ MAX ];
bool solve(){
    for( int i = 1 ; i <= n ; ++i ){
        for( int j = 1 ; j <= n ; ++j ){
            if( i != j && possible[ i ][ j ] && degree[ j ] > 1 ){
                //cout<<"pos "<<i<<" "<<j<<endl;
                last[ i ].push_back( j );
            }
        }
    }
    int cnt;
    for( int i = 1 ; i <= n ; ++i ){
        if( outdegree[ i ] > 1 ){
            for( int j = 0 ; j < last[ i ].size() ; ++j ){
                cnt = 0;
                if( direct[ i ][ last[ i ][ j ] ] ) cnt = 1;
                for( int k = 0 ; k < ady[ i ].size() ; ++k ){
                    //cout<<i<<" "<<ady[ i ][ k ]<<" "<<last[ i ][ j ]<<" "<<possible[ ady[ i ][ k ] ][ last[ i ][ j ] ]<<endl;
                    if( possible[ ady[ i ][ k ] ][ last[ i ][ j ] ] ){
                        cnt++;
                        if( cnt > 1 ) {
                            //cout<<i<<" "<<last[ i ][ j ]<<endl;
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}
int main(){

    int t , x ,k ;
    freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
    scanf("%d" , &t );
    for( int q = 1 ; q <= t ; ++q ){
        scanf("%d" , &n );
        memset( degree , 0 , sizeof( degree ) );
        memset( outdegree , 0 , sizeof( outdegree ) );
        memset( direct , 0 , sizeof( direct ) );
        for( int i = 1 ; i <= n ; ++i ){
            scanf("%d" , &k );
            while( k-- ){
                scanf("%d" , &x );
                ady[ i ].push_back( x );
                direct[ i ][ x ] = 1;
                degree[ x ]++;
                outdegree[ i ]++;
            }
        }
        memset( possible , 0 , sizeof( possible ) );
        for( int i = 1 ; i <= n ; ++i ){
                memset( seen , 0 , sizeof( seen ) );
                dfs( i , i );
        }

        printf("Case #%d:" , q  );
        if( solve() ) printf(" Yes");
        else printf(" No");
        printf("\n");
        for( int i = 1 ; i <= n ; ++i ) ady[ i ].clear() , last[ i ].clear();
    }
    return 0;
}
