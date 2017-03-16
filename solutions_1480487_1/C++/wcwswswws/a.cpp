#include<stdio.h>

double a[200];
bool b[200];
int n;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("2.txt","w",stdout);
    int tt;
    scanf("%d",&tt);int t=0;
    while (tt>0)
    {
        tt--;t++;
        scanf("%d",&n);
        double x=0;
        for (int i=0;i<n;i++) {b[i]=true;scanf("%lf",&a[i]);x+=a[i];}double nn=0,y=0;
        for (int i=0;i<n;i++)
        {
            double sum=0;
            for (int j=0;j<n;j++) if (a[j]<a[i]) sum+=a[i]-a[j];
            if (sum<=x) {nn+=1.0;b[i]=false;y+=a[i];}
        }
        double xx=(x+y)/nn;
        printf("Case #%d:",t);
        for (int i=0;i<n;i++)
        {
            double l=(xx-a[i])/x;
            if (b[i]) l=0;
            printf(" %.5f",l*100.0);
        }
        printf("\n");
    }
    return 0;
}
