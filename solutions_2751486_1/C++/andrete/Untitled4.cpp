#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define L 1050006
using namespace std;
typedef long long LL;

int T, n, s[L], ns, e[L], len, ee[L], ne;
LL ans;
char str[L];

inline int ok(char ch)
{
    if(ch == 0 || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return 0;
    return 1;
}

LL f(int a)
{
    int b = lower_bound(s, s+ns, a) - s;
    if(b >= ns)
    {
        int c = lower_bound(ee, ee+ne, a) - ee;
        if(c >= ne) return 0;
        if(ee[c] - a + 1 >= n) return len-(a+n-1)+1;
        return 0;
    }
    if(s[b]-a+1 >= n)
    {
        int c = lower_bound(ee, ee+ne, a) - ee;
        if(ee[c] >= s[b])
            return len-s[b]+1;
        if(ee[c]-a+1 >= n) return len-(a+n-1)+1;
        return len-s[b]+1;

    }
    if(e[s[b]-n+1] - a + 1 >= n) return len-(a+n-1)+1;
    return f(e[s[b]-n+1]+1);
}

inline void solve()
{
    ans = 0, ns = 0, ne = 0;
    int p = 1, q = 1;
    for(p = 1; str[p]; ++p)
    {
        if(ok(str[p]))
        {
            for(q = p+1; ok(str[q]); ++q)
                ;
            if(q-p >= n)
                s[ns++] = p+n-1, e[p] = q-1, ee[ne++] = e[p];
            p = q-1;
        }
    }
    for(int i = 1; str[i]; ++i)
        ans += f(i);
}

int main(int argc, char **argv)
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas)
    {
        printf("Case #%d: ", cas);
        scanf("%s%d", str+1, &n);
        len = strlen(str+1);
        solve();
        printf("%I64d\n", ans);
    }

    return 0;
}

