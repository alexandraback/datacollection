// MS Visual Studio
#include<cstdio>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<map>
#include<vector>
using namespace std;

#define REP(i,n) FOR(i,0,n)
#define FOR(i,s,n) for(int i=(s); i<(n); ++i)
#define sz(X) int((X).size())
#define pb push_back

typedef long long lint;

vector<int> e[1024];
int mk[1024];

int dfs(int v) {
    if(mk[v] != -1) {
        return mk[v];
    }
    int ret = 0;
    REP(i, sz(e[v])) {
        ret += dfs(e[v][i]);
    }
    return mk[v] = ret;
}

int main() {
    freopen("A-small-attempt0 (2).in", "r", stdin);
    freopen("A.out", "w", stdout);
    int tc;
    scanf("%d", &tc);
    FOR(t, 1, tc+1) {
        //cerr << t << endl;
        int n;
        printf("Case #%d: ", t);
        cin >> n;
        REP(i, n) {
            e[i].clear();
            int k;
            cin >> k;
            REP(j, k) {
                int u;
                cin >> u;
                e[i].pb(u - 1);
            }
        }
        bool bad = false;
        REP(i, n) {
            memset(mk, -1, sizeof(mk));
            mk[i] = 1;
            REP(j, n) {
                if(dfs(j) > 1) {
                    bad = true;
                    break;
                }
            }
        }
        printf("%s\n", bad ? "Yes":"No");
    }
}