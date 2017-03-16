#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<string>
#define ll long long
#define db double
#define PB push_back
#define lson k<<1
#define rson k<<1|1
using namespace std;

const int N = 205;

vector<ll> a;

int main()
{
#ifdef Haha
    freopen("C-large.in", "r", stdin);
    freopen("A-small-attempt0.out","w",stdout);
#endif // Haha
    int T, cas(1);
    scanf("%d", &T);
    while(T--)
    {
        ll c, d, v;
        scanf("%I64d%I64d%I64d", &c, &d, &v);
        a.clear();
        for(ll i = 1; i <= d; i++)
        {
            ll t;
            scanf("%I64d", &t);
            a.PB(t);
        }
        if(a[0] != 1) a.insert(a.begin(), 1);
        ll s(0LL);
        for(int i = 0; i < a.size(); i++)
        {
            if(i + 1 < a.size())
            {
                if(a[i]*c + s < a[i + 1] - 1)
                {
                    a.insert(a.begin() + i + 1, a[i]*c + s + 1);
                }
            }
            else
            {
                if(a[i]*c + s < v)
                {
                    a.PB(a[i]*c + s + 1);
                }
                else
                {
                    break;
                }
            }
            s += a[i] * c;
        }
        printf("Case #%d: %d\n", cas++, a.size() - d);
    }
    return 0;
}
