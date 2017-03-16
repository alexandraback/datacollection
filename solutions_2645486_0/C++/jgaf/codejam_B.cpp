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
int E , R , n , a[ MAX ] , maxi;

void solve( int len , int e , int sum ){

    if( len == n ){
        maxi = max( maxi , sum );
        return;
    }
    int  i , j;
    for( j = 0 ; j <= e ; ++j ){
        solve( len + 1 , min( E , e - j + R ) , sum + j * a[ len ] );
    }

    return;
}

int main(){
    int t, q , i,  j;
    freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
    scanf("%d" , &t );
    for( q = 1 ; q <= t && scanf("%d %d %d"  ,&E , &R , &n ); ++q ){
        for( i = 0 ; i < n && scanf("%d" , &a[ i ] ) ; ++i );
        maxi = 0; solve( 0 , E , 0 );
        printf("Case #%d: %d\n" , q , maxi  );
    }
    return 0;
}
