#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int , int>;
using pll = pair <ll , ll>;
const ll inf = 1;
const ll mod = 1E9;

#define SZ 1000010

int dp[SZ];
queue <int> Q;

int f (int n) {
    int ret = 0;
    while (n) {
        ret = ret * 10 + (n % 10);
        n /= 10;
    }
    return ret;
}

void bfs () {
    while (!Q.empty()) Q.pop();
    Q.push(1);
    dp[1] = 1;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (u + 1 <= 1E6 && dp[u + 1] > dp[u] + 1) {
            dp[u + 1] = dp[u] + 1;
            Q.push(u + 1);
        }
        int v = f (u);
        if (v <= 1E6 && dp[v] > dp[u] + 1) {
            dp[v] = dp[u] + 1;
            Q.push(v);
        }
    }
    return;
}

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
        freopen("2.txt", "w", stdout);
    #endif

//    for (int i = 0; i < 30; i++) {
//        cout << ">> " << i << ' ' << f(i) << '\n';
//    }

    for (int i = 1; i <= 1E6; i++) {
        dp[i] = 1E7;
    }
    bfs();

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        int n;
        scanf("%d", &n);
        printf("Case #%d: %d\n", cs + 1, dp[n]);
    }


    return 0;
}







