// Google Code Jam Template by rabbit125 @2014/02/13
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cstring>
#include <cmath>
#include <map>
#include <stack>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include <climits>
#include <bits/stdc++.h>
using namespace std ;
/* Define Useful Vars. */
#define ULL  unsigned long long
#define LLI  long long
#define BIT         17
#define INF 1000000000
#define MOD 1000000007
#define MAX      12000
LLI A , B , K ;
int main( )
{
    freopen( "B-small-attempt0.in" , "r" , stdin ) ;
    freopen( "B-s0.out" , "w" , stdout ) ;
    int t , T = 1 ;
    scanf( "%d" , &t ) ;
    while( t-- )
    {

        int ans = 0 ;
        scanf( "%d%d%d" , &A , &B , &K ) ;
        for( int i = 0 ; i < A ; i++ )
            for( int j = 0 ; j < B ; j++ )
                if( (i&j) < K )
                {
                    ans++ ;
                }
        printf( "Case #%d: %d\n" , T++ , ans ) ;
    }
    return 0 ;
}
/*
5
3 4 2
4 5 2
7 8 5
45 56 35
103 143 88
*/
/*
Case #1: 10
Case #2: 16
Case #3: 52
Case #4: 2411
Case #5: 14377
*/
