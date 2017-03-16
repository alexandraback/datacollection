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
#define openfile(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
#define mpr std::make_pair
#define lg(x) (31-__builtin_clz(x))
#define __count __builtin_popcount
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
typedef long long LL;
typedef double LD;
typedef vector<int> VI;
typedef std::pair<int,int> PII;
template<class T>inline void maz(T &a,T b){if(a<b)a=b;}
template<class T>inline void miz(T &a,T b){if(a>b)a=b;}
template<class T>inline T abs(T a){return a>0?a:-a;}
inline int max(int a,int  b){return a>b?a:b;}
/*void RI() {}
template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}*/
const int N=500010,INF=1e9;
const LD EPS=1e-6;
int table[5][5]={
    {},
    {0, 1, 2, 3, 4},
    {0, 2,-1, 4,-3},
    {0, 3,-4,-1, 2},
    {0, 4, 3,-2,-1},
};
struct M{
    int v;
    M(){}
    M(int _v):v(_v){}
    M operator*(const M& a) const{
        int f=1;
        if(v*a.v<0)f=-1;
        return M(f*table[abs(v)][abs(a.v)]);
    }
    void operator*=(const M& a) {
        int f=1;
        if(v*a.v<0)f=-1;
        v = f*table[abs(v)][abs(a.v)];
    }
    bool operator==(const M& a)const {
        return v==a.v;
    }
    bool operator!=(const M& a)const {
        return v!=a.v;
    }
};
int n,m;
int A[N];
VI G[N],rG[N];
char s[N];
LL X;
M total() {
    int r=X%4;
    if(r==0)return M(1);
    M now(1),ans(1);
    FOR(i,n)now*=M(s[i]);
    while(r--)ans*=now;
    return ans;
}
int _find(int v,bool rev=false) {
    M now(1);
    FOR(i,4*n){
        if(!rev)now*=M(s[i%n]);
        else now = M(s[i%n])*now;
        if(now==M(v))return i;
    }
    return -1;
}
int find_k() {
    reverse(s,s+n);
    int r=_find(4,true);
    reverse(s,s+n);
    return r;
}
bool solve() {
    if(total()!=M(-1))return false;
    int fi = _find(2);
    int fk = find_k();
    if(fi==-1 || fk==-1)return false;
    fi++;fk++; // 1base
    if(fi >= X*n || fk >= X*n)return false;
    int c = min(8LL,X);
    FOR(i,c*n)A[i]=0;
    FOR(i,fi)A[i]=1;
    for(int i=c*n-1,j=0;j<fk;j++,i--)if(A[i])return false;
    return true;
}
int main() {
    RID(T);
    int w=1;
    while(T--) {
        RI(n);
        scanf("%lld",&X);
        scanf("%s",s);
        FOR(i,n)s[i]=s[i]-'i'+2;
        printf("Case #%d: %s\n",w++,solve()?"YES":"NO");
    }

    return 0;
}
/*

11
2 1
ik
3 1
ijk
3 1
kji
2 6
ji
1 10000
i
6 1
kkkkkk
2 2
ki
2 3
ki
2 4
ki
2 5
ki
2 6
ki

kik == i

iki == k

*/
