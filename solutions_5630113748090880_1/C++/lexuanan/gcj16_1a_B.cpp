#include <bits/stdc++.h>

using namespace std;

const int MAXVAL = 2500;

int cnt[MAXVAL+5];

int main() {
    //freopen("B.in", "r", stdin);
    //freopen("B.out", "w", stdout);
    int ct;
    cin >> ct;
    for (int nt = 1; nt <= ct; nt++) {
        int n;
        cin >> n;
        for (int i = 1; i <= MAXVAL; i++) cnt[i] = 0;
        int nn = n+n-1;
        for (int i = 0; i < nn; i++) {
            for (int j = 0; j < n; j++) {
                int tmp;
                cin >> tmp;
                cnt[tmp]++;
            }
        }
        cout << "Case #" << nt << ": ";
        for (int i = 1; i <= MAXVAL; i++)
            if (cnt[i] & 1) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}
