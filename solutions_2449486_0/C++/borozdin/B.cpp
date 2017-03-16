#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200;

int n, m, a[N][N];
bool used[N][N];

void read()
{
    memset(used, 0, sizeof(used));

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
}

void solve()
{
    while (true)
    {
        int maxVal = -1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!used[i][j])
                    maxVal = max(maxVal, a[i][j]);
        if (maxVal == -1)
            break;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j] == maxVal)
                {
                    bool fail1 = false;
                    for (int t = 0; t < n && !fail1; t++)
                        if (used[t][j])
                            fail1 = true;

                    bool fail2 = false;
                    for (int t = 0; t < m && !fail2; t++)
                        if (used[i][t])
                            fail2 = true;

                    if (fail1 && fail2)
                    {
                        printf("NO\n");
                        return;
                    }
                }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (a[i][j] == maxVal)
                    used[i][j] = true;
    }

    printf("YES\n");
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tstCnt;
    scanf("%d", &tstCnt);
    for (int tst = 1; tst <= tstCnt; tst++)
    {
        read();
        printf("Case #%d: ", tst);
        solve();
    }

    return 0;
}
