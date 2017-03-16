#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctype.h>
#include <limits.h>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <stack>
#include <set>
#define CLR(a) memset(a, 0, sizeof(a))
#define REP(i, a, b) for(ll i = a;i < b;i++)
typedef long long ll;

using namespace std;
ll f[16];
ll n;
int len;
ll h[16];
ll g[1010000];
int ok[1010000];
ll get(int x,ll t)
{
    return t / f[x-1] % 10;
}
ll oo(int x)
{
    ll t = 0;
    while (x)
    {
        t = t* 10 + (x%10);
        x /= 10;
    }
    return t;
}
void solve()
{
    memset(ok,0,sizeof ok);
    queue <int> q;
    q.push(1);
    ok[1] = 1;
    g[1] = 1;
    while (!q.empty())
    {
        int h = q.front();
        q.pop();
        int x1 = h + 1;
        int x2 = oo(h);

        if (x1 <= 1000100 && ok[x1] != 1)
        {
            q.push(x1);
            ok[x1] = 1;
            g[x1] = g[h] + 1;
        }
        if (x2 <= 1000100 && ok[x2] != 1)
        {
            q.push(x2);
            ok[x2] = 1;
            g[x2] = g[h] + 1;
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out2.txt","w",stdout);
    solve();
    int T;
    scanf("%d",&T);
    for (int _ = 1;_ <= T;_++)
    {
        scanf("%lld",&n);
        printf("Case #%d: %lld\n",_,g[n]);
    }
}
