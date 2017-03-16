#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int a[110][110];
int r[110], c[110];
int t, n, m;

bool judge() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] < r[i] && a[i][j] < c[j])
                return false;
    return true;
}

int main() {
    freopen("t.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);
    scanf("%d", &t);
    for (int z = 1; z <= t; z++) {
        scanf("%d%d", &n, &m);
        memset(r, 0, sizeof(r));
        memset(c, 0, sizeof(c));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                scanf("%d", &a[i][j]);
                r[i] = max(r[i], a[i][j]);
                c[j] = max(c[j], a[i][j]);
            }
        printf("Case #%d: ", z);
        if (judge())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
