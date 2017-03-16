#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;
# define ll long long
ll gcd(ll a, ll b)
{
    if (a%b)  return gcd(b,a%b);
    return b;
}
ll kgcd(ll a, ll b)
{
    if (a == 0) return b;
    if (b == 0) return a;
    if (!(a & 1) && !(b & 1)) return kgcd(a>>1, b>>1) << 1;
    else if (!(b & 1)) return kgcd(a, b>>1);
    else if (!(a & 1)) return kgcd(a>>1, b);
    else return kgcd(abs(a - b), min(a, b));
}
int main()
{
    int t;
    ll p,q;
    char c;
//
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    scanf("%d",&t);
    for(int ii = 1; ii <= t ; ++ii )
    {
        printf("Case #%d: ",ii);
        scanf("%I64d%c%I64d",&p,&c,&q);
        //printf("asd");
        ll d = kgcd(p,q);
       // printf("asda\n");
        p /= d, q /= d;
        //printf("")
        ll s = q;
        while(s%2 == 0) s /= 2;
        if (s != 1)
        {
            printf("impossible\n");
            continue;
        }
        for(int i = 1; i < 50 ; ++i)
        {
            if (p < q/2)
            {
                q /= 2;
            }
            else
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
