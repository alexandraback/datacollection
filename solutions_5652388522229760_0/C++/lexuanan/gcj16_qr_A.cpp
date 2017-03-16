#include <bits/stdc++.h>

using namespace std;

bool mark[10];

int main() {
    //freopen("A.in", "r", stdin);
    //freopen("A.out", "w", stdout);
    int ct;
    cin >> ct;
    for (int nt = 1; nt <= ct; nt++) {
        int n;
        cin >> n;
        for (int i = 0; i < 10; i++) mark[i] = false;
        int cnt = 10;
        int i;
        for (i = 1; i <= 100; i++) {
            int tmp = n*i;
            while (tmp) {
                int cs = tmp % 10;
                tmp /= 10;
                if (!mark[cs]) {
                    mark[cs] = true;
                    cnt--;
                }
            }
            if (cnt == 0) break;
        }
        cout << "Case #" << nt << ": ";
        if (cnt == 0) cout << n*i << '\n';
        else cout << "INSOMNIA\n";
    }
    return 0;
}
