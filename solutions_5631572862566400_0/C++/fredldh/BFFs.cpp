#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define N 1000

int n, res1, res2;
int b[N+1], chk[N+1];

int depth(vector<vector<int> >& adj, int x) {
    int dep = 1;
    for(int i = 0, cn = adj[x].size(); i < cn; ++i) {
        if(chk[adj[x][i]] == 0) {
            chk[adj[x][i]] = 1;
            dep = max(dep, depth(adj, adj[x][i]) + 1);
        }
    }
    return dep;
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T, t = 1;
    for(scanf("%d", &T); (T--); ++t) {
        scanf("%d", &n); res1 = res2 = 0;
        for(int i = 1; i <= n; ++i) scanf("%d", &b[i]);
        for(int i = 1; i <= n; ++i) chk[i] = 0;
        vector<int> cyc;
        for(int i = 1; i <= n; ++i) {
            if(chk[i] == 0) {
                int last = b[i]; chk[i] = i;
                for(int j = b[i]; chk[j] == 0; j = b[j], last = j) {
                    chk[j] = i;
                }
                if(chk[last] == i) cyc.push_back(last);
            }
        }
        for(int i = 1; i <= n; ++i) chk[i] = 0;
        vector<vector<int> > adj(n+1);
        for(int j = 1; j <= n; ++j) adj[b[j]].push_back(j);
        for(int i = 0, cycn = cyc.size(); i < cycn; ++i) {
            vector<int> comp(1, cyc[i]), dep;
            chk[cyc[i]] = 1;
            for(int j = b[cyc[i]]; j != cyc[i]; j = b[j]) {
                chk[j] = 1; comp.push_back(j);
            }
            if(comp.size() == 2) {
                for(int j = 0, compn = comp.size(); j < compn; ++j) dep.push_back(depth(adj, comp[j]));
                int cnt = 0;
    //            printf("%d %d\n", comp.size(), dep.size());
    //            for(int j = 0, compn = comp.size(); j < compn; ++j) printf("%d %d\n", comp[j], dep[j]);
                for(int j = 0, compn = comp.size(); j < compn; ++j) cnt = max(cnt, compn + dep[j] + dep[(j+1)%compn] - 2);
                res2 = res2 + cnt;
            }
            else res1 = max(res1, (int)comp.size());
        }
        printf("Case #%d: %d\n", t, max(res1, res2));
    }
    return 0;
}
