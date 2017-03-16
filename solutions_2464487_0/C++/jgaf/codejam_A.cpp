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

int main(){
    int T, q , i;
    long long r , t , j;
    freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
    scanf("%d" , &T );
    for( q = 1 ; q <= T && scanf("%lld %lld" , &r , &t ) ; ++q ){
        printf("Case #%d: " , q  );
        long long sum = 0 , val;
        for( i = 1 , j = 1 ; ; ++i ){
            val = ( ( r + j ) * ( r + j ) - ( r - 1 + j ) * ( r - 1 + j ) );
            if( sum + val > t ) break;
            sum += val;
            j += 2;
        }
        printf("%d\n" , i - 1 );

    }
    return 0;
}
