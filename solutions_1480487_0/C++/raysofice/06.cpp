#include<iostream>
#include<stdio.h>
#include<memory.h>
using namespace std;

int n;
double a[202],f[202],s,t,t2;

int main()
{
    freopen("A-small-attempt3.in","r",stdin);
    freopen("outa.out","w",stdout);
    int T,i,cas=0,m;
    scanf("%d",&T);
    while(T--)
    {
        cas++;
        scanf("%d",&n);
        s=0;
        for(i=0;i<n;i++)
        {
            scanf("%lf",a+i);
            s+=a[i];
        }

        memset(f,0,sizeof(f));
        m=n,t2=s,t=2.0/n;;
        for(i=0;i<n;i++)
        {
            if(t<a[i]/s)
            {
                f[i]=1;
                t2-=a[i];
                m--;
            }
        }
        printf("Case #%d:",cas);
        for(i=0;i<n;i++)
        {
            if(!f[i])
                printf(" %.5lf",100.0*(1.0/m+t2/(s*m)-a[i]/s));
            else
                printf(" 0");
        }
        printf("\n");
    }
}
