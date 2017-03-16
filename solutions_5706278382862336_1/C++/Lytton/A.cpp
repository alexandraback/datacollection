#include <stdio.h>
#include <iostream>
using namespace std;

long long p, q;
int T;
char c;

void doit()
{
    cin >> p >> c >> q;
    long long k, tmp;

    k = 1; tmp = q;

    while (tmp % 2 == 0 )
    {
        k = k*2;
        tmp /= 2;
    }

    //printf("%d %d\n", p, k);
    if (p % tmp != 0)
    {
        printf("impossible\n");
    }
    else {

            p /= tmp;
            int g = 1;
            while (p*2 < k)
            {
                p = p*2;
                g++;
            }
            printf("%d\n", g);
         }
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d", &T);
    for (int q = 1;q <= T;++q)
    {
        printf("Case #%d: ", q);
        doit();
    }

    return 0;
}
