#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
int num[5000], b[100];
int tot, n, T, tmp;
int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("out2.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        printf("Case #%d:", cas);
        scanf("%d", &n);
        memset(num, 0, sizeof(num));
        tot = 0;
        for (int i = 1; i <= 2 * n  -1; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                scanf("%d", &tmp);
                num[tmp]++;
            }
        }
        for (int i = 1; i <= 2500; ++i)
        {
            if (num[i] & 1)
            {
                b[tot++] = i;
            }
        }
        sort(b, b + n);
        for (int i = 0; i < n; ++i)
        {
            printf(" %d", b[i]);
        }
        printf("\n");
    }
    return 0;
}
