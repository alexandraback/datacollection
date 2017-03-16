#include <stdlib.h>
#include <stdio.h>

int t;
double X,C,F,rate,sec,total;

void main()
{
    FILE *f, *g;

    f = fopen("Bin.txt","r");
    g = fopen("Bout.txt","w");

    fscanf(f,"%d",&t);
    for (int test=0; test<t;test++)
    {
        fscanf(f,"%lf%lf%lf",&C,&F,&X);
        total = 0;
        rate = 2;
        sec = 0;
        while (total<X)
        {
            sec+=C/rate;
            total = C;

            if ((X-total)/rate < X/(rate+F))
            {
                sec+=(X-total)/rate;
                break;
            }
            else
            {
                total = 0;
                rate+=F;
            }
        }
        fprintf(g,"Case #%d: %.7f\n",test+1,sec);
    }

    fclose(f);
    fclose(g);
}
