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
#define MAX 10005
int a[ MAX ] , n , aux[ MAX ];
vector<int> mp;
void reduce( int x ){
    for( int i = 1  ; i < MAX ; ++i ){
        mp[ i - 1 ] = mp[ i ];
        //if( mp[ i ] != 0 )
        //    mp[ i ] -= x;
    }
}

int getMax( vector<int> mp ){
    for( int i = MAX - 1 ; i >= 0 ; --i ){
        if( mp[ i ] )
            return i;
    }
    return -1;
}


int solve( vector<int> mp ){
/*
    for( int i = 0 ; i < 5 ; ++i )
        cout<<mp[ i ]<<" ";
    cout<<endl;*/

    int maxi = getMax( mp );
    if( maxi <= 0 ){
        return 0;
    }
    int tot = 0;
    vector<int> aux = mp;
    //memcpy( aux , mp , sizeof( mp ) );
    //reduce(1);
    for( int i = 1 ; i < MAX ; ++i  ){
        mp[ i - 1 ] = mp[ i ];
    }
    tot = 1 + solve( mp );
    mp = aux;
    /*for( int i = 1 ; i < MAX ; ++i ){

    }*/
   // memcpy( mp , aux , sizeof( aux ) );
/*
    cout<<"test"<<endl;
    for( int i = 0 ; i < 5 ; ++i )
        cout<<mp[ i ]<<" ";
    cout<<endl;*/

    int tmp = mp[ maxi ];
    //cout<<maxi<<" "<<tmp<<" "<<getMax()<<endl;
    mp[ maxi ] = 0;
    for( int i = 1 ; i <= maxi/2 ; ++i ){
        mp[ i ] += tmp;
        mp[ maxi - i ] += tmp;
        //cout<<i<<" ---- "<<maxi - i<<endl;
        tot = min( tot , tmp + solve(mp) );
        mp[ i ] -= tmp;
        mp[ maxi - i ] -= tmp;
    }
    mp[ maxi ] = tmp;
    return tot;
    //tot += mp[ maxi ];
    //int cnt = 2 * mp[ maxi ];
    //mp[ maxi ] = 0;
    //mp[ maxi/2 ] += cnt;
}

int main(){
    int t, q;
    //freopen( "input.txt", "r", stdin );
	//freopen( "output.txt", "w", stdout );
    scanf("%d" , &t );
    for( q = 1 ; q <= t && scanf("%d" , &n ) ; ++q ){
        //memset( mp , 0 , sizeof( mp ) );
        mp.clear();
        mp = vector<int>( MAX , 0 );
        int tot = 0, maxi = 0;
        for( int i = 0 ; i < n && scanf("%d" , &a[i] ) ; ++i ){
            mp[ a[i] ]++;
            //maxi = max( maxi , mp[ a[i] ] );
        }
/*
        maxi = getMax();

        while( maxi > 0 ){
            if( maxi & 1 ){
                tot++;
                reduce( 1 );
            }else if( maxi/2 + mp[ maxi ] < maxi ){
                tot += mp[ maxi ];
                int cnt = 2 * mp[ maxi ];
                mp[ maxi ] = 0;
                mp[ maxi/2 ] += cnt;
            }else{
                tot++;
                reduce(1);
            }
            //cout<<maxi<<" "<<tot<<endl;
            maxi = getMax();
            //cout<<maxi<<endl;
        }*/

        printf("Case #%d: %d\n" , q , solve( mp )  );
        //printf("Case #%d: %d\n" , q , tot  );
    }
    return 0;
}
