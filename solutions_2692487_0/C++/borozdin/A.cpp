#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200;
const int INF = 1e9;

int a, n, w[N];

void readInput()
{
    scanf("%d%d", &a, &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);
}

void solve()
{
    sort(w, w + n);

    int cur = 0;
    int best = INF;
    bool gone = false;
    for (int i = 0; i < n; i++)
    {
        if (a > w[i])
            a += w[i];
        else
        {
            best = min(best, cur + n - i);
            if (a == 1)
            {
                gone = true;
                break;
            }
            while (a <= w[i])
            {
                a += a - 1;
                cur++;
            }
            a += w[i];
        }
    }
    if (!gone)
        best = min(best, cur);

    printf("%d", best);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tstCnt;
    scanf("%d", &tstCnt);

    for (int i = 0; i < tstCnt; i++)
    {
        readInput();
        printf("Case #%d: ", i + 1);
        solve();
        printf("\n");
    }

    return 0;
}
