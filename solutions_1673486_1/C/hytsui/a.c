#include <stdio.h>

double foo()
{
    int a, b;
    double c1=1, c2, p, c3=999999, tc3, tmp;
    int i, j;
    double pa[100000];
    scanf("%d %d", &a, &b);
    for (i=0; i<a; i++)
    {
        scanf("%lf", &p);
        c1 *= p;
        pa[i] = p;
    }
    c1 = c1 * (b-a+1) + (1-c1) * (b+2+b-a);
    c2 = b+2;
    for (i=1; i<=a; i++)
    {
        tmp = 1;
        for (j=0; j<a-i; j++)
            tmp *= pa[j];
        tc3 = tmp * (2*i+b-a+1) + (1-tmp) * (2*i+b-a+1+b+1);
        if (tc3 < c3)
            c3 = tc3;
    }
    if (c1 < c2 && c1 < c3)
        return c1;
    if (c2 < c1 && c2 < c3)
        return c2;
    if (c3 < c2 && c3 < c1)
        return c3;
}

int main()
{
    int i, t;
    scanf("%d", &t);
    for (i=0; i<t; i++)
    {
        printf("Case #%d: %.6f\n", i+1, foo());
    }
    return 0;
}
