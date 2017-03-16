#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;
int C, T;
int a[N][N], mr[N], mc[N];

void run() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    memset(mr, 0, sizeof(mr));
    memset(mc, 0, sizeof(mc));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            mr[i] = max(mr[i], a[i][j]);
            mc[j] = max(mc[j], a[i][j]);
        }
    bool valid = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] < mr[i] && a[i][j] < mc[j])
                valid = false;
    if (valid)
        printf("Case #%d: YES\n", C);
    else
        printf("Case #%d: NO\n", C);
}

int main() {
    scanf("%d", &T);
    for (C = 1; C <= T; C++)
        run();
    return 0;
}
