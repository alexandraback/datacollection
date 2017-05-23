#include <stdio.h>
#include <string.h>

long long gcd(long long a, long long b)
{
    long long r;
    while(b>0)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;

}

main()
{
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T, i, cas=0, key;
    long long a, b, c, d;
    scanf("%d", &T);

    while(T--)
    {
        scanf("%lld/%lld", &a, &b);
        c=gcd(a, b);
        a=a/c;
        b=b/c;
        key=1;
        c=1;
        while(1)
        {
            c=c*2;
            if(c==b)
            {
                break;
            }
            if(c>b)
            {
                printf("Case #%d: impossible\n", ++cas);
                key=0;
                break;
            }
        }

        if(key==1)
            for(i=1; ; i++)
            {
                b=b/2;
                if(b<=a)
                {
                    printf("Case #%d: %d\n", ++cas, i);
                    break;
                }
            }
    }


    return 0;
}
