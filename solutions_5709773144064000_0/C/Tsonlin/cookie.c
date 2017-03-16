#include <stdio.h>

int main()
{
    double X, F, C, r;
    double time, f_time, x_time;
    int T, t;

    scanf("%d", &T);
    for (t = 1; t <= T; t++)
    {
        scanf("%lf%lf%lf", &C, &F, &X);

        r = 2.0;
        time = 0.0;
        f_time = C / r;
        x_time = X / r;
        
        while (f_time + X / (r + F) < x_time)
        {
            // add a factory
            time += f_time;
            r += F;

            f_time = C / r;
            x_time = X / r;
        }

        // wait to win
        time += x_time;

        printf("Case #%d: %.7lf\n", t, time);
    }

    return 0;
}
