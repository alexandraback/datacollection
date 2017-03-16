#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

typedef __int128_t integer;

void solve()
{
    long long t_r, t_t;
    cin >> t_r >> t_t;
    integer r = t_r, t = t_t;
    integer l = 1, h = numeric_limits<int>::max();

    while (l + 1 != h) {
        integer c = (l + h) / 2;
        if (2 * r * c - c + 2 * c * c > t) {
            h = c;
        } else {
            l = c;
        }
    }
    cout << static_cast<long long>(l) << endl;
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
