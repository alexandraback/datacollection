#include <cstdio>
#include <cmath>

double mp[251]; //my position
double mv[251]; //my speed
double mt[251]; //my time
double a[251]; //accelerations
double t[2001]; //ti
double x[2001]; //xi
double D;
int N, A;

void init()
{
    for(int i = 0; i < A; i++)
    {
        mp[i] = 0;
        mv[i] = 0;
        mt[i] = 0;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    scanf("%d", &T);

    for(int tt = 1; tt <= T; tt++)
    {
        printf("Case #%d:\n", tt);
        scanf("%lf %d %d", &D, &N, &A);
        init();
        for(int i = 0; i < N; i++)
        {
            scanf("%lf %lf", &t[i], &x[i]);
        }
        for(int i = 0; i < A; i++)
        {
            scanf("%lf", &a[i]);
        }

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < A; j++)
            {
                if (mp[j] >= D)
                {
                    continue;
                }
                double md = mp[j] + 0.5 * a[j] * (t[i] - mt[j]) * (t[i] - mt[j]);
                if(tt == 3)
                {
                    //printf("%lf - %lf: %lf\n", x[i], t[i], md);
                }
                if (md >= x[i])
                {
                    if (x[i] >= D)
                    {
                        double ht = 0;
                        double hs = (x[i] - x[i-1]) / (t[i] - t[i-1]);
                        double nec = mt[j] + sqrt((D - mp[j]) / (0.5 * a[j]));
                        double distdiff = D - x[i - 1];
                        double hn = t[i - 1] + distdiff / hs;
                        if (hn > nec)
                        {
                            nec = hn;
                        }
                        mt[j] = nec;
                        mp[j] = D;
                        mv[j] = 0;
                    }
                    else
                    {
                        mv[j] = 0;
                        mp[j] = x[i];
                        mt[j] = t[i];
                    }
                    if(tt == 3)
                    {
                        //printf("MYP: %lf\n", mp[j]);
                    }
                }
            }
        }

        for(int i = 0; i < A; i++)
        {
            if (mp[i] < D)
            {
                mt[i] = mt[i] + sqrt((D - mp[i] * 1.0) / (0.5 * a[i]));
                if(tt == 3)
                {
                    //printf("MYP: %lf\n", mp[i]);
                }
            }
            printf("%.8lf\n", mt[i]);
        }
    }

    return 0;
}
