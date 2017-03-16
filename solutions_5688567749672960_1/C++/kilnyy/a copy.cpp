#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <queue>

#define REP(i,n) for(int i=0;i<(n);i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,n) for(int i=1;i<=(n);i++)
#define FORD(i,n) for(int i=(n);i>=1;i--)

#define SZ(x) ((int)x.size())
#define CC(a,x) memset(a,x,sizeof(a))
#define TWO(x) ((LL)1<<(x))

using namespace std;

int T, n;

int f[1000001];

int reverse(int x) {
    int res = 0;
    while (x % 10 == 0) {
        x /= 10;
    }
    while (x) {
        res = res * 10 + (x % 10);
        x /= 10;
    }
    return res;
}

queue<int> Q;

void solve() {
    scanf("%d", &n);
    memset(f, -1, sizeof(f));
    f[1] = 1;
    Q = queue<int>();
    Q.push(1);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (u == n) break;
        if (f[u+1] == -1 || f[u+1] > f[u] + 1) f[u+1] = f[u] + 1, Q.push(u+1);
        if (f[reverse(u)] == -1 || f[reverse(u)] > f[u] + 1) f[reverse(u)] = f[u] + 1, Q.push(reverse(u));
    }
    for (int i=1;i<=n;i++) printf("%d ", f[i]);
    printf("%d", f[n]);
}

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &T);
    for (int i=1; i<=T; i++) {
        printf("Case #%d: ", i);
        solve();
        printf("\n");
    }
    return 0;
}
