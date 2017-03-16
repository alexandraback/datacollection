#include <stdio.h>
#include <string.h>

double c[40][40];


int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);

    for(int i=0;i<40;i++)
    {
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++)
            c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
    int cas,n,x,y;


    scanf("%d",&cas);
    for(int ii=1;ii<=cas;ii++)
    {
        scanf("%d%d%d",&n,&x,&y);
        printf("Case #%d: ",ii);
        if (x<0) x*=-1;
        if (y<0) y*=-1;
        int sum=0;
        int d=0;
        while(sum+(4*d+1)<=n)
        {
            sum+=4*d+1;
            d++;
        }
        d--;
        if (x+y<=2*d) puts("1.0");
        else
        if (x+y>2*(d+1)) puts("0.0");
        else
        {
            int res=n-sum;
            //printf("res=%d ",res);
            if (res<=y||y==2*d+2) puts("0.0");
            else
            {
                double ans=0;
                for(int i=0;i<=(res-(y+1));i++)
                    ans+=c[res][i];
                double p=1;
                for(int i=0;i<res;i++) p*=2;
                ans/=p;
                printf("%.10f\n",ans);
            }
        }
    }
    return 0;
}
