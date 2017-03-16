#include<stdio.h>
int main()
{
    int T,t,N,a[1000],b[1000],c[1000],i,ans,n,star,min;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            scanf("%d%d",a+i,b+i);
            c[i]=0;
        }
        for(n=N,ans=star=0;n;)
        {
            for(i=0;i<N;i++)
                if(c[i]<2&&star>=b[i])
                {
                    star+=2-c[i];
                    c[i]=2;
                    ans++;
                    n--;
                    break;
                }
            if(i<N)
                continue;
            for(i=0,min=-1;i<N;i++)
                if(c[i]==0&&star>=a[i]&&(min<0||b[i]>b[min]))
                    min=i;
            if(min<0)
                break;
            else
            {
                star+=c[i]=1;
                ans++;
            }
        }
        printf("Case #%d: ",t);
        if(n>0)
            puts("Too Bad");
        else
            printf("%d\n",ans);
    }
}
