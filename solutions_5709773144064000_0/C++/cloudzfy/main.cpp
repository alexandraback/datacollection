#include <stdio.h>
#include <string.h>

int main()
{
    freopen("B-small-attempt0.in.txt","r",stdin);
	freopen("B-small-attempt0.out.txt","w",stdout);
    int t, T;
    double C, F, X, tt, s, m;
    scanf("%d", &T);
    for(t = 1; t<= T; t++)
    {
        scanf("%lf%lf%lf", &C, &F, &X);
        tt = 0;
        m = 0;
        s = 2;
        while (1) {
            if(m + C >= X)
            {
                tt += (X - m) / s;
                break;
            }
            tt += C/s;
            m += C;
            if((X - m + C) / (s + F) < (X - m) / s)
            {
                m -= C;
                s += F;
            }
            else
            {
                tt += (X - m) / s;
                break;
            }
        }
        printf("Case #%d: %.7f\n", t, tt);
    }
    return 0;
}