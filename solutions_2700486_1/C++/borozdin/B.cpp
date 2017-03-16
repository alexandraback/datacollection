#include <iostream>
#include <algorithm>
using namespace std;

int n, _x, y;

void readInput()
{
    scanf("%d%d%d", &n, &_x, &y);
}

void solve()
{
    int level = 0;
    int curCnt = 1;
    int sumCnt = 0;
    while (sumCnt + curCnt <= n)
    {
        level++;
        sumCnt += curCnt;
        curCnt += 4;
    }
    int x = n - sumCnt;

    int posLevel = (abs(_x) + y) / 2;
    int posHeight = y;
    int m = posHeight + 1;
    int l = curCnt / 2;

    if (posLevel < level)
    {
        printf("%.10lf", 1.0);
        return;
    }
    if (posLevel > level)
    {
        printf("%.10lf", 0.0);
        return;
    }
    if (x < m)
    {
        printf("%.10lf", 0.0);
        return;
    }
    if (posHeight == level * 2)
    {
        printf("%.10lf", 0.0);
        return;
    }
    if (l + m <= x)
    {
        printf("%.10lf", 1.0);
        return;
    }

    double comb = 1;
    for (int i = 1; i <= x - m; i++)
    {
        comb *= m + i;
        comb /= i;
        comb /= 2;
    }
    for (int i = 0; i < m; i++)
        comb /= 2;

    double res = comb;
    for (int i = m + 1; i <= x; i++)
    {
        comb /= i;
        comb *= x - i + 1;
        res += comb;
    }

    printf("%.10lf", res);
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
