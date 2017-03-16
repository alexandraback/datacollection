#include <iostream>
#include <cstdio>
using namespace std;

int n;



int main()
{
    scanf("%d", &n); FILE *out = fopen("ki.txt", "w");

    for (int ii = 1; ii<=n; ii++)
    {
        printf("%d\n", ii);
        double c,f,x; scanf("%lf %lf %lf", &c, &f, &x);
        double re = -1;

        double rate=2;

        int h = 0;
        bool megy = true;

        while (megy)
        {
            rate=2;
            double d = 0;
            for (int i = 1; i<=h; i++)
            {
                d+=c/rate;
                rate+=f;
            }
            d+=x/rate;

            megy = false;
            if (re == -1 || re > d)
            {
                re = d;
                megy = true;
            }

            h++;
        }

        fprintf(out, "Case #%d: %.10f\n", ii, re);
    }
    return 0;
}
