#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int gdz[1000005];
char t[1000005];

int main ()
{
    int z,n,a,b,c,d,e,ile,dob;
    long long w;

    scanf ("%d", &z);

    for (e=1; e<=z; e++)
    {
        scanf ("%s %d", t, &n);

        ile=dob=w=0;

        for (a=0; t[a]; a++)
        {
            if (t[a]!='a' && t[a]!='e' && t[a]!='o' && t[a]!='i' && t[a]!='u')
            {
                ile++;

                if (ile>=n)
                    gdz[dob++]=a;

            }
            else
                ile=0;
        }

        gdz[dob++]=a;
        c=a;

        for (a=0; t[a]; a++)
        {
            b=*lower_bound(gdz,gdz+dob,min(a+n-1,c));
            w+=(long long)c-(long long)b;
        }

        printf ("Case #%d: %lld\n", e, w);
    }


    return 0;
}
