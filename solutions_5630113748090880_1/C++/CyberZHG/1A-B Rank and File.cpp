#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, n, m, a;
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d", &n);
        map<int, int> cnt;
        m = (2 * n - 1) * n;
        for (int i = 0; i < m; ++i) {
            scanf("%d", &a);
            cnt[a] += 1;
        }
        vector<int> ans;
        for (auto it : cnt) {
            if (it.second & 1) {
                ans.push_back(it.first);
            }
        }
        sort(ans.begin(), ans.end());
        assert((int)ans.size() == n);
        printf("Case #%d:", t);
        for (int i = 0; i < n; ++i) {
            printf(" %d", ans[i]);
        }
        putchar('\n');
    }
    return 0;
}
