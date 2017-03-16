#include <bits/stdc++.h>

using namespace std;

#define ll long long

int N;
int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T;
    cin>>T;
    for (int cc = 1; cc <= T; cc++) {
        cin>>N;
        string s;
        cin>>s;

        int l = 0, h = N, res = -1;
        while (l <= h) {
            int m = (l + h) / 2;
            int standing = m + s[0] - '0';
            bool ok = true;
            for (int i = 1; i <= N; i++) {
                int cnt = s[i] - '0';
                if (standing >= i) {
                    standing += cnt;
                } else {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                h = m - 1;
                res = m;
            } else {
                l = m + 1;
            }
        }
        printf("Case #%d: %d\n", cc, res);
    }
    return 0;
}
