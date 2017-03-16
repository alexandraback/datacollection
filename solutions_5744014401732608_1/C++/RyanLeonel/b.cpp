#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
    long long b, b2, b22, cnt, i, j, m, t, x, y;
    vector <vector <bool> > ss;
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    cin >> t;
    for (cnt = 1; cnt <= t; cnt++)
    {
        cin >> b; cin >> m;

        b2 = 1; for (i = 0; i < b - 2; i++) b2 *= 2;
        ss.resize(b);
        for (i = 0; i < b; i++) {
            ss[i].resize(b);
            for (j = 0; j < b; j++) ss[i][j] = false;
        }

        if (m > b2) cout << "Case #" << cnt << ": IMPOSSIBLE" << endl;
        else {
            cout << "Case #" << cnt << ": POSSIBLE" << endl;
            for (i = 0; i < b; i++) {
                for (j = i + 1; j < b; j++) {
                    ss[i][j] = true;
                }
            }
            x = b2 - m;
            for (i = 0; i < b - 2; i++) {
                if (x % 2) ss[0][(b - 2) - i] = false;
                x /= 2;
            }
            for (i = 0; i < b; i++) {
                for (j = 0; j < b; j++) cout << (ss[i][j] ? "1" : "0");
                cout << endl;
            }
        }
    }
    return 0;
}
