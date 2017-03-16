#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int const maxB = 60;

int b;
long long m;

int matr[maxB][maxB];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int q;
    cin >> q;
    for (int t = 1; t <= q; ++t)
    {
        cin >> b >> m;
        printf("Case #%d: ", t);
        if (b == 2)
        {
            if (m == 1)
            {
                printf("POSSIBLE\n01\n00\n");
            }
            else
            {
                printf("IMPOSSIBLE\n");
            }
            continue;
        }
        if (m > (1ll << (b - 2)))
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        memset(matr, 0, sizeof(matr));
        for (int i = 1; i < b; i++)
        {
            for (int j = i + 1; j < b; j++)
            {
                matr[i][j] = 1;
            }
        }
        if (m == (1ll << (b - 2)))
        {
            for (int i = 1; i < b; i++)
            {
                matr[i][b] = 1;
            }
        }
        else
        {
            for (int i = 2; i < b; i++)
            {
                if (m & (1ll << (i - 2)))
                {
                    matr[i][b] = 1;
                }
            }
        }
        printf("POSSIBLE\n");
        for (int i = 1; i <= b; i++)
        {
            for (int j = 1; j <= b; j++)
            {
                printf("%d", matr[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}