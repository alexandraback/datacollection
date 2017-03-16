#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int T, r, n, m, k;
int v[10];

bool check(int a, int b, int c)
{
    for (int i = 0; i < k; ++i)
        if (v[i] != 1 && v[i] != a && v[i] != b && v[i] != c
        && v[i] != a * b && v[i] != a * c && v[i] != b * c
        && v[i] != a * b * c) return false;
    return true;
}

void findans()
{
    for (int i = 2; i <= m; ++i)
        for (int j = 2; j <= m; ++j)
            for (int l = 2; l <= m; ++l)
                if (check(i, j, l))
                {
                    printf("%d%d%d\n", i, j, l);
                    return;
                }
}

int main()
{
    freopen("C-small-1-attempt0.in", "r", stdin);
    freopen("2.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        printf("Case #%d:\n", cas);
        scanf("%d%d%d%d", &r, &n, &m, &k);
        for (int p = 0; p < r; ++p)
        {
            for (int i = 0; i < k; ++i) scanf("%d", &v[i]);
            findans();
        }   
    }
    return 0;
}
