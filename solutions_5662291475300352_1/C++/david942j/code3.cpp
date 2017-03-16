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
const int N=1000010,INF=1e9;
const LD EPS=1e-6;

int m;
int G,n;
int A[N];
vector<PII>V;
void gen(int d,int h,int m) {
    FOR(i,h)V.pb(mpr(d,m+i));
}
LD end(PII a){
    return (360.0-a.X)/360.0*a.Y;
}
LD e[N];
int solve() {
    sort(ALL(V));
    if(V.size()==1)return 0;
    if(V.size()==2) {
        int m1=V[0].Y;
        int m2=V[1].Y;
        if(m1==m2)return 0;
        LD e1 = end(V[0]);
        LD e2 = end(V[1]);
        if(e1 <= e2 ){
            if(e2 < e1+m1)return 0;
            return 1;
        }
        else {
            if(e1 < e2+m2) return 0;
            return 1;
        }
    }
    FOR(i,V.size()) {
        e[i] = end(V[i]);
    }
    int ans=V.size()-1;
    FOR(i,V.size()){
        int tmp=0;
        FOR(j,V.size())if(e[j] > e[i])tmp++;
        else if(e[j]!=e[i]) {
            tmp+=(e[i]-e[j])/V[j].Y;
            if(tmp>ans)break;
        }
        miz(ans,tmp);

    }
    return ans;
}
int main() {
    int w=1;
    RID(T);
    while(T--) {
        RI(G);
        V.clear();
        FOR(i,G){
            int d,h,m;
            RI(d);
            RI(h);
            RI(m);
            gen(d,h,m);
        }
        int ans=solve();
        printf("Case #%d: %d\n",w++,ans);
    }

    return 0;
}
/*
0 + 9 + 19 + 109 + 199 + 1099
10000 41299 
9999999999999
*/
