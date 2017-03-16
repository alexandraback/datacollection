#include <bits/stdc++.h>
using namespace std;

int c, d, v;
bool vs[111];

void solve(int ca) {
    cout << "Case #" << ca << ": ";
    cin >> c >> d >> v;
    memset(vs, false, sizeof(vs));
    vs[0] = true;
    for (int i = 0; i < d; i++) {
        int x;
        cin >> x;
        for (int j = v; j >= 0; j--) if (vs[j] && j + x <= v) vs[j + x] = true;
    }

    int res = 0;
    for (int i = 1; i <= v; i++) if (!vs[i]) {
            res++;
            for (int j = v; j >= 0; j--) if (vs[j] && j + i <= v) vs[j + i] = true;
        }
    cout << res << endl;
}

int main() {
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve(i + 1);
    return 0;
}
