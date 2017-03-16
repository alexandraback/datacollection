#include <cstdio>

void solve()
{
    long long t, s = 0;
    scanf("%lld", &t);
    if (t == 0)
    {
        printf("INSOMNIA\n");
        return;
    }
    bool shown[10] = {0};
    int cnt = 0;
    while (cnt < 10)
    {
        s += t; 
        for (long long tmp = s; tmp; tmp /= 10)
        {
            int digit = tmp % 10;
            if (!shown[digit])
            {
                cnt++;
                shown[digit] = 1;
            }
        }
        // printf("%d %lld\n", cnt, s);
    }
    printf("%lld\n", s);
    // for (int i = 0; i < 10; i++)printf("%d ", shown[i]);
}

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
