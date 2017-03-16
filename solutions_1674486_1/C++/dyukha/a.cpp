#include <cstdio>
#include <string>
#include <string.h>
#include <memory>
#include <vector>
#include <algorithm>
#include <cassert>
#include <map>

#define fori(i,b,e) for(int i = (b); i < (e); ++i)
#define sz(a) ((int)(a).size())
#define pb push_back
#define mp make_pair

using namespace std;

const int maxn = 1000;
vector<int> a[maxn];

bool was[maxn];

bool dfs(int u) {
    was[u] = true;
    fori(i,0,sz(a[u])) {
        int v = a[u][i];
        if (was[v] || dfs(v)) {
            return true;
        }
    }
    return false;
}

int main() {
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    int TT;
    scanf ("%d\n", &TT);
    for (int tt = 1; tt <= TT; ++tt) {
        //memset(was,0,sizeof(was));
        printf("Case #%d: ", tt);
        int n;
        scanf ("%d", &n);
        fori(i,0,n) {
            was[i] = false;
            a[i].clear();
        }
        fori(i,0,n) {
            int m;
            scanf ("%d", &m);
            fori(j,0,m) {
                int x;
                scanf ("%d", &x);
                x--;
                a[i].pb(x);
            }
        }
        bool has = false;
        fori(i,0,n) {
            fori(j,0,n) {
                was[j] = false;
            }
            if (dfs(i)) {
                has = true;
                break;
            }
        }
        if (has) {
            printf("Yes");
        } else {
            printf("No");
        }
        printf ("\n");
    }
}
