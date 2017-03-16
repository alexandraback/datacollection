#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 10000;
int a[N], b[N];
int res, n;

int main()
{
    int T;
    scanf("%d\n", &T);
    for (int tt = 1; tt <= T; ++tt) {
        bool bad = true;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d%d", &a[i], &b[i]);
        int c = 0, s = n, r = 0;
        for (; s; ++c) {
            for (int i = 0; i < n; ++i)
                if (0 <= b[i] && b[i] <= r) {
                    b[i] = ~b[i];
                    --s;
                    r += 0 <= a[i] ? 2 : 1;
                    goto L1;
                }
            {
                int k = -1, maxb = -1;
                for (int i = 0; i < n; ++i)
                    if (0 <= a[i] && a[i] <= r && 0 <= b[i])
                        if (b[i] > maxb)
                            maxb = b[i], k = i;
                if (k == -1) break;
                a[k] = ~a[k];
                ++r;
            }
L1:;
        }
        printf("Case #%d: ", tt);
        if (s) puts("Too Bad");
        else printf("%d\n", c);
    }
}
