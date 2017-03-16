#include <stdio.h>
typedef long long LL;

LL gcd(LL a,LL b)
{
    if(b == 0)  return a;
    return gcd(b,a%b);
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t,x;
    scanf("%d", &t);
    for(x = 1; x <= t; x++)
    {
        LL p,q;
        int ans = 0;
        scanf("%lld/%lld", &p, &q);
        LL g = gcd(p,q);
        p /= g;
        q /= g;
        int flag = 0;
        LL temp = q;
        while(temp > 1)
        {
            if(temp%2 != 0)
            {
                flag = 1;
                break;
            }
            else
                temp /= 2;
        }

        if(flag)
            printf("Case #%d: impossible\n",x);
        else
        {
            while(p < q)
            {
                q /= 2;
                ans++;
            }
            if(ans <= 40)
                printf("Case #%d: %d\n",x,ans);
            else
                printf("Case #%d: impossible\n",x);
        }
    }
    return 0;
}
