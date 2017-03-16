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

#define llint long long
#define vi vector<int>
#define ii pair<int, int>
#define iii pair<int, ii>
#define iiii pair<ii,ii>
#define vii vector<ii>
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

int main(){
    int T, tt, X, R, C;
    FILE *fi = fopen( "input.txt", "r" );
    FILE *fo = fopen( "output.txt", "w" );
    fscanf( fi, "%d", &T );
    for( tt = 1; tt <= T; tt++ ){
        fprintf( fo, "Case #%d: ", tt );
        fscanf( fi, "%d%d%d", &X, &R, &C );

        if( X > 2*min( R, C ) ){ fputs( "RICHARD\n", fo ); continue; }
        if( X >= 2*min( R, C ) && R == C ){ fputs( "RICHARD\n", fo ); continue; }
        if( X > 6 ){ fputs( "RICHARD\n", fo ); continue; }
        if( X > max( R, C ) ){ fputs( "RICHARD\n", fo ); continue; }
        if( (R*C)%X ){ fputs( "RICHARD\n", fo ); continue; }
        if( X == 4 && min( R, C ) == 2 && max( R, C ) == 4 ){ fputs( "RICHARD\n", fo ); continue; }
        fputs( "GABRIEL\n", fo );

    }
    return 0;
}
