#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1050;
int TC, N, F[MAXN], cc[MAXN], dp[MAXN];
vector<int> adjList[MAXN];
bitset<MAXN> v, comp;
int fc (int x, int p, int s) {
    if (v[x]) return 0;
    v[x] = 1;
    if (F[x] == s) return 1;
    int r = fc(F[x], x, s);
    if (r) return r+1;
    else return 0;
}
int dfs(int x, int s) {
    if (x == s) return 0;
    if (v[x]) return dp[x];
    v[x] = dp[x] = 1;
    for (auto it:adjList[x]) {
        dp[x] = max(dp[x], 1+dfs(it, s));
    }
    return dp[x];
}
int main () {
    scanf("%d", &TC);
    for (int T = 1; T <= TC; ++T) {
        scanf("%d", &N);
        
        //1-indexed
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &F[i]);
            adjList[F[i]].push_back(i);
        }
        int ans = 0;
        memset(cc, 0, sizeof cc);
        comp.reset();
        for (int i = 1; i <= N; ++i) {
            if (comp[i]) continue;
            v.reset();
            cc[i] = fc(i, -1, i);
            if (cc[i]) {
                for (int x = i; F[x] != i; x = F[x]) {
                    comp[x] = 1;
                    comp[F[x]] = 1;
                }
                ans = max(ans, cc[i]);
                //printf("At %d ans = %d\n", i, cc[i]);
            }
        }
        int sum = 0;
        for (int i = 1; i <= N; ++i) {
            if (cc[i] != 2) continue;
            v.reset();
            sum +=  dfs(i, F[i]) + dfs(F[i], i);
            //printf("at %d sum += %d + %d\n", i, dfs(i, F[i]), dfs(F[i], i));
            
        }
        for (int i = 1; i <= N; ++i) adjList[i].clear();
        printf("Case #%d: %d\n", T, max(ans, sum));
    }
}