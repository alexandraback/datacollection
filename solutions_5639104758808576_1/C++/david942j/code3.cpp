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
int n,m;
int A[N];
VI G[N],rG[N];
char s[N];
int main() {
    RID(T);
    int w=1;
    while(T--) {
        RI(n);
        scanf("%s",s);
        FOR(i,n+1)A[i]=s[i]-'0';
        FOR1(i,n)A[i]+=A[i-1];
        int ans=0;
        FOR1(i,n)maz(ans,i-A[i-1]);
        printf("Case #%d: %d\n",w++,ans);
    }

    return 0;
}
/*

*/
