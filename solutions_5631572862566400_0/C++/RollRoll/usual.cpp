#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <functional>
#include <cstdlib>
#include <climits>
#include <cctype>
using namespace std;
#define REP(i,x) for(int i = 0; i < (x); i++)
#define DEP(i,x) for(int i = (x) - 1; i >= 0; i--)
#define FOR(i,x) for(__typeof(x.begin())i=x.begin(); i!=x.end(); i++)
#define set(a,x) memset(a, x, sizeof(a))
#define mo(a,b) (((a)%(b)+(b))%(b))
#define ALL(x) (x).begin(), (x).end()
#define SZ(v) ((int)v.size())
#define UNIQUE(v) sort(ALL(v)); v.erase(unique(ALL(v)), v.end())
#define out(x) cout << #x << ": " << x << endl;
#define fastcin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define inf 0x3f3f3f3f
#define MOD 1000000007
#define eps 1e-8
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define IT iterator
#define X first
#define Y second
// ************************************************************************

int n;
int g[1001][1001];
bool vis[1001];

int dfs(int fi, int pre, int u, int num, bool right) {
    // cout << fi << " " << pre << " " << u << " " << num << endl;
    vis[u] = 1;
    bool f = 0;
    int rt = 0;
    if (g[fi][u] || g[u][fi]) rt = num;
    for (int i = 0; i < n; i++)
        if (g[u][i] && !vis[i]) {
            f = 1;
            rt = max(rt, dfs(fi, u, i, num + 1, 0));
            vis[i] = 0;
        }
    if (!f && (pre != -1 && (g[u][pre]))) {
        for (int i = 0; i < n; i++)
            if (g[i][u] && !vis[i]) {
                f = 1;
                rt = max(rt, dfs(fi, u, i, num + 1, 1));
                vis[i] = 0;
            }
        if (!f) {
            // if (pre != -1 && (g[u][pre] || g[pre][u])) return num;
            // cout << fi << " " << pre << " " << u << " " << num << endl;
            if (pre != -1 && (g[u][pre] || g[pre][u])) rt =  max(rt, num);
            if (g[fi][u] || g[u][fi]) rt =  max(rt, num);
            // if(right && )
            // return 0;
        }
    }

    return rt;
}

int main() {
#ifdef MANGOGAO
    // freopen("data.in", "r", stdin);
    freopen("/Users/Lodour/Downloads/C-small-attempt2.in", "r", stdin);
    // freopen("/Users/Lodour/Downloads/B-large.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    int t, cnt = 0, tmp;
    scanf("%d", &t);
    while (t--) {
        set(g, 0); set(vis, 0);
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            g[i][tmp - 1] = 1;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            set(vis, 0);
            ans = max(ans, dfs(i, -1, i, 1, 0));
        }
        printf("Case #%d: %d\n", ++cnt, ans);

    }
    return 0;
}
