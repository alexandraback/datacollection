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
#define MAX 105
int n , m ;
long long a[ MAX ] , A[ MAX ] , b[ MAX ] , B[ MAX ];
long long maxi;
void solve( int box , int toys , long long sum ){
    //cout<<box<<" "<<toys<<" "<<sum<<" "<<A[ box ]<<" "<<B[ toys ]<<" "<<a[ box ]<<" "<<b[ toys ]<<endl;
    maxi = max( sum , maxi );

    /*if( box == n || toys == m ){
        maxi = max( sum , maxi );
        return;
    }*/
    long long resp = 0 , mini = 0;
    if( A[ box ] == B[ toys ] ) {
        mini = min( a[ box ] , b[ toys ] );
        resp = min( a[ box ] , b[ toys ] );
        a[ box ] -= mini;
        b[ toys ] -= mini;
    }
    maxi = max( resp + sum , maxi );
    //bool bb = false , cc = false;
    if( box + 1 < n ){
        solve( box + 1 , toys , resp + sum );
        /*a[ box ] += mini;
        b[ toys ] += mini;
        bb = true;*/
    }
    //a[ box ] += resp;
    //b[ toys ] += resp;
    if( toys + 1 < m ){
        /*if( bb ){
            //solve( box , toys + 1 , resp + sum );
            a[ box ] -= mini;
            b[ toys ] -= mini;
        }*/
        solve( box , toys + 1 , resp + sum );
        /*a[ box ] += mini;
        b[ toys ] += mini;
        cc = true;*/
    }
    /*if( cc ){
        a[ box ] -= mini;
        b[ toys ] -= mini;
    }*/
    a[ box ] += mini;
    b[ toys ] += mini;
}

int main(){

    int t;
    long long ans;
    freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
    scanf("%d" , &t );

    for( int q = 1 ; q <= t ; ++q ){
        ans = 0;

        scanf("%d %d" , &n  , &m );

        for( int i = 0 , j = 0; i < 2 * n ; i += 2 ){
            scanf("%lld %lld" , &a[ j ] , &A[ j ] );
            j++;
        }
        for( int i = 0 , j = 0; i < 2 * m ; i += 2 ){
            scanf("%lld %lld" , &b[ j ] , &B[ j ] );
            j++;
        }

        //for( int i = 0 ; i < m ; ++i ) cout<<b[ i ]<<" "<<B[ i ]<<endl;
        maxi = 0;
        solve( 0 , 0 , 0LL );
       // cout<<"Case #"<<q<<": "<<maxi<<endl;
        printf("Case #%d: %lld\n" , q , maxi );
    }
    return 0;
}
