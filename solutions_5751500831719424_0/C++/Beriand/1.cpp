#include <cstdio>
#include <algorithm>

using namespace std;

char t[105][105];
int wsk[105], ile[105];

int main ()
{
    int z,n,a,b,c,d,e,sum,maks;

    scanf ("%d", &z);

    for (int i=1; i<=z; i++)
    {
        scanf ("%d", &n);
        sum=0;

        for (a=0; a<n; a++)
        {
            getchar();
            scanf ("%s", t[a]);
            wsk[a]=0;
        }

        for (a=0; t[0][a]; a++)
        {
            for (b=0; t[0][a+b]==t[0][a]; b++);

            ile[0]=b;

            for (c=1; c<n; c++)
            {
                if (t[c][wsk[c]]!=t[0][a])
                    break;

                for (d=0; t[c][wsk[c]+d]==t[0][a]; d++);
                ile[c]=d;
                wsk[c]+=d;
            }

            if (c<n)
                break;

            sort(ile,ile+n);

            for (d=0; d<n; d++)
                sum+=abs(ile[d]-ile[n/2]);

            a=a+b-1;
        }

        for (b=1; b<n && !t[b][wsk[b]]; b++);

        if (t[0][a] || b!=n)
            printf ("Case #%d: Fegla Won\n", i);
        else
            printf ("Case #%d: %d\n", i, sum);
    }

    return 0;
}
