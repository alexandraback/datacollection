#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
#define rp(i,b) for(int i=(0);i<(b);++i)
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define repd(i,a,b) for(int i=(a);i<=(b);++i)
#define mst(a,b) memset(a,b,sizeof(a))
const int MAXN = 1000005;
const ll mod = 1000000007;
int n;
int p[200], np;
int revs(int c)
{
    np = 0;
    while (c)
    {
        p[np++] = c%10;
        c/=10;
    }
    int o = 0;
    while (p[o] == 0) ++o;
    int res = 0;
    for (;o<np; ++o)
    {
        res = res*10 + p[o];
    }
    return res;
}
int dp[MAXN];
struct node
{
    int a, c;
    bool operator< (const node &d) const
    {
        return c > d.c;
    }
};
priority_queue<node> qq;
void dfs(int cur, int stp)
{
    qq.push({1,1});
    while (!qq.empty())
    {
        node as = qq.top();
        qq.pop();
        if (dp[as.a]) continue;
        if (as.a >= 1000000)
            continue;
        dp[as.a] = as.c;
        int c = as.a+1;
        int d = revs(as.a);
        if (!dp[c]) qq.push({c, as.c+1});
        if (!dp[d]) qq.push({d, as.c+1});
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("A-small-attempt1.in", "r", stdin);
    //freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    int t;
    scanf("%d", &t);
    mst(dp, 0);
    dfs(1, 1);
    for (int _ = 1; _<= t; ++_)
    {
        printf("Case #%d: ", _);
        scanf("%d", &n);
        if (n == 1000000)
            cout<<dp[999999]+1<<endl;
        else
            printf("%d\n", dp[n]);
    }
    return 0;
}
