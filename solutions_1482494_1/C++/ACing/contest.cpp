#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[1010], b[1010];
bool first[1010], second[1010];

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int T, cas = 0, n;
    scanf("%d", &T);
    while (T--)
    {
        memset(first, 0, sizeof(first));
        memset(second, 0, sizeof(second));
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d%d", &a[i], &b[i]);
        bool fail = 0;
        int ans = 0, score = 0;
        while (score < 2*n)
        {
            bool op = 0;
            for (int i = 0; i < n; ++i) if (!second[i] && score >= b[i])
            {
                ++ans;
                op = 1;
                second[i] = 1;
                if (first[i]) ++score;
                else score += 2;
                break;
            }
            if (!op)
            {
                int mv = -1, id = -1;
                for (int i = 0; i < n; ++i) if (!first[i] && !second[i] && score >= a[i])
                {
                    if (b[i] > mv) mv = b[i], id = i;
                }
                if (id == -1)
                {
                    fail = 1;
                    break;
                }
                ++ans;
                ++score;
                first[id] = 1;
            }
        }
        printf("Case #%d: ", ++cas);
        if (fail) puts("Too Bad");
        else printf("%d\n", ans);
    }
    return 0;
}
