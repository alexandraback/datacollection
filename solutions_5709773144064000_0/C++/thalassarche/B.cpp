#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

void solve()
{
    long double c, f, x, t = 0, r = 2;
    cin >> c >> f >> x;
    
    const long double at = c / f;
    for (;;) {
        if (at < (x / (r + f))) {
            t += (c / r);
            r += f;
        } else {
            cout << setprecision(30) << (x / r) + t << endl;
            return;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
