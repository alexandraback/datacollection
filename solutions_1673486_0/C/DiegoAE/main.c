#include <stdio.h>


#define MAXN 100010

int A,B;



double  array[MAXN];
double  producto[MAXN];


char debug=0;


int main()
{
    int T,caso;
    scanf("%d",&T);
    int i;
    for(caso=1;caso<=T;caso++)
    {
        scanf("%d %d",&A,&B);
        double ant=1.0;
        for(i=0;i<A;i++)
        {
            scanf("%lf",&array[i]);
            producto[i]=ant*array[i];
            ant=array[i];
        }
        double best_expected=-1.0;
        if (debug)
        {
            for(i=0;i<A;i++)
                printf("%lf %lf\n",array[i],producto[i]);
        }
        for(i=0;i<=A;i++)
        {
            double all_good=producto[A-i-1];
            double not_good=1 - all_good;
            double mean= all_good*(B-A+i+i+1) + not_good*(B-A+i+i+1+B+1);
            if (best_expected < 0 || mean < best_expected)
                best_expected=mean;
        }
        if (B+2<best_expected)
            best_expected=B+2;
        printf("Case #%d: %.10lf\n",caso,best_expected);
    }
    return 0;
}
