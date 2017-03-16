#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <random>
#include <cstdio>
#include <cstring>
using namespace std;

void solve()
{
    int k, c, s;
    cin >> k >> c >> s;

    int mins = (k + c - 1) / c;
    if (mins > s) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    for (int i = 0; i < mins; i++) {
        if (i != 0) cout << " ";
        int64_t cur = 0;
        for (int j = 0; j < c; j++) {
            int t = (i * c + j) % k;
            cur = cur * k + t;
        }
        cout << cur + 1;
    }

    cout << endl;
}

int main()
{
    int cases; cin >> cases;
    for (int cn = 1; cn <= cases; cn++) {
        cout << "Case #" << cn << ": ";
        solve();
    }
    return 0;
}
