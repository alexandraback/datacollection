#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <strstream>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair
#define A first
#define B second
#define eps 1e-8

#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int t, n, gs[1010];
bool lin[1010][1010], vis[1010], vis1[1010];
bool flag;

void dfs(int t) {
    if (vis[t]) {
        flag = true;
        return ;
    }
    vis[t] = true;
    vis1[t] = true;
    for (int i = 1; i <= n; i ++ )
        if (lin[t][i]) {
            dfs(i);
            if (flag) return;
        }
}

int main() {
    freopen("A-large.in","r",stdin);
    freopen("A2.out","w",stdout);
    scanf("%d", &t);
    for (int i = 1; i <= t; i ++ ) {
        scanf("%d", &n);
        memset(lin, 0, sizeof(lin));
        memset(gs, 0, sizeof(gs));
        for (int j = 1; j <= n; j ++) {
            int x, y;
            scanf("%d", &x);
            for (int k = 0; k < x; k ++ ) {
                scanf("%d", &y);
                lin[j][y] = true;
                gs[y] ++ ;
            }
        }
        flag = false;
        memset(vis1, 0, sizeof(vis1));
        for (int j = 1; j <= n; j ++ )
            if (gs[j] == 0) {
                memset(vis, 0, sizeof(vis));
                dfs(j);
                if (flag) break;
            }
        for (int j = 1; j <= n; j ++ )
            if (!vis1[j]) {
                memset(vis, 0, sizeof(vis));
                dfs(j);
                if (flag) break;
            }
        if (flag) printf("Case #%d: Yes\n", i);
        else printf("Case #%d: No\n", i);
    }
    return 0;
}
