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
int p,q,r,k;
bool A[N];
VI ans;
int f[30][30], u[30][30];
int use[11][11];
bool flag[30];
bool DFS(int x, int t,int n) {
    //printf("%d\n",x);
    flag[x]=true;
    if(x==t)
        return true;
    FOR(i,n) if(!flag[i] && f[x][i] > 0)
        if(DFS(i,t,n)) {
            f[x][i]--;
            f[i][x]++;
            return true;
        }
    return false;
}
void flow(int s,int t,int n) {
    mst(flag);
    while(DFS(s,t,n))mst(flag);
}
void work(int a) {
    int s=0,t=q+r+1;
    FOR1(i,q) FOR1(j,r) f[i][j+q] = (use[i][j] < k),f[j+q][i] = 0;
    FOR1(i,q) f[s][i] = k, f[i][s] = 0;
    FOR1(j,r) f[j+q][t]=k,f[t][j+q]=0;
    memcpy(u, f, sizeof(f));
    flow(s,t,t+1);
    FOR1(i,q)FOR1(j,r) if(u[i][j+q] - f[i][j+q] > 0) {
        use[i][j] ++;
        ans.pb(a*256+i*16+j);
    }
}
int main() {
    RID(T);
    FOR1(w,T) {
        R(p,q,r,k);
        ans.clear();
        mst(use);
        mst(f);
        FOR1(i,q) FOR1(j,r) f[i][j+q] = k;
        printf("Case #%d: ",w);
        FOR1(i,p) {
            work(i);
        }
        printf("%d\n",ans.size());
        for(auto c: ans)
            printf("%d %d %d\n", c/256, (c/16) & 15, c&15);
    }
    return 0;
}
/*

*/