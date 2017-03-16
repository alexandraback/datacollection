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
ll get(int x,ll t)
{
    return t / f[x-1] % 10;
}
void init()
{
    len = 0;
    f[0] = 1;
    for (int i = 1;i <= 15;i++)
        f[i] = f[i-1] * 10;
    for (int i = 0;i <= 15;i++)
    if (n / f[i] != 0)
    {
        len = i + 1;
    }

    h[1] = 9 + 1;
    h[2] = 9 + 9 + 1;
    h[3] = 9 + 99 + 1;
    h[4] = 99 + 99 + 1;
    h[5] = 99 + 999 + 1;
    h[6] = 999 + 999 + 1;
    h[7] = 999 + 9999 + 1;
    h[8] = 9999 + 9999 + 1;
    h[9] = 9999 + 99999 + 1;
    h[10] = 99999 + 99999 + 1;
    h[11] = 99999 + 999999 + 1;
    h[12] = 999999 + 999999 + 1;
    h[13] = 999999 + 9999999 + 1;
    h[14] = 9999999 + 9999999 + 1;
    h[15] = 9999999 + 99999999 + 1;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int _ = 1;_ <= T;_++)
    {
        scanf("%lld",&n);
        ll ans = 0;
        init();
        for (int i = 1;i < len;i++)
            ans += h[i];
        ll tmp = 0;
        for (int i = len - len/2 + 1;i <= len;i++)
            tmp = tmp * 10 + get(i,n);
        ll t = n % f[len - len/2] - 1;
        if (tmp == 1) tmp --;
        tmp += t;
        if (t < 0)
        {
            n--;

            if (n / f[len-1] != 0)
            {
                tmp = 0;
                for (int i = len - len/2 + 1;i <= len;i++)
                    tmp = tmp * 10 + get(i,n);
                t = n % f[len - len/2] - 1;
                if (tmp == 1) tmp --;
                tmp += t;
                tmp++;
            }
        }
        ans += tmp;
        printf("Case #%d: %lld\n",_,ans + 1);
    }
}
