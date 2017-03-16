#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int a[1024];
vector<int> b[1024];
int u[1024];

void read() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) b[i].clear();
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        -- a[i];
        b[ a[i] ].push_back (i);
    }
}

int go (int x) {
    int &ans = u[x];
    if (ans != -1) return ans;

    ans = 1;
    for (int i = 0; i < (int)b[x].size(); i++) {
        ans = max(ans, go(b[x][i]) + 1);
    }

    return ans;
}

int get(int x) {
    int ans = 0;
    for (int i = 0; i < (int)b[x].size(); i++) {
        if (b[x][i] != a[x]) {
            ans = max(ans, go(b[x][i]));
        }
    }
    return ans;
}

void solve() {
    int ans = 0;
    int d[1024];
    memset (u ,-1, sizeof u);
    memset (d, 0, sizeof d);

    for (int i = 0; i < n; i++) {
        if (a[ a[i] ] == i && !d[i]) {
            ans += 2 + get(i) + get(a[i]) ;
            d[i] = d[a[i]] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        memset(u, 0, sizeof u);
        int cur = 1;

        for (int j = i; !u[j]; j = a[j]) {
            if (a[j] == i)
                ans = max(ans, cur);
            u[j] = 1;
            ++ cur;
        }
    }
    printf ("%d\n", ans);
}

int main() {
    int cases;

    scanf("%d", &cases);
    for (int i=1; i<=cases; i++) {
        read();
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}

