#include <cstdio>
#include <queue>
using namespace std;
int cnt[1010];
int n;
int a[1010];

int solve(int x) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] <= x) continue;
        else {
            cnt += (a[i] - 1) / x;
        }
    }
    return cnt + x;
}

int main() {
    int T;

    scanf("%d", &T);
    for (int kase = 1; kase <= T; kase++) {
        scanf("%d", &n);
        int x;
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            maxi = max(maxi, a[i]);
        }

        int ans = 1000000000;
        for (int i = 1; i <= maxi; i++) {
            ans = min(ans, solve(i));
        }

        printf("Case #%d: %d\n", kase, ans);
    }
        
    return 0;
}
