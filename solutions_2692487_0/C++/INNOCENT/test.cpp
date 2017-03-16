#include <iostream>
#include <algorithm>

#define rep(i, s, t) for (int i = s; i <= t; i++)

using namespace std;

#define N 1000

int a[N];

int main() {
    int T;
    cin >> T;
    rep (ca, 1, T) {
        int A, n;
        cin >> A >> n;
        rep (i, 0, n-1) {
            cin >> a[i];
        }
        sort(a, a + n);
        int ans = n;
        int now = A;
        int nowc = 0;
        if (now > 1) {
            rep (i, 0, n-1) {
                ans = min(ans, nowc + n - i);
                while (now <= a[i]) {
                    now = 2 * now - 1;
                    nowc++;
                }
                now += a[i];
            }
            ans = min(ans, nowc);
        }
        cout << "Case #" << ca << ": " << ans << "\n";
    }
    return 0;
}
