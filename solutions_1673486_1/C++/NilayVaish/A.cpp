#include<cstdio>

double P[100005];
double Q[100005];

int main()
{
    int T;
    scanf("%d\n",&T);

    for(int ii = 1; ii<= T; ++ii)
    {
        int A, B;
        scanf("%d %d\n", &A,&B);
        double pp = 1, qq = 0;
        double op = B + 2;

        for (int i = 0; i < A; ++i)
        {
            scanf("%lf ", P+i);
            Q[i] = pp * P[i];
            pp *= P[i];

            double op2 = 2 * (A - i - 1) + B - A + 1 + (B+1) * (1-pp);
            if (op > op2) op = op2;
        }

        double op3 = B - A + 1 + (B+1) * (1 - pp);
        if (op > op3) op = op3;

        printf("Case #%d: %.8lf\n", ii, op);
    }

    return 0;
}
