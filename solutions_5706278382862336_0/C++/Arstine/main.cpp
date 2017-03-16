#include <cstdio>

using namespace std;


int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.txt", "w", stdout);

    long t,k,p,q,i,g;
    char l;

    scanf("%ld",&t);

    for(k=1;k<=t;k++)
    {
        scanf("%ld%c%ld",&p,&l,&q);

        if(p==q)
            {printf("Case #%ld: 0\n",k);
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
            printf("Case #%ld: impossible\n",k);
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
                    printf("Case #%ld: %ld\n",k,g);
                else
                    printf("Case #%ld: impossible\n",k);
            }

    }
    return 0;
}
