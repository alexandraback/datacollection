#include<stdio.h>
#include<algorithm>
using namespace std;
#define nmax 1005
int i, ii, poz, t, n, inc1, inc2, sf1, sf2, rez1, rez2, j, l, a1, a2, b1, b2;
double a[nmax], b[nmax];

void rezolv1()
{
    inc1=inc2=1;    sf1=sf2=n;
    rez1=0;
    for (i=1;i<=n;i++)
    {
        if (a[sf1]>b[sf2])
        {
            rez1++;
            sf1--;  inc2++;
        }
        else
        {
            sf1--;  sf2--;
        }
    }
}

void rezolv2()
{
    poz=1;
    rez2=0;
    for (i=1;i<=n;i++)
    {
        while ((a[poz]<b[i])&&(poz<=n))
            poz++;
        rez2+=(poz<=n);
        poz++;
    }

   /* for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            nr[i][i][j][j]=(a[i]>b[j]);
    for (l=1;l<=n;l++)
        for (a1=1;a1+l-1<=n;a1++)
            for (a2=1;a2+l-1<=n;a2++)
            {
                b1=a1+l-1;  b2=a2+l-1;
                nr[a1][b1][a2][b2]=nr[a1+1][b1][a2][b2-1];
                if (nr[a1][b1][a2][b2]<nr[a1][a1][a1][a1]);

            }*/
}

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%ld",&t);
    for (ii=1;ii<=t;ii++)
    {
        scanf("%ld",&n);
        for (i=1;i<=n;i++)
            scanf("%lf",&a[i]);
        for (i=1;i<=n;i++)
            scanf("%lf",&b[i]);
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        rezolv1();
        rezolv2();
        printf("Case #%ld: %ld %ld\n",ii, rez2,rez1);

    }
    return 0;
}
