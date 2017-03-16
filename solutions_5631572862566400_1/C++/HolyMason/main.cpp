#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <bitset>
#define INF 0x3f3f3f3f
#define eps 1e-8
#define FI first
#define SE second
using namespace std;
typedef long long ll;

const int N = 1005;

int F[N];

bool vis[N];

int clen[N], mx[N];

int main() {
    freopen("C-large.in", "r", stdin);;
    freopen("Clarge.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++ cas) {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i) {
            scanf("%d", F + i);
        }
        int ans = 0;
        for(int i = 1; i <= n; ++ i) {
            int len = 1, u;
            memset(vis, 0, sizeof(vis));
            vis[i] = true;
            for(u = F[i]; !vis[u]; u = F[u]) {
                ++ len;
                vis[u] = true;
            }
            if(u == i) {
                clen[i] = len;
            } else {
                clen[i] = -1;
            }
            ans = max(ans, clen[i]);
        }
        memset(mx, 0, sizeof(mx));
        for(int i = 1; i <= n; ++ i) {
            int u = i, len = 0;
            while(clen[u] == -1) {
                u = F[u];
                ++ len;
            }
            mx[u] = max(mx[u], len);
        }
        int tot = 0;
        for(int i = 1; i <= n; ++ i) {
            if(clen[i] == 2) {
                tot += mx[i] + 1;
            }
        }
        ans = max(ans, tot);
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}
