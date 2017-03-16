#include <iostream>
#include <cstring>
using namespace std;

typedef long long LL;

const int MAX = 200;

int n, m;
LL a[MAX], A[MAX], b[MAX], B[MAX];
LL f[MAX][MAX];

LL solve() {
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (A[i] == B[j]) {
                int k2 = j;
                LL aa = 0, bb = 0;
                for (int k1 = i; k1; --k1) {
                    if (A[k1] != A[i]) continue;
                    aa += a[k1];
                    while (bb < aa && k2) {
                        if (B[k2] == B[j])
                            bb += b[k2];
                        f[i][j] = max(f[i][j], f[k1 - 1][k2 - 1] + min(aa, bb));
                        --k2;
                    }
                    f[i][j] = max(f[i][j], f[k1 - 1][k2] + min(aa, bb));
                }
            }
        }
    return f[n][m];
}

int main() {
    int t;
    cin >> t;
    for (int tt = 1; tt <= t; ++tt) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            cin >> a[i] >> A[i];
        for (int i = 1; i <= m; ++i)
            cin >> b[i] >> B[i];
        cout << "Case #" << tt << ": " << solve() << '\n';
    }

    return 0;
}
