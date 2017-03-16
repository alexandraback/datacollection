#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main()
{
    int i, j, k;
    int T, N, s[200], X, newX, newN;
    double average, newAverage;
    scanf("%d", &T);
    for(i = 1; i<=T; i++)
    {
        scanf("%d", &N);
        X = 0;
        for(j = 0; j<N; j++)
        {
            scanf("%d", s+j);
            X += s[j];
        }
        average = 2.0 * X / N;
        newX = X; newN = N;
        for(j = 0; j<N; j++)
        {
            if(s[j] > average)
            {
                newX -= s[j];
                newN--;
            }
        }

        if(newN > 0)
            newAverage = 1.0 * (X + newX) / newN;

        printf("Case #%d: ", i);

        for(j = 0; j<N; j++)
        {
            if(average <= s[j])
                printf("0 ");
            else
            {
                if(newN > 0)
                {
                    printf("%f ", (newAverage - s[j]) / X * 100);
                }
                else
                {
                    printf("%f ", (average - s[j]) / X * 100);
                }
            }
        }
        printf("\n");
    }
}
