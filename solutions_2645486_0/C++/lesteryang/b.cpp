#include "iostream"
#include "cstdio"
#include "cstring"
#include "algorithm"
#include "vector"
#include "queue"
#include "stack"
#include "cmath"
#include "string"
#include "cctype"
#include "map"
#include "iomanip"
#include "set"
#include "utility"
using namespace std;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lc(x) (x << 1)
#define rc(x) (x << 1 | 1)
#define lowbit(x) (x & (-x))
#define ll long long
#define ull unsigned long long
const int inf = 1 << 29;
const double dinf = 1e30;
const ll linf = 1LL << 55;
const int N = 111;
int e, r, n;
ll v[N];
ll dp[N][10];

ll dfs(int i, int ee) {
    if (i == n) return 0;
    if (dp[i][ee] != -1) return dp[i][ee];
    ll res = 0;
    for (int j = 0; j <= ee; j++) {
        res = max(res, j * v[i] + dfs(i + 1, min(ee - j + r, e)));
    }
    return dp[i][ee] = res;
}

int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("b.out", "w", stdout);
    int T, Case = 1;
    cin >> T;
    while (T--) {
        cin >> e >> r >> n;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        memset(dp, -1, sizeof(dp));
        printf("Case #%d: ", Case++);
        cout << dfs(0, e) << endl;
        //for (int i = 0; i < n; i++) {
            //for (int j = 0; j <= e; j++) {
                //cout << dp[i][j] << " ";
            //}
            //cout << endl;
        //}
    }
    return 0;
}
