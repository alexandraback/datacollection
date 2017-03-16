#include <stdio.h>
#include <math.h>


main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("bullseyeout.txt","w",stdout);
    int t,test;
    scanf("%d",&test);
    for (t=1;t<=test;t++)
    {
        printf("Case #%d: ",t);
        long long r,n;
        long long count = 0;
        scanf("%lld %lld",&r,&n);
        r+=1;
        while(1)
        {
            if (n >= (r*r-(r-1)*(r-1)))
            {
                n -= (r*r-(r-1)*(r-1));
                r+=2;
                count++;
            }
            else break;
        }
        printf("%lld\n",count);
    }
}
