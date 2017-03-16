#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<algorithm>

using namespace std;

long long needed(long long t, long long resp)
{
    return (2 * t + 2 * resp - 1) * resp;
}

int main()
{
    int te, teste;
    long long t, n;
    scanf("%d\n", &teste);
    for (int te = 0; te < teste; te++)
    {
        scanf("%lld %lld\n", &t, &n);
        long long a = 0;
        long long b = 1000000000000000000LL / t;
        if (b > 1000000000)
            b = 1000000001;
        long long c;
        while (a + 1 < b)
        {
            c = (a + b)/2;
            long long need = needed(t, c);
            if (need <= n)
                a = c;
            else
                b = c;
        }
        printf("Case #%d: %lld\n", te+1, a);
    }
    return 0;
}
