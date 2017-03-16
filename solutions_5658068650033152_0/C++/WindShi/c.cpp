#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, n, m, f[101], a[21][21], re, Min, pos[21][21];

int gf(int i){
    if (i == f[i]) return i;
    return f[i] = gf(f[i]);
}

int main(){
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    scanf("%d", &test);
    for (int uu = 1; uu <= test; uu++)
    {
        printf("Case #%d: ", uu);
        scanf("%d%d%d", &n, &m, &re);
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                pos[i][j] = cnt++;
        Min = 1 << 30;
        for (int i = 0; i < 1 << (n * m); i++)
        {
            int use = 0;
            for (int j = 0; j < n; j++)
                for (int k = 0; k < m; k++)
                    if (i & (1 << pos[j][k])) a[j][k] = 1, ++use;
                    else a[j][k] = 0;
            if (use >= Min) continue;
            for (int j = 0; j <= cnt; j++) f[j] = j;
            for (int j = 0; j < n; j++)
                for (int k = 0; k < m; k++)
                if (!a[j][k])
                {
                    if (j == 0 || j == n - 1 || k == 0 || k == m - 1)
                       f[gf(pos[j][k])] = gf(cnt);
                    if (j != n - 1 && !a[j + 1][k])
                       f[gf(pos[j][k])] = gf(pos[j + 1][k]);
                    if (k != m - 1 && !a[j][k + 1])
                       f[gf(pos[j][k])] = gf(pos[j][k + 1]);
                }
            int will = 0;
            for (int j = 0; j < n; j++)
                for (int k = 0; k < m; k++)
                    if (gf(pos[j][k]) != gf(cnt)) ++will;
            if (will >= re) Min = use;
        }
        printf("%d\n", Min);
    }
}
