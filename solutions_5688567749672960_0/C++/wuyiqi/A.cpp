#include <bits/stdc++.h>
using namespace std;
int dp[1000100];
bool vis[1000010];
int n;
int main()
{
 freopen("A-small-attempt1.in","r",stdin);
 freopen("out.txt","w",stdout);
    memset(dp ,-1,sizeof(dp));
    dp[0] = 0;
    queue<int> Q;
    Q.push(0);
    n = 1000000;
    while(!Q.empty()) {
        int x  = Q.front(); Q.pop();
        if(x+1<=n && dp[x + 1] == -1 ) {
            dp[x + 1] = dp[x] + 1;
            Q.push(x + 1);
        }
        int y = x;
        vector<int> v;
        v.push_back(y);
        vis[y] = true;
        int num;
        while(true) {
            num = y;
            int dig[10],tot=0;
            for(;num;num/=10) dig[tot++]=num%10;
            y = 0;
            for(int i = 0; i < tot; i++) y = y * 10 + dig[i];
            if(!vis[y]) {
                vis[y] = true;
                v.push_back(y);
            } else {
                break;
            }
            if(y <= n && dp[y] == -1) {
                dp[y] = dp[x] + 1;
                Q.push(y);
            }
        }
        for(int i = 0; i < (int)v.size(); i++) vis[v[i]] = false;
    }
    int t,ca=1;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        printf("Case #%d: %d\n", ca++, dp[n]);
    }
    return 0;
}
