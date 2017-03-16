#include <bits/stdc++.h>
using namespace std;

const int MAXD = 1010;
int D;
int P[MAXD];

int attempt(int highest) {
    int extra = 0;
    for (int i=0; i<D; i++) {
        extra += ((P[i]-1) / highest);
    }
    return highest + extra;
}

int main() {
    int T; cin >> T;
    for (int kase=1; kase<=T; kase++) {
        cout << "Case #" << kase << ": ";
        cin >> D;
        for (int i=0; i<D; i++)
            cin >> P[i];
        int ans = MAXD;
        for (int i=1; i<MAXD; i++) {
            ans = min(ans, attempt(i));
        }
        cout << ans << '\n';
    }
    return 0;
}
