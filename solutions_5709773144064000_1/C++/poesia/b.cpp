#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

int main() {
    int t;

    cin >> t;

    cout.precision(7);
    cout.setf(ios::fixed);

    for (int tc = 1; tc <= t; tc++) {
        double c, f, x;
        cin >> c >> f >> x;

        double d = 0, t = x/2, ans = t;

        for (int i = 1; i <= x; i++) {
            d += c/(2 + f * (i-1));
            t = d + x / (2 + i*f);
            ans = min(ans, t);
        }

        cout << "Case #" << tc << ": " << ans << '\n';
    }

    return 0;
}
