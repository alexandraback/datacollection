#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

long long MAX = 1000000001;

long long r,t;

bool ok(long long c)
{
    if (t < (r * c * 2 + c * (c * 2 - 1)))
        return 0;
    return 1;
}

long long cal()
{
    int i,j;
    long long k,a,b,c;
    if (r * 2 + 1 > t)
        return 0;
    k = t / (r * 2) + 2;
    b = min(k, MAX);
    a = 1;
    //printf("%I64d %I64d %I64d\n", k, a, b);
    while (a < b - 1)
    {
        c = (a + b) / 2;
        if (ok(c))
            a = c;
        else
            b = c;
    }
    return a;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,k;
    int T;
    scanf("%d", &T);
    for (k = 1;k <= T;k++)
    {
        scanf("%I64d%I64d", &r,&t);
        printf("Case #%d: ", k);
        printf("%I64d\n", cal());
    }
    return 0;
}
