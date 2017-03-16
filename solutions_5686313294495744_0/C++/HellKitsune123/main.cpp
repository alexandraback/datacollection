#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int tt, n;
char s[25];
map<string, int> lma, rma;
int lc, rc;
vector<int> le, ri;
vector<int> g[1000], rev[1000];
int mt[1000];
bool used[1000], vis[1000];

int getHash(map<string, int> &ma, int &cnt, string s) {
    auto it = ma.find(s);
    if (it == ma.end()) {
        ma[s] = cnt;
        return cnt++;
    }
    return it->second;
}

bool dfs(int v) {
    if (vis[v]) return false;
    vis[v] = true;
    for (int to : g[v]) if (mt[to] == -1 || dfs(mt[to])) {
        mt[to] = v;
        return true;
    }
    return false;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &tt);
    for (int test = 1; test <= tt; ++test) {
        printf("Case #%d: ", test);
        lma.clear();
        rma.clear();
        lc = 0, rc = 0;
        le.clear();
        ri.clear();
        scanf("%d", &n);
        REP(i, n) {
            scanf("%s", s);
            le.pb(getHash(lma, lc, string(s)));
            scanf("%s", s);
            ri.pb(getHash(rma, rc, string(s)));
        }
        REP(i, lc) g[i].clear();
        REP(i, rc) rev[i].clear();
        REP(i, n) {
            g[le[i]].pb(ri[i]);
            rev[ri[i]].pb(le[i]);
        }
        REP(i, rc) mt[i] = -1;
        REP(i, lc) used[i] = false;
        int ans = 0;
        REP(i, lc) {
            for (int to : g[i]) if (mt[to] == -1) {
                mt[to] = i;
                used[i] = true;
                ++ans;
                break;
            }
        }
        REP(i, lc) {
            if (used[i]) continue;
            REP(j, lc) vis[j] = false;
            if (dfs(i)) {
                ++ans;
            }
        }
        ans = lc + rc - ans;
        ans = n - ans;
        printf("%d\n", ans);
    }
    return 0;
}
