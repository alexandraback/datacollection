#include <cstdio>
#include <algorithm>

using namespace std;

long long nwd (long long a, long long b)
{
    if (b==0)
        return a;

    return nwd(b,a%b);
}

int main ()
{
    long long a,b,c,d,e,z,n;

    scanf ("%lld", &z);

    for (n=1; n<=z; n++)
    {
        scanf ("%lld/%lld", &a, &b);

        if (a>b)
        {
            printf ("Case #%lld: impossible\n", n);
            continue;
        }

        c=nwd(a,b);
        a/=c;
        b/=c;

        for (c=b; c>1 && c%2==0; c/=2);

        if (c>1)
        {
            printf ("Case #%lld: impossible\n", n);
            continue;
        }

        d=b/2;

        for (c=1; d>a; c++)
            d/=2;

        if (c>40)
        {
            printf ("Case #%lld: impossible\n", n);
            continue;
        }

        printf ("Case #%lld: %lld\n", n, c);
    }


    return 0;
}
