#include <bits/stdc++.h>
using namespace std;

int T;
int R, C, W;

void solve() {
    int cnt = C / W;
    if (C % W == 0) {
        cnt += W - 1;
    } else {
        int mod = C % W;
        cnt += mod;
        cnt += W - 1;
    }
    cnt *= R;
    cout << cnt << endl;
}

int main() {
    //freopen("a.in", "r", stdin);
    cin >> T;
    for (int caseID = 1; caseID <= T; ++caseID) {
        cin >> R >> C >> W;
        cout << "Case #" << caseID << ": ";
        solve();
    }
    return 0;
}
