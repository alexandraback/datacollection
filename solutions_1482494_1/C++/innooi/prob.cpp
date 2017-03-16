#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;

int T, n;
int comp[MAXN];

struct node
{
    int a, b;

    bool operator<(const node & x) const
    {
        if (a != x.a) return a < x.a;
        return b > x.b;
    }
} p[MAXN];

int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d%d", &p[i].a, &p[i].b);
        sort(p + 1, p + n + 1);
        memset(comp, 0, sizeof (comp));
        int ans = 0, starts = 0;
        bool finish, cannot = 0, nowdone;
        while (1)
        {
            finish = 1;
            if (ans > 2 * n)
            {
                cannot = 1;
                break;
            }
            nowdone = 0;

            for (int i = 1; i <= n; ++i)
                if (comp[i] != 2) finish = 0;
            if (finish) break;

            for (int i = 1; i <= n; ++i)
            {
                if (p[i].b <= starts && comp[i] == 0)
                {
                    starts += 2;
                    comp[i] = 2;
                    nowdone = 1;
                    break;
                }
            }

            if (!nowdone)
            {
                for (int i = 1; i <= n; ++i)
                {
                    if (p[i].b <= starts && comp[i] == 1)
                    {
                        starts++;
                        comp[i] = 2;
                        nowdone = 1;
                        break;
                    }
                    else if (p[i].a <= starts && comp[i] == 0)
                    {
                        starts++;
                        comp[i] = 1;
                        nowdone = 1;
                        break;
                    }
                }
            }
            if (nowdone == 0)
            {
                cannot = 1;
                break;
            }
            ans++;
        }
        printf("Case #%d: ", cas);
        if (cannot)
        {
            puts("Too Bad");
        }
        else
        {
            printf("%d\n", ans);
        }
    }
    return 0;
}
