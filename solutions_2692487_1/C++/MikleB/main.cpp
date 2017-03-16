#include <iostream>
#include <algorithm>

using namespace std;

long long a[200], b;
int n;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cin >> b >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a, a + n);
        int res = n;
        if (b > 1) {
            for (int j = 0; j < n; ++j) {
                int cnt = j;
                long long x = b;
                for (int i = 0; i < n - j; ++i) {
                    while (a[i] >= x) {
                        x += x - 1;
                        ++cnt;
                    }
                    x += a[i];
                }
                res = min(res, cnt);
            }
        }
        cout << "Case #" << t + 1 << ": " << res << endl;
    }
    
    
    return 0;
}