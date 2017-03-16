#include <iostream>
#include <cstdlib>
#include <algorithm>
#define MAXN 1010

using namespace std;

int n,p[MAXN];

int main() {
    int T;
    cin >> T;
    for (int TC = 1; TC <= T; TC++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        int ans = MAXN;
        for (int i = 1; i < MAXN; i++) {
            int x = 0;
            for (int j = 0; j < n; j++) {
                x += (p[j] + i - 1) / i - 1;
            }
            ans = min(ans, i + x);
        }
        cout << "Case #" << TC << ": ";
        cout << ans << '\n';
    }
}
