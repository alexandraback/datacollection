#include <stdio.h>

bool isPower(long long n)
{
    while (n > 1)
    {
        if (n % 2 != 0)
            return false;
        n /= 2;
    }
    return true;
}

int main()
{
    int T, gen;
    long long P, Q;
    bool impossible;
    scanf("%d", &T);
    for (int t = 0; t < T; ++t)
    {
        scanf("%lld/%lld", &P, &Q);
        impossible = true;
        gen = 1;
        //simplify
        while (P % 2 == 0 && Q % 2 == 0)
        {
            P /= 2;
            Q /= 2;
        }
        long long aux = Q;
        while (aux % 2 == 0)
        {
            aux /= 2;
        }
        if (P % aux == 0)
        {
            P /= aux;
            Q /= aux;
        }
        if (isPower(Q))
        {
            impossible = false;
            while (P < Q/2)
            {
                gen++;
                Q /= 2;
            }
        }

        if (impossible)
        {
            printf("Case #%d: impossible\n", t+1);
        }
        else
        {
            printf("Case #%d: %d\n", t+1, gen);
        }
    }
}
