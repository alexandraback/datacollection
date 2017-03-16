#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int r,c,w,najz;

int rob (int x)
{
    int y,v,z,zz,tmp;

    if (c==w)
        y=w-1;
    else
        y=w;

    tmp=c;
    c=x-1;
    z=1000000;

    if (c>=w)
    {
        for (v=1; v<=c; v++)
            z=min(z,rob(v));
    }

    c=tmp-x;
    zz=1000000;

    if (c>=w)
    {
        for (v=1; v<=c; v++)
            zz=min(zz,rob(v));
    }

    c=tmp;

    if (z>1000 && zz>1000)
        return y+1;

    if (z<=1000)
    {
        if (zz>1000)
            return max(y+1,z+1);

        return max(y+1,1+zz+z);
    }

    return max(y+1,zz+1);
}

int main ()
{
    int a,b,d,e,f,g,n,z;

    scanf ("%d", &z);

    for (a=1; a<=z; a++)
    {
        scanf ("%d%d%d", &r, &c, &w);

        if (w==1)
        {
            printf ("Case #%d: %d\n", a, r*c);
            continue;
        }

        najz=1000000000;

        for (b=1; b<=c; b++)
            najz=min(najz,rob(b));

        printf ("Case #%d: %d\n", a, najz+c/w*(r-1));
    }

    return 0;
}
