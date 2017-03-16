#include<stdio.h>
#define nmax 1005
int t, ii, i, n, m, max, rez, nr, v[nmax];

void rezolvare()
{
    rez=-1;
    for (m=1;m<=max;m++)
    {
        nr=0;
        for (i=1;i<=n;i++)
            if (v[i]>m)
            {
                nr+=v[i]/m-1;
                if (v[i]%m>0)
                    nr++;
            }
        if ((nr+m<rez)||(rez==-1))
            rez=nr+m;
    }
    printf("Case #%ld: %ld\n",ii,rez);

}
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%ld",&t);
    while (t--)
    {
        ii++;
        scanf("%ld",&n);
        max=0;
        for (i=1;i<=n;i++)
        {
            scanf("%ld",&v[i]);
            if (max<v[i])
                max=v[i];
        }
        rezolvare();
    }
    return 0;
}

