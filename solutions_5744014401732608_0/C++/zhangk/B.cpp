#include<iostream>
#include<cstring>
#include<cstdio>
#define LL long long
using namespace std;

int T, a[55][55],kase = 0;
LL n, M;

void add(int k)
{
    int i, j;
    for (i = 1; i < k; i++)
        for (j = i + 1; j <= k; j++)
            a[i][j] = 1;
    if (k != n) a[k][n] = 1;
}

int main()
{
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        int i, j;
        cin >> n >> M;
        printf("Case #%d: ", ++kase);
        if (M > (1LL << (n - 2)))
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        printf("POSSIBLE\n");
        memset(a, 0, sizeof(a));
        for (i = 1; i <= n; i++)
            if (M & (1LL << (i - 1))) add(i + 1);
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
                printf("%d", a[i][j]);
            printf("\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
