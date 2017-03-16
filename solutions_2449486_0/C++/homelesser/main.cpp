#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n, m;
int a[105][105];

int main() {
    freopen("in.1.txt", "r", stdin);
    freopen("out.1.txt", "w", stdout);
    int TT;
    scanf("%d", &TT);
    for (int cas = 1; cas <= TT; cas++) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d", &a[i][j]);
        bool ok = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                bool r = 1, c = 1;
                for (int k = 0; k < n; k++)
                    r &= (a[i][j] >= a[k][j]);
                for (int k = 0; k < m; k++)
                    c &= (a[i][j] >= a[i][k]);
                ok &= (r || c);
            }
        printf("Case #%d: ", cas);
        if (ok) puts("YES");
        else puts("NO");
    }
    return 0;
}