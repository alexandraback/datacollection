#include<stdio.h>


int main()
{
    int t,i,j;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        int limit1,limit2;
        float a[99999];
        float minimum;
        scanf("%d %d",&limit1,&limit2);
        minimum=limit2+2;
        int nbsp;
        float prob=1.0;
        float strk;
        j=0;
        while(j!=limit1)
        {
            scanf("%f",&a[j]);
            nbsp=limit1-j-1;
            prob*=a[j];
            strk=((nbsp+nbsp+limit2-limit1+1)*prob)+((1-prob)*(nbsp+nbsp+limit2-limit1+1+limit2+1));
            if(strk<minimum)
                minimum=strk;
        j++;
        }
        strk=1+limit2+1;
        if(minimum>strk)
            minimum=strk;
        printf("Case #%d: %f\n",i+1,minimum);
    }
return 0;
}
