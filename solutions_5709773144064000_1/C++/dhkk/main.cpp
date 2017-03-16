#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

double c, f, x, d, t;

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("ou.txt", "w", stdout);
    int _, cas = 0;
    scanf("%d", &_);
    while (_--)
    {
        scanf("%lf%lf%lf", &c, &f, &x);
        d = 2;
        t = 0;
        for (;;)
        {
            if (x/d < c/d+x/(d+f))
            {
                t += x/d;
                break;
            }
            t += c/d;
            d += f;
        }
        printf("Case #%d: %.7f\n", ++cas, t);
    }
    return 0;
}
