#include<stdio.h>
typedef long long ll;
typedef unsigned long long ull;
int main()
{
    freopen("C:\\TC\\BIN\\codejam2013\\in.txt","r",stdin);
    freopen("C:\\TC\\BIN\\codejam2013\\out.txt","w",stdout);

    int t,cs;
    ll r,t1,t2,t3,t4;
    scanf("%d",&t);
    for(cs=1;cs<=t;cs++)
    {
        scanf("%lld %lld",&r,&t1);
        t2=1;
        t3=10000000;
        while(1)
        {
            for(t4=t2;;t4+=t3)
            {
                if((2*(t4+r)-1)>(t1/t4))break;
            }
            t2=t4-t3;
            t3/=2;
            if(t3<10)break;
        }
        for(;;t2++)
        {
            if((2*(t2+r)-1)>(t1/t2))break;
        }
        printf("Case #%d: %lld\n",cs,t2-1);
    }
    return 0;
}
