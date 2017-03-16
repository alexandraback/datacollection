#include <cstdio>
#include <algorithm>
using namespace std;
main()
{
    int t, d, mx, mn, sum, p[2000];
    scanf("%d", &t);
    for (int cs = 1 ; cs <= t ; ++cs) {
        scanf("%d", &d);
        for (int i = 0 ; i < d ; ++i) {
            scanf("%d", &p[i]);
            mx = max(mx, p[i]);
        }
        mn = mx;
        for (int i = 1 ; i <= mx ; ++i) {
            sum = i;
            for (int j = 0 ; j < d ; ++j) {
                if (p[j] > i) {
                    if (p[j] % i == 0) sum += (p[j] / i - 1);
                    else sum += (p[j] / i);
                }
            }
            mn = min(mn, sum);
        }
        printf("Case #%d: %d\n", cs, mn);
    }
}