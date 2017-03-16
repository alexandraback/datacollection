#include <cstdio>
using namespace std;

typedef long long LL;

LL gcd(LL x, LL y)
{
    while(LL tmp = y%x)
    {
        y = x; x = tmp;
    }
    return x;
}

bool ismul(LL Q)
{
    while(Q%2==0)
        Q/=2;
    if(Q!=1)
        return false;
    return true;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        LL P,Q;
        scanf("%lld/%lld", &P, &Q);
        LL g = gcd(P,Q);
        P /= g; Q /= g;
        if(!ismul(Q))
            printf("Case #%d: impossible\n", t);
        else
        {
            int count=0;
            while(P<Q)
            {
                P*=2;
                count++;
            }
            printf("Case #%d: %d\n", t, count);
        }
    }
    return 0;
}
