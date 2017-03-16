#include<stdio.h>
int n, m, w, t, poz, rez, ii;

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
        printf("Case #%ld: %ld\n",ii,rez);
    }
    return 0;
}
