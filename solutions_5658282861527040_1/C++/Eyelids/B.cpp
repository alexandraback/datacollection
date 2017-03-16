/*
 * Author:  Eyelids
 * Created Time:  2014/5/4 0:37:47
 * File Name: B.cpp
 */
#include<iostream>
#include<sstream>
#include<fstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
using namespace std;
const double eps(1e-8);
typedef long long lint;
#define clr(x) memset( x , 0 , sizeof(x) )
#define sz(v) ((int)(v).size())
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repf(i, a, b) for (int i = (a); i <= (b); ++i)
#define repd(i, a, b) for (int i = (a); i >= (b); --i)
#define clrs( x , y ) memset( x , y , sizeof(x) )
typedef unsigned long long LL;
int a, b, k;
LL f[33][2][2][2];
LL Dfs( int p, int equA, int equB, int equK ) {
    if ( p == -1 ) return 1;
    if ( f[p][equA][equB][equK] ) return f[p][equA][equB][equK];
    
    int A = ( equA ) ? (( a >> p ) & 1) : 1;
    int B = ( equB ) ? (( b >> p ) & 1) : 1;
   
    int ret = 0; 
    int equ1, equ2;
    for ( int i = 0; i <= A; i ++ )
        for ( int j = 0; j <= B; j ++ ) {
            if ( (( a >> p ) & 1) == i ) equ1 = equA; else equ1 = 0;
            if ( (( b >> p ) & 1) == j ) equ2 = equB; else equ2 = 0;
            
            if ( equK ) {
                if ( (i & j) == (( k >> p ) & 1) )       
                    ret += Dfs( p - 1, equ1, equ2, 1 );
                else if ( ( i & j ) < ((k >> p) & 1) )
                    ret += Dfs( p - 1, equ1, equ2, 0 );
            } else {
                ret += Dfs( p - 1, equ1, equ2, 0 );
            }
        }
   
    f[p][equA][equB][equK] = ret;
   
    /*if ( p <= 2 ) {
        cout <<(( a >> p ) & 1)<<" "<<(( b >> p ) & 1)<<" "<<((k >> p) & 1)<<endl; 
        cout <<p<<" "<<equA<<" "<<equB<<" "<<equK<<" "<<ret<<endl;
    }*/
    return ret; 
}

int main() {
    freopen( "B.in", "r", stdin );
    freopen( "B.out", "w", stdout );
    
    int T;
    scanf( "%d", &T );
    int cas = 0;
    while ( T -- ) {
        scanf( "%d%d%d", &a, &b, &k );
     
        a --, b --; 
        k --; 
        memset( f, 0, sizeof(f) );
        LL ret = Dfs( 30, 1, 1, 1 );
        
        printf( "Case #%d: ", ++ cas );
        cout <<ret<<endl;
    }
    
    return 0; 
}









