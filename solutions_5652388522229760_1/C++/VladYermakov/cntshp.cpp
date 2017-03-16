#include <bits/stdc++.h>

using namespace std;

main () {
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);

    int T;
    cin >> T;

    int num = 1;

    while (T--) {
        cout << "Case #" << num << ": ";
        num++;
        int n;
        cin >> n;
        if (n == 0) cout << "INSOMNIA\n";
        else {
            int cnt = 0;
            int q[10] = {0};
            int i = 1;
            while (cnt < 10) {
                int x = n * i;
                while (x > 0) {
                    ++q[x % 10];
                    if (q[x % 10] == 1) ++cnt;
                    x /= 10;
                }
                ++i;
            }
            cout << (i - 1) * n << "\n";
        }
    }

}
