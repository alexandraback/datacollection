#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long, long long>
#define y1 stupid_y1
#define ll long long
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x)*(x))
#define sz(a) (int)a.size()
#define file ""

const int inf = (int)1e9;
const double eps = 1e-9;
const double pi = acos(-1.0);

int n;
int a[1010];
int used[1010];
int level[1010];
int maxval = 0;
vector < int > g[1010];
int S;
bool debug = false;

void dfs(int v, int p, int dep){
    used[v] = 1;
    level[v] = dep;
    int to = a[v];
    if (!used[to]){
        dfs(to, v, dep + 1);
    }
    else if (used[to] == 1){
        maxval = max(maxval, level[v] - level[to] + 1);
    }
    used[v] = 2;
}

void dfs2(int v, int p, int dep){
    used[v] = true;
    S = max(S, dep);
    forit(it, g[v]){
        int to = *it;
        if (to == p) continue;
        if (used[to]) continue;
        dfs2(to, v, dep + 1);
    }
}

void solve(){
    scanf("%d", &n);
    for (int i=0;i<1010;i++) g[i].clear();
    memset(level, 0, sizeof(level));
    memset(used, 0, sizeof(used));
    memset(a, 0, sizeof(a));
    for (int i=1;i<=n;i++){
        scanf("%d", &a[i]);
        g[a[i]].pb(i);
    }
    maxval = 0;
    for (int i=1;i<=n;i++){
        if (used[i]) continue;
        dfs(i, -1, 0);
    }
  
    memset(used, 0, sizeof(used));
    int sum = 0;
    for (int i=1;i<=n;i++){
        if (!used[i] && i == a[a[i]]){
            used[i] = true;
            used[a[i]] = true;
            S = 0;
            dfs2(i, a[i], 1);
            sum += S;
            S = 0;
            dfs2(a[i], i, 1);
            sum += S;
        }
    }
    maxval = max(maxval, sum);
    printf("%d\n", maxval);
}

int main () {
    freopen("a.in", "r", stdin);
    freopen("a2.out", "w", stdout);

    int T;
    scanf("%d", &T);

    for (int i=1;i<=T;i++){
        printf("Case #%d: ", i);
        debug = (i == 13);
        solve();
    }


    #ifdef LOCAL
    cerr << (double)clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif

    return 0;
}