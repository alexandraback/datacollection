#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>

#define REP(i,n) for(int i=0;i<(n);i++)
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))
#define SIZE(x) (int)(x).size()

#define MP make_pair
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

int n;
int F[1010];
int g[1010];

bool vis[1010];
bool inCircle[1010];
int ord[1010];
int a[1010];

int gao(int u) {
    FILL(ord, 0xff);
    int cnt = 0;
    vis[u] = true;
    a[cnt] = u;
    ord[u] = cnt++;
    for (u = F[u]; ord[u] == -1; u = F[u]) {
        vis[u] = true;
        a[cnt] = u;
        ord[u] = cnt++;
    }
    for (int i = ord[u]; i < cnt; ++i) {
        inCircle[a[i]] = true;
    }
    return cnt - ord[u];
}

void Solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", F + i);
    }
    int ans = 1;
    CLEAR(vis);
    CLEAR(inCircle);
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            ans = max(ans, gao(i));
        }
    }
    CLEAR(g);
    for (int i = 1; i <= n; ++i) {
        if (!inCircle[i]) {
            int cnt = 0, j;
            for (j = i; !inCircle[j]; j = F[j]) {
                ++cnt;
            }
            g[j] = max(g[j], cnt);
        }
    }
    int all = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (F[i] == j && F[j] == i) {
                all += 2 + g[i] + g[j];
            }
        }
    }
    ans = max(ans, all);
    cout << ans << endl;
}

int main() {
//	freopen("C.in","r",stdin);
//	freopen("C-small-attempt0.in","r",stdin);freopen("C-small-attempt0.out","w",stdout);
	freopen("C-small-attempt1.in","r",stdin);freopen("C-small-attempt1.out","w",stdout);
//	freopen("C-small-attempt2.in","r",stdin);freopen("C-small-attempt2.out","w",stdout);
//	freopen("C-large.in","r",stdin);freopen("C-large.out","w",stdout);
    int cas;
    cin >> cas;
    for (int T = 1; T <= cas; ++T) {
        printf("Case #%d: ", T);
        Solve();
        cerr << "Case #" << T << ": done!" << endl;
    }
    return 0;
}

