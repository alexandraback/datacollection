#include <iostream>
#include <fstream>

using namespace std;

void solve() {
    int a, b, k;
    scanf("%d %d %d", &a, &b, &k);
    int ans = 0, i, j;
    for (i = 0; i < a; ++i) {
        for (j = 0; j < b; ++j) {
            if ((i & j) < k) ans++;
        }
    }
    printf("%d\n", ans);
}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T, t;
    scanf("%d", &T);
    for (t = 1; t <= T; ++t) {
        printf("Case #%d: ", t);
        solve();
    }
    return 0;
}