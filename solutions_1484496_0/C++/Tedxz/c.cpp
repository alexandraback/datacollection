#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
using namespace std;

int T, n, a[510];
int b[510];
long long sa, sb = 0;
bool flag;

void dfs(int k) {
    if (flag) return;
    if (k == n + 1) {
        sa = sb = 0;
        for (int i = 1; i <= n; ++i) {
            if (b[i] == 1)
                sa += a[i];
            if (b[i] == 2)
                sb += a[i];
        }
        if ((sa == sb) && (sb)) {
            flag = true;
        }
        return;
    }
    b[k] = 0;
    dfs(k + 1);
    if (flag) return;
    
    b[k] = 1;
    dfs(k + 1);
    if (flag) return;
    
    b[k] = 2;
    dfs(k + 1);
    if (flag) return;
    
    
    
}

void solve() {
    cin >> n;
    sa = sb = 0;
    flag = false;
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; ++i) 
        cin >> a[i];
    dfs(1);
    if (!flag) {
        cout << "Impossible" << endl;
        return;
    }
    bool fa = false, fb = false;
    for (int i = 1; i <= n; ++i) {
        if (b[i] == 1) {
            if (!fa) { cout << a[i]; fa = true; }
            else { cout << " " << a[i];}
        }
    }
    cout << endl;
    for (int i = 1; i <= n; ++i) {
        if (b[i] == 2) {
            if (!fb) { cout << a[i]; fb = true; }
            else { cout << " " << a[i]; }
        }
    }
    cout << endl;
    
    
}

int main() {
    freopen("C-small-attempt4.in", "r", stdin);
    freopen("c.out", "w", stdout);
    scanf("%d\n", &T);
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d:\n", t);
        solve();
    }

}
