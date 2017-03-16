#include<iostream>
#include<cstdio>
#include<queue>
#include<set>
#include<cstring>
#include<map>
#include<algorithm>
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,b,a) for(int i = (b); i >= (a); --i)
#define clr(a,x) memset(a,(x),sizeof(a))
#define ll long long
#define ull unsigned long long
#define all(o) o.begin(),o.end()
#define eps 1e-6
#define mp make_pair

std::map<int,int> dp[50];
bool vis[50];
int main()
{
    //Getinput(); return 0;
    #ifdef ACM
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif // ACM
    int _T; scanf("%d",&_T);
    rep(cas,1,_T+1) {
        int C, D, V; scanf("%d%d%d",&C,&D,&V);
        rep(i,0,50) dp[i].clear();
        clr(vis,0);
        int s = 1;
        rep(i,0,D) {
            int x; scanf("%d",&x);
            vis[x] = true;
            s |= (s << x);
        }
        s &= (1 << (V+1)) - 1;
        dp[0][s] = 0;
        rep(i,1,V+1) {
            dp[i] = dp[i-1];
            if (!vis[i]) {
                for(auto it : dp[i-1]) {
                    int s = it.first;
                    s |= (s << i);
                    s &= (1 << (V+1)) - 1;
                    auto up = dp[i].find(s);
                    if (up == dp[i].end()) dp[i][s] = it.second + 1;
                    else up->second = std::min(up->second,it.second+1);
                }
            }
        }
        printf("Case #%d: %d\n",cas,dp[V][(1<<(V+1))-1]);
    }
}
