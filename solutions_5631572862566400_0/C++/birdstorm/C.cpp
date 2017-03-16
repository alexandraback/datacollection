#include <bits/stdc++.h>
using namespace std;
const int MAXN = 11;
int g[MAXN], ti[MAXN];
bool vis[MAXN];
int order[MAXN];
int ans;
void dfs(int x, int t) {
    ti[x] = t;
    vis[x] = 1;
    int y = g[x];
    if(!vis[y]) dfs(y, t + 1);
    else {
        ans = max(ans, t - ti[y] + 1);
    }
}
inline bool isadj(int x, int y) { /// x --> y
    return (g[x] == y);
}
int main() {
    freopen("C-small-attempt2.in", "r", stdin);
    freopen("C-small-attempt2.out", "w", stdout);
    int T; cin>>T;
    for(int cs = 1; cs <= T; cs ++) {
        cerr << "Processing Case #" << cs << "...\n";
        printf("Case #%d: ", cs);
        int n; cin >> n;
        for(int i = 1; i <= n; i ++) {
            scanf("%d", &g[i]);
        }
        ans = 1;
        for(int len = 1; len < (1 << n); len ++) {
            int cnt = 0;
            for(int i = 1; i <= n; i ++) {
                if(len >> (i - 1) & 1) {
                    order[++ cnt] = i;
                }
            }
            if(cnt <= ans) continue;
            do {
                for(int j = 1; j <= cnt; j ++) {
                    if(!isadj(order[j], order[j == cnt ? 1 : j + 1]) && !isadj(order[j], order[j == 1 ? cnt : j - 1])) goto no;
                }
                ans = cnt;
                break;
                no:;
            } while(next_permutation(order + 1, order + cnt + 1));
        }
        printf("%d\n", ans);
    }
    return 0;
}


