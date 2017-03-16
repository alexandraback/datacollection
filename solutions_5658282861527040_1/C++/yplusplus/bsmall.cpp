#include <iostream>
using namespace std;

int main() {
    freopen("b-big.in", "r", stdin);
    freopen("b-big.out", "w", stdout);
    int T, Case = 1;
    cin >> T;
    while (T--) {
        int a, b, k;
        cin >> a >> b >> k;
        int ans = 0;
        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                ans += (i & j) < k;
            }
        }
        cout << "Case #" << Case++ << ": " << ans << endl;
    }
    return 0;
}
