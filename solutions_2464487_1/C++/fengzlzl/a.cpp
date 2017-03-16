#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

const double PIE = M_PI;

int main()
{
    //freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-large.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int T, cas;
    long long l, r, R, t, n;
    double v;
    scanf("%d", &T);
    for (cas=1; cas<=T; cas++)
    {
        scanf("%I64d%I64d", &R, &t);
        n = 2;
        l = 1; r = sqrt(t*PIE/2);
       // printf("l=%I64d r=%I64d\n", l, r);
        while (l<=r)
        {
            n = (l+r)/2;
          //  printf("%I64d %I64d\n", 2*R+2*n-1, t/n);
            if (2*R+2*n-1<=t/n) l = n + 1;
            else r = n - 1;
        }
        printf("Case #%d: %I64d\n", cas, r);
    }
    return 0;
}
/*
10000000000000000
1000000000000000000
*/
