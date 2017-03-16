#include <cstdio>
#include <algorithm>

using namespace std;

int main ()
{
    int a,b,k,z,w,x,y;

    scanf ("%d", &z);

    for (int i=1; i<=z; i++)
    {
        scanf ("%d %d %d", &a, &b, &k);

        w=0;

        for (x=0; x<a; x++)
        {
            for (y=0; y<b; y++)
            {
                if ( (x&y) < k)
                {
                    w++;
                }
            }
        }

        printf ("Case #%d: %d\n", i, w);
    }

    return 0;
}
