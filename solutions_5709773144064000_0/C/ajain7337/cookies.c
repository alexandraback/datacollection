#include<stdio.h>

int main()
{
    int t,i;
    double c,f,x,time,cook;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%lf%lf%lf",&c,&f,&x);
        time=0;
        cook=2.0;
        while(1)
        {
           // printf("%f %f\n",(x/cook),(c/cook)+(x/(cook+f)));
            if((x/cook) > (c/cook)+(x/(cook+f)))
            {
                time+=(c/cook);
                cook+=f;
            }
            else
            {
                time+=(x/cook);
                break;
            }
        }
        printf("Case #%d: %0.7f\n",i+1,time);
    }
    return 0;
}
