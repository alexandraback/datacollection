#include <stdio.h>

int main()
{
    long t, cas = 0, c, d, v;
    long denom[1000];
    long rst, max, i;

    scanf("%ld", &t);
    while (t--) {
        scanf("%ld %ld %ld", &c, &d, &v);
        for (i = 0; i < d; i++)
            scanf("%ld", &denom[i]);
        rst = max = 0;

        i = 0;
        while (max < v) {
            if (i < d && denom[i] <= max + 1) {
                max += denom[i] * c;
                i++;
            } else {
                max += (max + 1) * c;
                rst++;
            }
        }

        printf("Case #%ld: %ld\n", ++cas, rst);
    }

    return 0;
}