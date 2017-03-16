#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    
    int tot;
    cin >> tot;
    for (int task = 1; task <= tot; task++) {
        int e, r, n;
        cin >> e >> r >> n;
        int v[10];
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        int f[11][6];
        memset(f, 0, sizeof(f));
        for (int i = 0; i < e; i++) {
            f[0][i] = -1;
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= e; j++) {
                if (f[i][j] >= 0) {
                    for (int k = 0; k <= j; k++) {
                        f[i + 1][min(e, j - k + r)] >?= f[i][j] + k * v[i];
                    }
                }
            }
        int ans = 0;
        for (int i = 0; i <= e; i++) {
            ans = max(ans, f[n][i]);
        }
        cout << "Case #" << task << ": " << ans << endl;
    }
}
