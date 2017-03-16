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
#define MAX 1005
#define pii pair<long long , long long>
#define mp make_pair
int a[ MAX ];
map<long long , bool> seen;

long long reverseNum( long long x ){
    long long num = 0;
    while( x > 0 ){
        num = num * 10 + x % 10;
        x /= 10;
    }
    return num;
}

long long bfs( long long end ){
    seen.clear();
    queue<pii> Q;
    Q.push( mp(1 , 1) );
    seen[ 1 ] = 1;
    while( !Q.empty() ){
        long long act = Q.front().first;
        long long d = Q.front().second; Q.pop();
        //if( act > end )
        //    continue;
        if( act == end )
            return d;
        if( !seen[ act + 1 ] ){
            seen[ act + 1 ] = 1;
            Q.push( mp(act + 1 , d + 1) );
        }
        long long num = reverseNum( act );
        if( !seen[ num ] ){
            seen[ num ] = 1;
            Q.push( mp( num , d + 1 ) );
        }
    }
    return -1;
}


int main() {
    //srand (time(NULL));
    int t;
    long long n;
    scanf("%d", &t) ;
    for( int q = 1 ; q <= t && scanf("%lld" , &n ) ; ++q ){
        printf("Case #%d: %lld\n", q , bfs( n ) );
    }
    return 0 ;
}
