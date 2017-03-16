#include<stdio.h>
#define nmax 1005
int i, t, ii, smax, s, m, st, dr, v[nmax];
bool ok;
char c;

void verificare()
{
    s=m;    ok=1;
    for (i=0;i<=smax;i++)
        if (s>=i)
            s+=v[i];
        else
        {
            ok=0;
            break;
        }
}

void rezolvare()
{
    st=0;   dr=smax;
    while (st<=dr)
    {
        m=(st+dr)/2;
        verificare();
        if (ok)
            dr=m-1;
        else
            st=m+1;
    }
    printf("Case #%ld: %ld\n",ii,st);
}

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%ld",&t);
    while (t--)
    {
        ii++;
        scanf("%ld ",&smax);
        for (i=0;i<=smax;i++)
        {
            scanf("%c",&c);
            v[i]=c-'0';
        }
        rezolvare();
    }
    return 0;
}
