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
//#include <time.h>
using namespace std;
#define MAX 10005
int a[ MAX ], mp[ MAX ] , n;

void reduce( int x ){
    for( int i = 1  ; i < MAX ; ++i ){
        mp[ i - 1 ] = mp[ i ];
    }
}

int getMax(){
    for( int i = MAX - 1 ; i >= 0 ; --i ){
        if( mp[ i ] )
            return i;
    }
    return -1;
}

int main() {
    //srand (time(NULL));
    int t, n, maxi, mini, sum ;
    scanf("%d", &t) ;
    for( int q = 1 ; q <= t && scanf("%d" , &n ) ; ++q ){
        maxi = 0;
        for( int i = 0 ; i < n && scanf("%d", &a[i]) ; ++i ) {
            //a[i] = rand() % 1000 + 1;
            maxi = max( maxi , a[i] );
        }
        mini = maxi;
        for( int i = 1 ; i <= maxi ; ++i ) {
            sum = i;
            for( int j = 0 ; j < n ; ++j ) {
                if( a[j] > i ) {
                    sum += a[j]/i;
                    if( a[j] % i == 0 )
                        sum--;
                }
            }
            mini = min( mini , sum ) ;
        }
        printf("Case #%d: %d\n", q , mini) ;
    }
    return 0 ;
}
