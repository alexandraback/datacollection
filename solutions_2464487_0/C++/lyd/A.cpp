#include<stdio.h>
#include<stdint.h>
#include<math.h>
//n(2n+2r-1)

#define ll long long

ll r,t;

ll minn(ll a, ll b)
{
    return a<b ? a:b;
}

ll cal(ll r,ll t)
{
    ll le = 0 , ri = minn( t*2/r, (ll)sqrt(t*2) );
    ll ans = 0;
    while(le<=ri)
    {
        ll n = (le+ri)/2;
        ll area = n * ( 2*n + 2*r - 1);
        if( area <= t )
        {
            ans = n;
            le = n + 1;
        }
        else
            ri = n - 1;
    }
    return ans;
}

int main()
{
    int T,ca=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld",&r,&t);
        ll ans = cal(r,t);
        printf("Case #%d: %lld\n",ca++,ans);
    }

    return 0;
}

