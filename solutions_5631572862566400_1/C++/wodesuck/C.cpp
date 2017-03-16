#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAXN = 1010;
int n;
int f[MAXN];
int g[MAXN];
bool v[MAXN];
int ans;

void walk(int head)
{
    memset(v, 0, sizeof(v));
    int i = head, last = 0, len = 1;
    for (;;) {
        v[i] = true;
        if (f[i] == head) ans = max(ans, len);
        if (f[i] == last) {
            g[i] = max(g[i], len);
            break;
        } else if (v[f[i]]) {
            break;
        }
        last = i;
        i = f[i];
        ++len;
    }
}

int main()
{
    int dat;
    scanf("%d", &dat);
    for (int cas = 1; cas <= dat; ++cas) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &f[i]);
        memset(g, 0, sizeof(g));
        ans = 0;
        for (int i = 1; i <= n; ++i) walk(i);
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (f[f[i]] == i && i < f[i]) {
                sum += g[i] + g[f[i]] - 2;
            }
        }
        ans = max(ans, sum);
        printf("Case #%d: %d\n", cas, ans);
    }
}
