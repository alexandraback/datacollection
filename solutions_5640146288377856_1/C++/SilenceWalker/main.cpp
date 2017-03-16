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
const int maxn = 1<<20;
const int inf = 1e6;
int W, R, C;

std::map<int,int> dp;
std::map<int,int> dpdp[20];

inline int getBit(int s,int pos)
{
    return (s & (3 << (pos * 2))) >> (pos * 2);
}

bool possible(int s)
{
    if (s == 85)
        char a='a';
    int l = -1, r = -1;
    rep(j,0,C) if (getBit(s,j) == 3) {
        if (l == -1) l = j;
        r = j;
    }
    if (r - l + 1 > W) return false;
    rep(j,l,r) if (getBit(s,j) == 1)
        return false;
    int len = 0, maxlen = 0;
    rep(j,0,C) {
        if (getBit(s,j) != 1) ++len;
        else len = 0;
        if (maxlen < len) maxlen = len;
    }
    if (maxlen < W) return false;
    return true;
}

bool Ok(int s)
{
    int l = -1, r = C;
    rep(j,0,C) if (getBit(s,j) == 3) {
        if (l == -1) l = j;
        r = j;
    }
    if (r - l + 1 != W) return false;
    rep(j,l,r+1) if (getBit(s,j) != 3)
        return false;
    return true;
}

int dfs(int s)
{
    if (dp.count(s)) return dp[s];
    if (!possible(s)) return dp[s] = -inf;
    if (Ok(s))
        return dp[s] = 0;

    int t = inf;
    rep(j,0,C) if (getBit(s,j) == 0) {
        int temp = std::max(dfs(s | (3 << (2 * j)))+1, dfs(s | (1 << (2 * j)))+1);
        t = std::min(t,temp);
    }
    return dp[s] = t;
}

int main()
{
    //Getinput(); return 0;
    #ifdef ACM
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif // ACM
    int T; scanf("%d",&T);
    rep(cas,1,T+1) {
        scanf("%d%d%d",&R,&C,&W);
        dp = dpdp[C];
        dfs(0);
        dpdp[C] = dp;
        printf("Case #%d: %d\n",cas,dp[0] + (R-1) * (C / W));
    }
}
