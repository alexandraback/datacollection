//by david942j
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <deque>
#include <cassert>
#include <queue>
#include <stack>
#include <cstdlib>
#ifndef DAVID
#include <bits/stdc++.h>
#endif
#define openfile(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
#define mpr std::make_pair
#define lg(x) (31-__builtin_clz(x))
#define lgll(x) (63-__builtin_clzll(x))
#define __count __builtin_popcount
#define __countll __builtin_popcountll
#define X first
#define Y second
#define mst(x) memset(x,0,sizeof(x))
#define mst1(x) memset(x,-1,sizeof(x))
#define ALL(c) (c).begin(),(c).end()
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR1(i,n) for(int i=1;i<=n;i++)
#define FORit(it,c) for(__typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define pb push_back
#define RI(x) scanf("%d",&x)
#define RID(x) int x;RI(x)
using namespace std;
template<typename T>
void _R( T &x ) { cin>>x; }
void _R( int &x ) { scanf("%d",&x); }
#ifdef PRId64
void _R( long long &x ) { scanf("%" PRId64,&x); }
#else
void _R( long long &x) {cin >> x;}
#endif
void _R( double &x ) { scanf("%lf",&x); }
void _R( char &x ) { scanf(" %c",&x); }
void _R( char *x ) { scanf("%s",x); }

void R() {}
template<typename T, typename... U>
void R( T& head, U&... tail ) {
    _R(head);
    R(tail...);
}

template<typename T>
void _W( const T &x ) { cout<<x; }
void _W( const int &x ) { printf("%d",x); }
template<typename T>
void _W( const vector<T> &x ) {
    for ( auto i=x.cbegin(); i!=x.cend(); i++ ) {
        if ( i!=x.cbegin() ) putchar(' ');
        _W(*i);
    }
}

void W() {}
template<typename T, typename... U>
void W( const T& head, const U&... tail ) {
    _W(head);
    putchar(sizeof...(tail)?' ':'\n');
    W(tail...);
}
#ifdef DAVID
#define debug(format, ...) fprintf(stderr, format, ##__VA_ARGS__)
#else
#define debug(...)
#endif
typedef long long LL;
typedef double LD;
typedef vector<int> VI;
typedef std::pair<int,int> PII;
template<class T>inline void maz(T &a,T b){if(a<b)a=b;}
template<class T>inline void miz(T &a,T b){if(a>b)a=b;}
template<class T>inline T abs(T a){return a>0?a:-a;}

const int N=100;
const int INF=1e9+7;
int n;
LL m;
bool A[N];
int main() {
    RID(T);
    FOR1(w,T) {
        RI(n);
        scanf("%lld", &m);
        int Max = 1LL << (n-2);
        printf("Case #%d: ", w);
        if(Max < m) {puts("IMPOSSIBLE");continue;}
        puts("POSSIBLE");
        mst(A);
        if(m==Max) {
            FOR1(i,n-1) A[i] = true;
        }
        else {
            for(int i=2;i<n;i++)
                if(m & (1LL<<(i-2))) A[i]=true;
        }
        FOR1(i,n)FOR1(j,n) {
            if(j==n) puts(A[i] ? "1":"0");
            else putchar(i<j ? '1':'0');
        }
    }
    return 0;
}
/*

*/