#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;
int t, n, m;
P a[100], b[100];
ll dp[101][101][2];
ll dfs(int i, int j, int k) {
    if (dp[i][j][k]!=-1) return dp[i][j][k];
    if (i>=n||j>=m) return 0;
    ll temp=0;
    if (a[i].second==b[j].second) temp=min(a[i].first, b[j].first);
    a[i].first-=temp; b[j].first-=temp;
    ll x=dfs(i+1,j,0), y=dfs(i,j+1,0), z=dfs(i+1,j+1,0);
    a[i].first+=temp; b[j].first+=temp;
    ll x1=dfs(i+1,j,1), y1=dfs(i,j+1,1), z1=dfs(i+1,j+1,1);
    dp[i][j][k]=max(max(x,max(y,z))+temp, max(x1,max(y1,z1)));
    //printf("%d %d %lld (%lld %d %d) (%lld %lld)\n",i,j,dp[i][j][k],temp,a[i].second,b[j].second,a[i].first,b[j].first);
    return dp[i][j][k];
}
int main() {
    scanf("%d",&t);
    for (int ix=1; ix<=t; ix++) {
        scanf("%d%d",&n,&m);
        memset(dp,-1,sizeof(dp));
        for (int i=0; i<n; i++) {
            scanf("%lld%d",&a[i].first,&a[i].second);
        }
        for (int i=0; i<m; i++) {
            scanf("%lld%d",&b[i].first,&b[i].second);
        }
        printf("Case #%d: %lld\n",ix,dfs(0,0,0));
    }
}
