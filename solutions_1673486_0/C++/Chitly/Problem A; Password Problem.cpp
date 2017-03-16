#include<stdio.h>
double p[100005];
int main()
{
    int a,b,n,i,j;
    double sump=1,ch1,ch2,ch3;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    scanf("%d",&n);
    for(a=0;a<n;a++,sump=1)
    {
        scanf("%d%d",&i,&j);
        for(b=0;b<i;b++)
        {
            scanf("%lf",&p[b]);
            sump=sump*p[b];
        }
        ch1=sump*(j+1-i)+(1-sump)*(j+1-i+j+1);
        //printf("ch1=%lf\n",ch1);
        ch3=j+2;
        //printf("ch3=%lf\n",ch3);
        
        ch2=(sump+sump/p[i-1]*(1-p[i-1]))*(double)(j+3-i) + (1-(sump+sump/p[i-1]*(1-p[i-1])))*(double)(j+3-i+j+1);
        //printf("ch2=%lf\n",ch2);
        
        if(ch1<ch3 && ch1<ch3)
            printf("Case #%d: %lf\n",a+1,ch1);
        else if(ch2<ch1 && ch2<ch3)
            printf("Case #%d: %lf\n",a+1,ch2);
        else
            printf("Case #%d: %lf\n",a+1,ch3);
    }
    scanf(" ");
}
