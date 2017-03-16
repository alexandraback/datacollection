#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 1000005;
int size[N];
int main()
{
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    int T;
    scanf("%d", &T);
    //printf("%d\n", T);
    for (int cas = 1; cas <= T; cas ++)
    {
        int a, n;
        scanf("%d%d", &a, &n);
        for (int i = 0; i < n; i ++)
            scanf("%d", size + i);

        sort(size, size + n);

        int ans = n, cnt = 0, tot = 0;
        long long now = a;
        if (a != 1)
            for (int i = 0; i < n; i ++)
            {
                cnt = 0;
                while (now <= size[i])
                {
                    now += now - 1;
                    cnt ++;
                }
                now += size[i];
                tot += cnt;
                ans = min (ans, tot + n - i - 1);
            }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
