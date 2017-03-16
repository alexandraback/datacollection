#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_N = 110;

int T, ans, n, k, size[MAX_N];
long long a;

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("a.out", "w", stdout);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> a >> n;
        for (int i = 0; i < n; ++i) 
            cin >> size[i];
        ans = n; k = 0;
        sort(size, size + n);
        if (a == 1) {
            ans = n;
            cout << "Case #" << t << ": " << ans << endl;
            continue;
        }
        for (int i = 0; i < n && k <= n; ++i) {
            ans = min(ans, (n - i) + k);
            while (a <= size[i]) {
                ++k;
                a = a * 2 - 1;
            }
            a += size[i];
        }
        ans = min(ans, k);
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
