#include <cstdio>
#include <algorithm>
#include <set>
#include <string>
#include <iostream>
using namespace std;

bool t[61][61];

int main ()
{
    int a,b,c,d,e,f,g,zz,n;
    long long w,z;
    scanf ("%d", &zz);

    for (g=1; g<=zz; g++)
    {
        scanf ("%d%lld", &n, &w);

        for (a=0; a<n; a++)
            for (b=0; b<n; b++)
                t[a][b]=0;

        z=1;

        for (a=2; a<n; a++)
            z*=2;

        if (w>z)
        {
            printf ("Case #%d: IMPOSSIBLE\n", g);
            continue;
        }

        z=1;

        for (a=1; z<w; a++)
            z*=2;

        for (b=0; b+1<n; b++)
            t[b][b+1]=1;

        for (b=0; b<a; b++)
            for (c=b+2; c<a; c++)
                t[b][c]=1;

        z/=2;
        w-=z;
        z/=2;

        for (b=a-2; b>0; b--)
        {
            if (w>=z)
            {
                w-=z;
                t[b][a]=1;
            }

            z/=2;
        }

        if (b==0 && w>0)
            t[0][a]=1;

        printf ("Case #%d: POSSIBLE\n", g);

        for (a=0; a<n; a++)
        {
            for (b=0; b<n; b++)
                printf ("%d", t[a][b]);

            printf ("\n");
        }
    }

    return 0;
}
