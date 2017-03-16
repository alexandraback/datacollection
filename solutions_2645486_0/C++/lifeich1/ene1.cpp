#include<cstdio>
#include<algorithm>
using namespace std;
int TT,sTT,v[21],E,n,R,ans;
void dfs(int r, int e, int k) {
    ans = max(ans, k);
    if (r > n) return ;
    for (int i = max(0, e + R - E); i <= e; ++i)
        dfs(r + 1, min(e - i + R, E), k + i * v[r]);
}
int main() {
    for (scanf("%d", &TT), sTT = TT; TT; --TT) {
        scanf("%d%d%d", &E, &R, &n);
        for (int i = 1; i <= n; ++i) scanf("%d", v + i);
        ans = 0;
        dfs(1, E, 0);
        printf("Case #%d: %d\n", sTT - TT + 1, ans);
    }
    return 0;
}
