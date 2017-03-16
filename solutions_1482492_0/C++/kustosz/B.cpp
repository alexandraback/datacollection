#include<cmath>
#include<cstdio>

int main()
{
    int z; scanf("%d", &z); int z1=z;
    while(z--)
    {
        long double D, t1, x1, t2, x2;
        int N, A;
        scanf("%Lf", &D);
        scanf("%d%d", &N, &A);
        if(N==2)
        {
            scanf("%Lf%Lf%Lf%Lf", &t1, &x1, &t2, &x2);
            long double v = (x2 - x1)/(t2-t1);
            long double a;
            printf("Case #%d:\n", z1-z);
            while(A--)
            {
                scanf("%Lf", &a);
                long double meet = v*(v+sqrt((2*a*x1)+(v*v)))/a;
                if(meet >= D || (N==1))
                    printf("%.7lf\n", sqrt((2*D)/a));
                else
                {
                    if(x1 <= D)
                    {
                        printf("%.7Lf\n", (D-x1)/v);
                    }
                    else
                    {
                        printf("%.7lf\n", sqrt((2*D)/a));
                    }
                }
            }
        }
        if(N==1)
        {
            scanf("%Lf%Lf", &t1, &x1);
            long double a;
            printf("Case #%d:\n", z1-z);
            while(A--)
            {
                scanf("%Lf", &a);
                printf("%.7lf\n", sqrt((2*D)/a));
            }
        }

    }
}


