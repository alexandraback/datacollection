#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main (void)
{
    int casos;
    scanf ("%d", &casos);

    for (int caso = 1; caso <= casos; ++caso)
    {
        printf ("Case #%d: ", caso);

        int a, b;
        vector<double> p;
        scanf ("%d %d", &a, &b);
        b -= a;

        for (int i = 0; i < a; ++i)
        {
            double x;
            scanf ("%lf", &x);
            p.push_back(x);
        }

        double ans;

        // Expected if I keep typing
        double pr = 1;
        for (int i = 0; i < a; ++i)
        {
            pr *= p[i];
        }
        ans = pr * (b + 1) + (1 - pr) * (a + 2*b + 2);

        // Expected if I type k backspaces
        pr = 1;
        for (int k = a; k > 0; --k)
        {
            ans = min(ans, pr * (2*k + b + 1) + (1 - pr) * (2*k + a + 2*b + 2));
            pr *= p[a-k];
        }

        // Expected if I give up
        ans = min(ans, 2.0 + a + b);

        printf ("%f\n", ans);
    }

    return 0;
}

