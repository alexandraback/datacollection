#include <algorithm>
#include <iostream>
#include <vector>

#include <cassert>

using namespace std;

void solve()
{
    long long a, b, k;
    cin >> a >> b >> k;
    int cnt = 0;
    for (int aa = 0; aa < a; ++aa) {
        for (int bb = 0; bb < b; ++bb) {
            if ((aa & bb) < k) ++cnt;
        }
    }
    cout << cnt << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    cout.flush();
    return 0;
}
