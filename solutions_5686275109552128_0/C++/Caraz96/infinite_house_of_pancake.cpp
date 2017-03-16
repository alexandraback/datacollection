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

const int MAXN = 1010;
int P[MAXN];

int main(){
    int T, tt, i, ans, D, sum, s;
    FILE *fi = fopen( "input.txt", "r" );
    FILE *fo = fopen( "output.txt", "w" );
    fscanf( fi, "%d", &T );
    for( tt = 1; tt <= T; tt++ ){
        fprintf( fo, "Case #%d: ", tt );

        fscanf( fi, "%d", &D );
        for( i = 0; i < D; i++ )
            fscanf( fi, "%d", P+i );
        ans = 10000;
        for( s = 1; s < 2010; s++ ){
            for( sum = i = 0; i < D; i++ )
                sum += ( ((P[i]+s-1)/s)-1 );
            ans = min( ans, sum+s );
        }
        fprintf( fo, "%d\n", ans );
    }
    return 0;
}

#if 0
map<int,int> m;
map<int,int>::iterator it;

int main(){
    int T, tt, i, cut, ans, P, D, x, c;
    FILE *fi = fopen( "input.txt", "r" );
    FILE *fo = fopen( "output.txt", "w" );
    fscanf( fi, "%d", &T );
    for( tt = 1; tt <= T; tt++ ){
        fprintf( fo, "Case #%d: ", tt );
        m.clear();

        fscanf( fi, "%d", &D );
        for( i = 0; i < D; i++ ){
            fscanf( fi, "%d", &P );
            m[P]++;
        }
        x = 100000000; cut = 0;
        ans = INT_MAX;
        while( !m.empty() ){
            it = m.end(); it--;
            x = it->first;
            c = it->second;
            m.erase( it );
            ans = min( ans, x+cut );
            if( x < 4 )break;

            cut += c;
            m[x/2]     += c;
            m[(x+1)/2] += c;
        }
        fprintf( fo, "%d\n", ans );
    }
    return 0;
}
#endif
