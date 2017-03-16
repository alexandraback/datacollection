// ProbA.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

int main()
{
    int T, nT, A, B, i;

    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    scanf("%d", &T);
    for(nT = 1; nT <= T; nT++)
    {
        double result = 0.0;
        double cumProb = 1.0;

        scanf("%d%d", &A, &B);

        result = B + 2;

        for (i = 1; i <= A; i++)
        {
            double curProb, tempRes;
            int Y;
            scanf("%lf", &curProb);
            
            cumProb *= curProb;

            Y = 2 * (A - i) + B-A+1;
            tempRes = cumProb * Y + (1-cumProb) * (Y+B+1);

            if (tempRes < result)
            {
                result = tempRes;
            }
        }

        printf("Case #%d: %0.6lf\n", nT, result);
    }

	return 0;
}

