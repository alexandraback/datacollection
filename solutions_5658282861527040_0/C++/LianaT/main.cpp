#include<stdio.h>
int a, b, k, rez, ii, t, i, j;

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%ld",&t);
    for (ii=1;ii<=t;ii++)
    {
        rez=0;
        scanf("%ld %ld %ld",&a,&b,&k);
        for (i=0;i<a;i++)
            for (j=0;j<b;j++)
                rez+=((i&j)<k);
        printf("Case #%ld: ",ii);
        printf("%ld\n",rez);
    }
    return 0;
}
