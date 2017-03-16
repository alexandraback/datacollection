#include <cstdio>
#include <algorithm>
using namespace std;

int main(void)
{
    int T;
    scanf("%d", &T);

    for(int k = 1; k <= T; ++k)
    {
        double c, f, x;
        scanf("%lf%lf%lf", &c, &f, &x);

        int t = x/c;
        double r = x/2;
        double sp = 2;
        double a = 0;

        for(int i = 1; i <= t; ++i)
        {
            a += c/sp;
            sp += f;

            r = min(r, a+x/sp);
        }
        printf("Case #%d: %.7lf\n", k, r);
    }
}
