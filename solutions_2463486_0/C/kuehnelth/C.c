#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>

uint64_t backwards(uint64_t a)
{
    uint64_t ret = 0;
    while (a > 0) {
        ret = ret * 10 + a % 10;
        a /= 10;
    }
    return ret;
}
uint64_t ispal(uint64_t a)
{
    return a == backwards(a);
}

uint64_t pal(uint64_t a, uint64_t b)
{
    uint64_t i, j, ret = 0;
    i = sqrt(a);
    if (i * i < a) i++;
    j = sqrt(b);
    if (j * j > b) j--;

    for (; i <= j; i++) {
        ret += (ispal(i) && ispal(i * i)) ? 1 : 0;
    }
    return ret;
}

uint64_t main(uint64_t argc, char **argv)
{
    uint64_t c, i, j, a, b;
    scanf("%" SCNu64, &c);
    for (i = 1; i <= c; i++) {
        scanf("%"SCNu64" %"SCNu64, &a, &b);
        printf("Case #%"PRIu64": %"PRIu64"\n", i, pal(a, b));
    }
    
}
