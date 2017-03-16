#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

int a[50 * (50 * 2) - 1], an;

int main() {
    int t, n;
    cin >> t;
    for (int ti = 1; ti <= t; ++ti) {
        cout << "Case #" << ti << ": ";
        cin >> n;
        an = 0;
        for (int i = 0; i < 2 * n - 1; ++i)
            for (int j = 0; j < n; ++j)
                cin >> a[an++];
        std::sort(a, a + an);
        int count = 1;
        for (int i = 1; i < an; ++i)
            if (a[i] != a[i - 1]) {
                if (count % 2) {
                    --n;
                    cout << a[i - 1] << (n ? ' ' : '\n');
                }
                count = 1;
            } else {
                ++count;
            }
        if (count % 2) {
            --n;
            cout << a[an - 1] << (n ? ' ' : '\n');
        }
    }
}
