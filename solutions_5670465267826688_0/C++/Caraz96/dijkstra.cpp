#include <cstdlib>
#include <cstdio>
//#include <bits/stdc++.h>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <ctime>
#include <cfloat>
#include <cassert>
#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>

#include <queue>
#include <deque>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <bitset>

/*
#include <random>
#include <unordered_map>
#include <unordered_set>
*/
const long double eps=1e-9;

#define pb push_back
#define mp make_pair
#define sz( a ) ( (int) a.size() )
using namespace std;

#if 0
#define what_is( _X ) cerr << #_X << " is " << _X << endl;
#define gcd( _a, _b ) __gcd( _a, _b )
inline int sum(){ return 0; }
template < typename... Args >
int sum( int _a, Args... _args ){return _a + sum( _args... );}
#endif

template < class T >inline T MAX (const T &_a, const T &_b){return ((_a>_b)?_a:_b);}
template < class T >inline T MIN (const T &_a, const T &_b){return ((_a<_b)?_a:_b);}
template < class T >inline T MAX3(const T &_a, const T &_b, const T &_c){return MAX(MAX(_a,_b),_c);}
template < class T >inline T MIN3(const T &_a, const T &_b, const T &_c){return MIN(MIN(_a,_b),_c);}
template < class T >inline T MAX4(const T &_a, const T &_b, const T &_c, const T &_d){return MAX(MAX3(_a,_b,_c),_d);}
template < class T >inline T MIN4(const T &_a, const T &_b, const T &_c, const T &_d){return MIN(MIN3(_a,_b,_c),_d);}
template < class T >inline T ABS (const T &_a){return ((_a<0)?-_a:_a);}
template < class T >inline T SQR (const T &_a){return _a*_a;}
template < class T >inline T gcd(T _a,T _b){for(T _r;(_r=_a%_b);_b=_r)_a=_b;return _b;}
template < class T >inline T lcm(const T &_a,const T &_b){return (_a/gcd(_a,_b))*_b;}
template < class T >inline bool BETW(const T&_a,const T&_b,const T&_c){return (_a>=MIN(_b,_c)&&_a<=MAX(_b,_c));}
template < class T >inline bool EXT (const T&_a,const T&_b,const T&_c){return !BETW(_a,_b,_c);}


#define oo 1
#define ii 2
#define jj 3
#define kk 4
const int MAXN = 10010;
int p[MAXN];
char S[MAXN];
int mat[][4] = { { oo, ii, jj, kk },
                 { ii, -oo, kk, -jj },
                 { jj, -kk, -oo, ii },
                 { kk, jj, -ii, -oo } };

int mat1[][4] = { { oo, -ii, -jj, -kk },
                  { ii, oo, kk, -jj },
                  { jj, -kk, oo, ii },
                  { kk, jj, -ii, oo } };

inline int prod( int val, char c ){
    int A = abs(val), s = ((val<0)?-1:1);
    if( c == 'i' )return s*mat[A-1][ii-1];
    if( c == 'j' )return s*mat[A-1][jj-1];
    return s*mat[A-1][kk-1];
}
inline int division( int val, int val1 ){
    return mat1[abs(val)-1][abs(val1)-1]*((val<0)?-1:1)*((val1<0)?-1:1);
}

int main(){
    int T, tt, i, j, X, L, l;
    bool ans;
    FILE *fi = fopen( "input.txt", "r" );
    FILE *fo = fopen( "output.txt", "w" );
    fscanf( fi, "%d", &T );
    for( tt = 1; tt <= T; tt++ ){
        fprintf( fo, "Case #%d: ", tt );
        fscanf( fi, "%d %d\n%s", &L, &X, S );
        l = L; X--;
        while(X){
            memcpy( S+l, S, L );
            l += L;
            X--;
        }
        L = l;

        if( S[0] == 'i' )p[0] = ii;
        if( S[0] == 'j' )p[0] = jj;
        if( S[0] == 'k' )p[0] = kk;

        for( i = 1; i < L; i++ )
            p[i] = prod( p[i-1], S[i] );

        ans = false;
        for( i = 0; i < L && !ans; i++ ){
            if( p[i] == ii ){
                for( j = i+1; j < L-1 && !ans; j++ ){
                    if( division( p[j], p[i] ) == jj && division( p[L-1], p[j] ) == kk )
                        ans = true;
                }
            }
        }
        if( ans )fputs( "YES\n", fo );
        else fputs( "NO\n", fo );
    }
    return 0;
}
