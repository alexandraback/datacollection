#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;
typedef map<pair<ll,ll>,ll> tp;

int N,M;
ll a[101],b[101];
int A[102],B[102],cnt;
tp dp[101][101];

ll solve (int i,int j,ll x,ll y) {
    if (i>N || j>M) return 0;
    tp::iterator I = dp[i][j].find(make_pair(x,y));
    if (I!=dp[i][j].end()) return I->second;
    if (A[i]!=B[j]) {
       ll res=max(solve(i+1,j,a[i+1],y),solve(i,j+1,x,b[j+1]));
       dp[i][j][make_pair(x,y)]=res;
       return res;
    }
    if (x>y) {
       ll res=y + solve(i,j+1,x-y,b[j+1]);
       dp[i][j][make_pair(x,y)]=res;
       return res;
    }
    if (x<y) {
       ll res = x + solve(i+1,j,a[i+1],y-x);
       dp[i][j][make_pair(x,y)]=res;
       return res;
    }
    ll res=x + solve(i+1,j+1,a[i+1],b[j+1]);
    dp[i][j][make_pair(x,y)]=res;
    return res;
}

int main () {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int z=1;z<=T;++z) {
    scanf("%d %d",&N,&M);
    for (int i=1;i<=N;++i) for( int j=1;j<=M;++j) dp[i][j].clear();
    for (int i=1;i<=N;++i) scanf("%lld %d",&a[i],&A[i]);
    for (int i=1;i<=M;++i) scanf("%lld %d",&b[i],&B[i]);
    printf("Case #%d: %lld\n",z,solve(1,1,a[1],b[1]));
    }
    return 0;
}
