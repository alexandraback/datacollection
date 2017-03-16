#include <stdio.h>

int main()
{
    int cn, cc;

    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    scanf("%d", &cn);

    for (cc=1; cc<=cn; cc++)
    {
        long long a, b;
        int gene;

        scanf("%lld/%lld", &a, &b);

        gene = 0;
        while (b && b%2 == 0)
        {
            if (a < b)
                gene++;
            b /= 2;
        }

        if (gene == 0 || b == 0 || a%b != 0)
            printf("Case #%d: impossible\n", cc);
        else
            printf("Case #%d: %d\n", cc, gene);
    }

    return 0;
}
