#include<stdio.h>
long long n, lg1, lg2, i, m, w, t, poz, rez, ii, nr[100];


void calc()
{
    for (i=0;i<w;i++)
        nr[i]=0;
    for (i=w;i<2*w;i++)
        nr[i]=1;
    for (i=2*w;i<=m;i++)
    {
        nr[i]=-1;
        for (poz=1;poz<=i;poz++)
        {
            lg1=poz-1;
            lg2=i-poz;
            if ((nr[i]>nr[lg1]+nr[lg2]+1)||(nr[i]==-1))
                nr[i]=nr[lg1]+nr[lg2]+1;
        }
    }
    rez+=(n-1)*nr[m];
}

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%ld",&t);
    while (t--)
    {
        scanf("%ld %ld %ld",&n,&m,&w);
        poz=w;rez=1;
        while (m-poz>2*w)
        {
            poz+=w;
            rez++;
        }
        //da
        if (m-poz>w)
            rez++;
        rez+=w;
        if (m==w)
            rez--;
        ii++;
        calc();
        printf("Case #%lld: %lld\n",ii,rez);
    }
    return 0;
}
