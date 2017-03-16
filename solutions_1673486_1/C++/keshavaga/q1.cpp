#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int A,B;
        float a[99999];
        float min;
        scanf("%d %d",&A,&B);
        min=B+2;
        int nbsp;
        float prob=1.0;
        float strokes;
        for(int j=0;j<A;j++)
        {
            scanf("%f",&a[j]);
            nbsp=A-j-1;
            prob*=a[j];
            strokes=((nbsp+nbsp+B-A+1)*prob)+((1-prob)*(nbsp+nbsp+B-A+1+B+1));
            if(strokes<min)
                min=strokes;
        }
        strokes=1+B+1;
        if(min>strokes)
            min=strokes;
        printf("Case #%d: %f\n",i+1,min);


    }
    return 0;
}
