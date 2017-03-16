#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, k;

int ans;
void dfs(int i, int gap, int cst, int wt, int flg = 1) {
    if (i >= n) return;
    if (gap > m) return;
    if (gap < 0) return;

    if (gap == m) flg = 0;

    int lcst = max(gap-2, 0);
    int new_wt = wt + lcst;
    int new_cst = cst + lcst + max(0, k - new_wt);
    if (ans > new_cst) {
        ans = new_cst;
    }

    for (int d = -2; d <= 2; ++d) {
        if (flg >  0 && d <  0) continue;
        if (flg == 0 && d >  0) continue;
        if (flg <  0 && d >= 0) continue;
        dfs(i+1, gap+d, cst+2, wt+gap+d, d > 0 ? 1 : (d == 0 ? 0 : -1));
    }
}

int jizz() {
    scanf("%d%d%d", &n, &m, &k);

    if (n > m) std::swap(n, m);

    if (n <= 2) return k;
    if (k <= 3) return k;

    ans = 1e9;

    for (int i = 1; i <= m; ++i)
        dfs(1, i, i, i);

    return ans;
}

int main() {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d: %d\n", t, jizz());
    }

    return 0;
}
