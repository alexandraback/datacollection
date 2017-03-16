#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <ctime>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define rep(i,a,b) for(int i = a; i < b; ++i)
#define pb(x) push_back(x)
#define sz size()
typedef long long ll;
const int N = 100000 + 11;

int n;

struct T {
    int a, b;
} ar[N];

bool cmp(const T& x, const T& y) {
    if (x.b == y.b) return x.a > y.a;
    return x.b < y.b;
}
bool vis[1003];

int solve() {
    sort(ar, ar + n, cmp);
    int cur = 0, res = 0;
    memset(vis, 0, sizeof (vis));
    for (int i = 0; i < n; ++i) {
        // cout << cur << " " << ar[i].b <<endl;
        while (cur < ar[i].b) {
            bool has = false;
            for (int j = n - 1; j >= i; --j) {
                if (!vis[j] && cur >= ar[j].a) {
                    cur += 1;
                    ++res;
                    has = true;
                    vis[j] = 1;
                    // cout << j << " " << cur <<" " << ar[i].b << endl;
                    break;
                }
            }
            if (!has) break;
        }
        if (cur >= ar[i].b) {
            cur += 1;
            if (!vis[i]) cur += 1;
        } else return -1;
    }
    return res + n;
}

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("out", "w", stdout);
    int cas, tcas = 0;
    cin >> cas;
    for (tcas = 1; tcas <= cas; ++tcas) {
        cin >> n;
        for (int i = 0; i < n; ++i) scanf("%d%d", &ar[i].a, &ar[i].b);

        printf("Case #%d: ", tcas);
        int ans = solve();
        if (ans == -1) printf("Too Bad\n");
        else printf("%d\n", ans);
    }
}
/*
 Case #78: 16
Case #79: 6
Case #80: 17
Case #81: 2
Case #82: 4
Case #83: 11
Case #84: 3
 */
