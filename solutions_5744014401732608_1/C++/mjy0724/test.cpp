#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define sz size
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define inf 1000000007

using namespace std;

int n, a[55][55];
ll m, f[55];

void solve() {
    memset(a, 0, sizeof(a));
    memset(f, 0, sizeof(f));
    for (int i = 1; i < n; ++ i)
        for (int j = i + 1; j < n; ++ j) a[i][j] = 1;
    f[1] = 1;
    for (int i = 2; i < n; ++ i)
        for (int j = 1; j < i; ++ j) f[i] += f[j];
    ll sum = 0;
    for (int i = 1; i < n; ++ i) sum += f[i];
    if (sum < m) {
        printf("IMPOSSIBLE\n");
        return ;
    }
    for (int i = n - 1; i; -- i) if (m >= f[i])
        m -= f[i], a[i][n] = 1;
    printf("POSSIBLE\n");
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= n; ++ j) printf("%d", a[i][j]);
        printf("\n");
    }
}

int main() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++ t) {
        scanf("%d%lld", &n, &m);
        printf("Case #%d: ", t);
        solve();
    }
    return 0;
}