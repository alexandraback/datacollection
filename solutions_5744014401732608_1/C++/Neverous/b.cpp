/* 2016
 * Maciej Szeptuch
 * II UWr
 */

#include <cstdio>

int buildings;
int tests;
long long int ways;

int main(void)
{
    scanf("%d", &tests);
    for(int t = 0; t < tests; ++ t)
    {
        scanf("%d %lld", &buildings, &ways);
        bool possible = ways <= (1LL << (buildings - 2));
        printf("Case #%d: %sPOSSIBLE\n", t + 1, possible ? "" : "IM");
        if(!possible) continue;

        -- ways;
        bool bits[buildings] = {};
        bits[buildings - 1] = 1;
        for(int b = 1; ways > 0; ++ b)
        {
            bits[buildings - b - 1] = ways % 2;
            ways /= 2;
        }

        for(int b = 0; b < buildings; ++ b)
            putchar('0' + bits[b]);

        puts("");
        for(int b = 1; b < buildings; ++ b)
        {
            for(int z = 0; z < 1 + b; ++ z)
                putchar('0');

            for(int o = 0; o < buildings - 1 - b; ++ o)
                putchar('1');

            puts("");
        }
    }

    return 0;
}
