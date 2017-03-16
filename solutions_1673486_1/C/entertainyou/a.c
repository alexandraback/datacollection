#include <stdio.h>
#include <stdlib.h>

double result(int a, int b, double *p)
{
    int i;
    double foo, ret;
    ret = 3 * b;
    for (i = 0; i <= a; ++i)
    {
        /* delte i chars */
        /* result += b - i + () */
        int step = a - i;
        double right = p[i] * (b - i + 1);
        double wrong = (1 - p[i]) * (b - i + 1 + b + 1);
        /* result[i] = step + right + wrong; */
        foo = step + right + wrong;
        if (foo < ret)
            ret = foo;
    }

    /* give up */
    foo = 1 + b + 1;
    if (foo < ret)
        ret = foo;
    return ret;
}

double solve(int a, int b, double *array)
{
    double *p, ret;
    p = malloc(sizeof(double) * (a + 1));

    {
        int i;
        /* double first = 1; */
        p[0] = 1;
        for (i = 0; i < a; ++i)
        {
            p[i + 1] = array[i] * p[i];
        }
    }

    ret = result(a, b, p);
    free(p);
    return ret;
}

int main(int argc, char *argv[])
{
    int i, n;
    scanf("%d", &n);

    for (i = 0; i < n; ++i)
    {
        int a, b, j;
        double *array;
        scanf("%d %d", &a, &b);
        array = malloc(sizeof(double) * b);

        for (j = 0; j < a; ++j)
        {
            scanf("%lf", &array[j]);
        }
        printf("Case #%d: %.6lf\n", i + 1, solve(a, b, array));
        free(array);
    }
    return 0;
}
