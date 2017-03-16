#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1e6+10;
int vis[N];

ll rev(ll x) {
    ll p=1, ret=0;
    char buf[111];
    sprintf(buf, "%lld", x);
    int n=strlen(buf);
    for(int i=0; i<n; i++) {
        ret+=p*(buf[i]-'0');
        p*=10;
    }
    return ret;
}

int main() {
    int t, T=1;
    ll n;
    scanf("%d", &t);
    while(t--) {
        scanf("%lld", &n);
        queue<ll> q;
        memset(vis, 0, sizeof(vis));
        vis[1]=1;
        q.push(1);
        if(n!=1) {
            while(!q.empty()) {
                ll u=q.front();
                q.pop();
                if(!vis[u+1]) {
                    vis[u+1]=vis[u]+1;
                    if(u+1==n) break;
                    q.push(u+1);
                }
                ll v=rev(u);
                if(!vis[v]) {
                    vis[v]=vis[u]+1;
                    if(v==n) break;
                    q.push(v);
                }
            }
        }
        printf("Case #%d: %d\n", T++, vis[n]);
    }
    return 0;
}
