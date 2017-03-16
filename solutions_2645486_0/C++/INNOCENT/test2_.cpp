#include <iostream>
#include <cstring>

#define rep(i, s, t) for (auto i = s; i <= t; ++i)

using namespace std;

int a[10001];
int sp[10001];
long long tr;
long long ans;
long long E, R, N;

void dfs(long long d, long long left) {
    if (d >= N) {
        if (tr > ans) {
            ans = tr;
        }
        return;
    }
    for (int i = left; i >= 0; i--) {
        tr += a[d] * i;
        dfs(d+1, min(E, left - i + R));
        tr -= a[d] * i;
    }
}

int main() {
    int T;
    cin >> T;
    rep (ca, 1, T) {
        cin >> E >> R >> N;
        if (R > E) {
            R = E;
        }
        rep (i, 0, N-1) {
            cin >> a[i];
        }
        memset(sp, 0, sizeof(sp));
        tr = 0;
        ans = 0;
        dfs(0, E);
        cout << "Case #" << ca << ": " << ans << "\n";
    }
    return 0;
}
