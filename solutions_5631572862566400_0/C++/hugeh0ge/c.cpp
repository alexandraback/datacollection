#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define PATH 0
#define CYCLE 1

int T;
int n;
int num_cycle;
int par[1001];
int deg[1001];
int state[1001];
vector<int> res[1001];
vector<int> cycles[10001];
int on_what[1001];

int dfs(int v) {
    if (state[v] == 2) {
        return -1;
    }

    if (state[v] == 1) {
        return v;
    }

    state[v] = 1;
    on_what[v] = PATH;
    int ret = dfs(par[v]);
    state[v] = 2;
    if (ret == -1) {
        return -1;
    }

    on_what[v] = CYCLE;
    cycles[num_cycle].push_back(v);
    if (v == ret) return -1;
    return ret;
}

int calc(int v) {
    int ret = 0;
    for (int i=0; i<res[v].size(); i++) {
        int u = res[v][i];
        if (on_what[u] == CYCLE) continue;
        ret = max(ret, calc(u));
    }
    return ret+1;
}

int main() {
    scanf("%d", &T);
    for (int Case=1; Case<=T; Case++) {
        scanf("%d", &n);
        num_cycle = 0;
        for (int i=0; i<n; i++) {
            res[i].clear();
            deg[i] = 0;
            state[i] = 0;
        }

        for (int i=0; i<n; i++) {
            scanf("%d", &par[i]);
            par[i]--;
            deg[par[i]]++;
            res[par[i]].push_back(i);
        }

        for (int i=0; i<n; i++) {
            if (!deg[i] && !state[i]) {
                cycles[num_cycle].clear();
                dfs(i);
                if (!cycles[num_cycle].empty()) ++num_cycle;
            }
        }

        for (int i=0; i<n; i++) {
            if (!state[i]) {
                cycles[num_cycle].clear();
                dfs(i);
                if (!cycles[num_cycle].empty()) ++num_cycle;
            }
        }

        int ans = 0;
        int sum = 0;
        for (int i=0; i<num_cycle; i++) {
            ans = max(ans, (int)cycles[i].size());
            if (cycles[i].size() == 2) {
                int u = cycles[i][0];
                int v = cycles[i][1];
                int ans1 = 0, ans2 = 0;

                for (int j=0; j<res[u].size(); j++) {
                    int w = res[u][j];
                    if (on_what[w] == CYCLE) continue;
                    ans1 = max(ans1, calc(w));
                }

                for (int j=0; j<res[v].size(); j++) {
                    int w = res[v][j];
                    if (on_what[w] == CYCLE) continue;
                    ans2 = max(ans2, calc(w));
                }

                sum += ans1+ans2+2;
            }
        }
        ans = max(ans, sum);
        printf("Case #%d: %d\n", Case, ans);
    }
}
