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
LL n;
int A[N];

int dp[N],par[N];
void go(int n){
    if(n==-1)return;
    go(par[n]);
    printf("%d ",n);
}
LL reverse(LL c) {
    LL a=0;
    while(c){
        a=a*10+c%10;
        c/=10;
    }
    return a;
}
int len(LL a) {
    int ret=0;
    while(a){ret++;a/=10;}
    return ret;
}
char tmp[100];
LL solve(LL now,LL n) { // 10000 41232
    if(len(now) != len(n)){
        return solve(now,now*10-1)+1+solve(now*10,n);
    }
    int l = len(now);
    sprintf(tmp,"%lld",n);
    LL k=0;
    LL a=now;
    LL best = n-now;
    for(int i=0;i<l-1;i++) {
        k=k*10+tmp[i]-'0';  // 41
        LL p = reverse(k); // 14
        if(n-(n/a*a+1) < 0)continue;
        LL ans = p+1+(n-(n/a*a+1)); //41001 ~ 41232
        a/=10;
        miz(best,ans);
    }
    return best;
}
int main() {
    int w=1;
    dp[1]=0;
    par[1]=-1;
    for(int i=1;i<N-1;i++) {
        int a=reverse(i);
        if(a<i)assert(dp[a] <= dp[i]+1);
        if(a>i && a<N){
            if(dp[a]==0 || dp[a] > dp[i]+1){
                dp[a]=dp[i]+1;
                par[a]=i;
            }
        }
        if(dp[i+1]==0 || dp[i+1] > dp[i]+1){
            dp[i+1]=dp[i]+1;
            par[i+1]=i;
        }
    }
    //go(30);
    /*for(int i=1;i<N;i++){
        if(dp[i]!=solve(1,i))
            return printf("%d\n",i);
        //assert(dp[i]==solve(1,i));
    }*/
    RID(T);
    while(T--) {
        scanf("%lld",&n);
        //LL ans = solve(1,n);
        //printf("%lld %lld\n",ans,dp[n]);
        //assert(dp[n] == ans);
        printf("Case #%d: %d\n",w++,dp[n]+1);
    }

    return 0;
}
/*
0 + 9 + 19 + 109 + 199 + 1099
10000 41299 
*/
