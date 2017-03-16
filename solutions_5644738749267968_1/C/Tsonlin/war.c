#include <stdio.h>

double woods_naomi[1000];
double woods_ken[1000];

int double_cmp(const void * a, const void * b)
{
    const double * ia = (const double *) a;
    const double * ib = (const double *) b;
    if (*ia > *ib) return 1;
    if (*ia < *ib) return -1;
    return 0;
}

int main()
{
    int T, t;
    int N, i, j;
    int score, dscore;

    scanf("%d", &T);
    for (t = 1; t <= T; t++)
    {
        // input
        scanf("%d", &N);
        for (i = 0; i < N; i++) 
        {
            scanf("%lf", woods_naomi + i);
        }

        for (i = 0; i < N; i++)
        {
            scanf("%lf", woods_ken + i);
        }

        // calculate
        qsort(woods_naomi, N, sizeof(double), double_cmp);
        qsort(woods_ken, N, sizeof(double), double_cmp);

        i = 0;
        for (j = 0; j < N; j++)
        {
            if (woods_naomi[i] < woods_ken[j])
            {
                i++;
            }
        }
        score = N - i;

        j = 0;
        for (i = 0; i < N; i++)
        {
            if (woods_naomi[i] > woods_ken[j]) 
            {
                j++;
            }
        }
        dscore = j;

        // output
        printf("Case #%d: %d %d\n", t, dscore, score);
    }

    return 0;
}

