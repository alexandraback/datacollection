#include<stdio.h>
int rez, poz, i, x, s, ok[150], v[150], ii, t, c, n;


void calc_pos()
{
    for (i=1;i<=n;i++)
        for (x=s;x>=v[i];x--)
                ok[x]|=ok[x-v[i]];

}

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%ld",&t);
    for (ii=1;ii<=t;ii++)
    {
        scanf("%ld %ld %ld",&c,&n,&s);
        for (i=1;i<=n;i++)
            scanf("%ld",&v[i]);
        for (i=1;i<=s;i++)
            ok[i]=0;
        ok[0]=1;
        calc_pos();
        rez=0;
        while (1)
        {
            poz=-1;
            for (i=1;i<=s;i++)
                if (ok[i]==0)
                {
                    poz=i;
                    break;
                }
            for (x=s;x>=poz;x--)
                ok[x]|=ok[x-poz];
            if (poz==-1)
                break;
            rez++;
        }
        printf("Case #%ld: %ld\n",ii,rez);

    }
    return 0;
}
