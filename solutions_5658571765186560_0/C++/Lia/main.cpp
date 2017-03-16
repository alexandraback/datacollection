#include<stdio.h>
#include<algorithm>
using namespace std;
int n, m, x, t, ii, aux;

bool rezolvare()
{
    if ((n*m)%x>0)
        return 0;
    if (x>max(n,m))
        return 0;
    if (x>2*min(n,m))
        return 0;
    if (n>m)
    {   aux=n;  n=m;    m=aux;    }
    if ((n==2)&&(m==4)&&(x==4))
        return 0;
    return 1;
}

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%ld",&t);
    while (t--)
    {
        ii++;
        scanf("%ld %ld %ld",&x,&n,&m);
        if (rezolvare())
            printf("Case #%ld: GABRIEL\n",ii);
        else
            printf("Case #%ld: RICHARD\n",ii);
    }
    return 0;
}
