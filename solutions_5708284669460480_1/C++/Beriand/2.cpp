#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int ile[250];
char kla[105], co[105];

int main ()
{
    int a,b,c,d,e,f,g,k,l,s,z,eksp;
    double x,y;

    scanf ("%d", &z);

    for (a=1; a<=z; a++)
    {
        for (b=0; b<250; b++)
            ile[b]=0;

        scanf ("%d%d%d\n%s\n%s", &k, &l, &s, kla, co);

        for (b=0; b<k; b++)
            ile[kla[b]]++;

        for (b=0; b<l; b++)
            if (!ile[co[b]])
                break;

        if (b<l)
        {
            printf ("Case #%d: 0.0\n", a);
            continue;
        }

        for (b=l-1; b; b--)
        {
            for (c=0; c<b && co[c]==co[l-b+c]; c++);

            if (c==b)
                break;
        }

        eksp=1+(s-l)/(l-b);

        x=s-l+1;

        for (b=0; b<l; b++)
            x*=(double)ile[co[b]]/(double)k;

        printf ("Case #%d: %lf\n", a, (double)eksp-x);
    }

    return 0;
}
