#include<stdio.h>

int A,B,T;
long long x;
int p[10],count,e,k,dijit[10],n,u;

main()
{
    freopen("/Users/thanardkurutach/Desktop/C++/CodeJam/C-small-attempt0.in","r",stdin);
    freopen("/Users/thanardkurutach/Desktop/C++/CodeJam/C-small-attempt0.out","w",stdout);

    scanf("%d",&T);
    for(int i=0;i<T;i++)
    {
        x=0;
        scanf("%d %d",&A,&B);
        for(int j=A;j<=B;j++)
        {
            n=0;
            k=j;

            while(k>=1)
            {
                dijit[n]=k%10;
                k=k/10;
                n++;
            }

            e=1;

            for(int l=0;l<n-1;l++)
            {
                e*=10;
            }

            count=0;
            p[0]=j;
            for(int l=1;l<n;l++)
            {
                p[l]=(p[l-1]/10)+(dijit[l-1]*e);
                for(int t=0;t<l;t++)
                {
                    if(p[l]==p[t]||p[l]<e||p[l]<A||p[l]>B)
                    {
                        u=1;
                    }
                }
                if(u!=1){count++;}
                u=0;
            }

//            printf("%d=%d\n",j,count);

            x+=count;

        }
        printf("Case #%d: ",i+1);
        printf("%lld\n",x/2);
    }
}
