#include <cstdio>

using namespace std;

long long gcd(long long a, long long b)
{
    long long GCD;
    while (b != 0)
                    {
                        GCD = b;
                        b = a % b;
                        a = GCD;
                    }
    return GCD;
}


int main()
{
    /*freopen("in.in", "r", stdin);
    freopen("out.txt", "w", stdout);*/

    long long t,k,p,q,i,g;
    char l;

    scanf("%lld",&t);

    for(k=1;k<=t;k++)
    {
        scanf("%lld%c%lld",&p,&l,&q);
        i=gcd(p,q);
        p=p/i;
        q=q/i;

        printf("%lld %lld %lld \n",i,p,q);
        if(p==q)
            {printf("Case #%lld: 0\n",k);
            continue;}

        i=0;
        g=-1;
        while(i<40)
        {
            i++;
            if(q%2==0)
                q/=2;
            else
                {
                    g=-1;
                    break;
                }

            if(p>=q)
                {
                    g=i;
                    break;
                }
        }



        if(g==-1)
            printf("Case #%lld: impossible\n",k);
        else
            {
                i=g;
                while(i<40)
                {
                    if(q==p)
                        break;
                    else if(p>q)
                    {
                        p=p-q;
                    }

                    if(q%2==0)
                        q/=2;
                    else
                        g=-1;

                    i++;
                }
                if(p==q)
                    printf("Case #%lld: %lld\n",k,g);
                else
                    printf("Case #%lld: impossible\n",k);
            }

    }
    return 0;
}
