#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int main ()
{
    int z,x,y,a,b,c,d;

    scanf ("%d", &z);

    for (a=1; a<=z; a++)
    {
        scanf ("%d %d", &x, &y);

        printf ("Case #%d: ", a);

        if (x>0)
            while (x--)
                printf ("WE");
        else
                while (x++)
                    printf ("EW");

        if (y>0)
            while (y--)
                printf ("SN");
        else
            while (y++)
                printf ("NS");

        printf ("\n");
    }

    getchar();
    getchar();
    return 0;
}
