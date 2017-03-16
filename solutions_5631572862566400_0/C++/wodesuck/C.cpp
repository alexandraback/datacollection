#include <stdio.h>
#include <string.h>

const int MAXN = 1010;
int n;
int f[MAXN];
bool v[MAXN];
int head, ans;

void dfs(int cur, int last, int d)
{
    if (f[cur] == head) {
        if (d > ans) ans = d;
    }
    if (f[cur] == last) {
        if (d > ans) ans = d;
        v[cur] = true;
        for (int i = 1; i <= n; ++i) {
            if (!v[i]) dfs(i, cur, d + 1);
        }
        v[cur] = false;
    } else if (!v[f[cur]]) {
        v[cur] = true;
        dfs(f[cur], cur, d + 1);
        v[cur] = false;
    }
}

int main()
{
    int dat;
    scanf("%d", &dat);
    for (int cas = 1; cas <= dat; ++cas) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &f[i]);
        memset(v, 0, sizeof(v));
        ans = 0;
        for (int i = 1; i <= n; ++i) dfs(head = i, 0, 1);
        printf("Case #%d: %d\n", cas, ans);
    }
}
