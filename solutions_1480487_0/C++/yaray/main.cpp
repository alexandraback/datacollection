#include <stdio.h>
#include <algorithm>
using namespace std;

const int N = 1900;
int s[N], a[N];

int main()
{
    int cases;
    scanf("%d", &cases);
    for (int T = 1; T <= cases; ++T) {
        int sum = 0, n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &s[i]), sum += s[i];
        printf("Case #%d:", T);
        for (int i = 0; i < n; ++i) {
            double lo = 0, hi = sum;
            while (hi-lo > 1e-8) {
                double m = (hi+lo) / 2, t = m;
                bool f = false;
                for (int j = 0; j < n; ++j)
                    if (j != i && m + s[i] - s[j] > 0)
                        t += m + s[i] - s[j], f = true;
                if (t >= sum) hi = m;
                else lo = m;
            }
            printf(" %lf", 100*double(hi)/sum);
        }
        puts("");
    }
}
