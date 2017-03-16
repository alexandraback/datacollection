#include <cstdlib>
#include <cstdio>
#include <algorithm>

#define N 10

using namespace std;

int arr[10], e, r, n, ans = 0;

void dfs(int k, int en, int gain) {
    if(k == n) {
        ans = max(ans, gain);
        return;
    }

    for(int i = 0; i <= en; i++) dfs(k + 1, min(en - i + r, e), gain + i * arr[k]);
}

int main() {
    int t;
    scanf("%d", &t);
    for(int p = 1; p <= t; p++) {
        printf("Case #%d: ", p);

        scanf("%d %d %d", &e, &r, &n);
        for(int i = 0; i < n; i++)  scanf("%d", &arr[i]);

        ans = 0;
        dfs(0, e, 0);

        printf("%d\n", ans);
    }
}
