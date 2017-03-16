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
    int cnt, i, i1, i2, j, k, p, res, s, t;
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    cin >> t;
    for (cnt = 1; cnt <= t; cnt++)
    {
        cin >> j; cin >> p; cin >> s; cin >> k;
        res = 0;

        if ((j == 1) && (p == 1) && (s == 1)) {
            res = 1;
            cout << "Case #" << cnt << ": " << res << endl;
            cout << "1 1 1" << endl;
        }

        if ((j == 1) && (p == 1) && (s == 2)) {
            res = 1;
            if (k >= 2) res = 2;
            cout << "Case #" << cnt << ": " << res << endl;
            cout << "1 1 1" << endl;
            if (k >= 2) {
                cout << "1 1 2" << endl;
            }
        }

        if ((j == 1) && (p == 1) && (s == 3)) {
            res = 1;
            if (k >= 2) res = 2;
            if (k >= 3) res = 3;
            cout << "Case #" << cnt << ": " << res << endl;
            cout << "1 1 1" << endl;
            if (k >= 2) {
                cout << "1 1 2" << endl;
            }
            if (k >= 3) {
                cout << "1 1 3" << endl;
            }
        }

        if ((j == 1) && (p == 2) && (s == 2)) {
            res = 2;
            if (k >= 2) res = 4;
            cout << "Case #" << cnt << ": " << res << endl;
            cout << "1 1 1" << endl;
            cout << "1 2 2" << endl;
            if (k >= 2) {
                cout << "1 1 2" << endl;
                cout << "1 2 1" << endl;
            }
        }

        if ((j == 2) && (p == 2) && (s == 2)) {
            res = 4;
            if (k >= 2) res = 8;
            cout << "Case #" << cnt << ": " << res << endl;
            cout << "1 1 1" << endl;
            cout << "2 2 1" << endl;
            cout << "1 2 2" << endl;
            cout << "2 1 2" << endl;
            if (k >= 2) {
                cout << "2 2 2" << endl;
                cout << "1 1 2" << endl;
                cout << "2 1 1" << endl;
                cout << "1 2 1" << endl;
            }
        }

        if ((j == 1) && (p == 2) && (s == 3)) {
            res = 2;
            if (k >= 2) res = 4;
            if (k >= 3) res = 6;
            cout << "Case #" << cnt << ": " << res << endl;
            cout << "1 1 1" << endl;
            cout << "1 2 2" << endl;
            if (k >= 2) {
                cout << "1 2 3" << endl;
                cout << "1 1 2" << endl;
            }
            if (k >= 3) {
                cout << "1 2 1" << endl;
                cout << "1 1 3" << endl;
            }
        }

        if ((j == 1) && (p == 3) && (s == 3)) {
            res = 3;
            if (k >= 2) res = 6;
            if (k >= 3) res = 9;
            cout << "Case #" << cnt << ": " << res << endl;
            cout << "1 1 1" << endl;
            cout << "1 2 2" << endl;
            cout << "1 3 3" << endl;
            if (k >= 2) {
                cout << "1 1 2" << endl;
                cout << "1 2 3" << endl;
                cout << "1 3 1" << endl;
            }
            if (k >= 3) {
                cout << "1 1 3" << endl;
                cout << "1 2 1" << endl;
                cout << "1 3 2" << endl;
            }
        }

        if ((j == 2) && (p == 2) && (s == 3)) {
            res = 4;
            if (k >= 2) res = 8;
            if (k >= 3) res = 12;
            cout << "Case #" << cnt << ": " << res << endl;
            cout << "1 1 1" << endl;
            cout << "2 2 2" << endl;
            cout << "1 2 3" << endl;
            cout << "2 1 3" << endl;
            if (k >= 2) {
                cout << "1 1 3" << endl;
                cout << "2 2 1" << endl;
                cout << "1 2 1" << endl;
                cout << "2 1 1" << endl;
            }
            if (k >= 3) {
                cout << "1 1 2" << endl;
                cout << "2 2 3" << endl;
                cout << "1 2 2" << endl;
                cout << "2 1 2" << endl;
            }
        }

        if ((j == 2) && (p == 3) && (s == 3)) {
            res = 6;
            if (k >= 2) res = 12;
            if (k >= 3) res = 18;
            cout << "Case #" << cnt << ": " << res << endl;
            cout << "1 1 1" << endl;
            cout << "1 2 2" << endl;
            cout << "1 3 3" << endl;
            cout << "2 1 2" << endl;
            cout << "2 2 3" << endl;
            cout << "2 3 1" << endl;
            if (k >= 2) {
                cout << "1 1 2" << endl;
                cout << "1 2 3" << endl;
                cout << "1 3 1" << endl;
                cout << "2 1 3" << endl;
                cout << "2 2 1" << endl;
                cout << "2 3 2" << endl;
            }
            if (k >= 3) {
                cout << "1 1 3" << endl;
                cout << "1 2 1" << endl;
                cout << "1 3 2" << endl;
                cout << "2 1 1" << endl;
                cout << "2 2 2" << endl;
                cout << "2 3 3" << endl;
            }
        }

        if ((j == 3) && (p == 3) && (s == 3)) {
            res = 9;
            if (k >= 2) res = 18;
            if (k >= 3) res = 27;
            cout << "Case #" << cnt << ": " << res << endl;
            cout << "1 1 1" << endl;
            cout << "1 2 2" << endl;
            cout << "1 3 3" << endl;
            cout << "2 1 2" << endl;
            cout << "2 2 3" << endl;
            cout << "2 3 1" << endl;
            cout << "3 1 3" << endl;
            cout << "3 2 1" << endl;
            cout << "3 3 2" << endl;
            if (k >= 2) {
                cout << "1 1 2" << endl;
                cout << "1 2 3" << endl;
                cout << "1 3 1" << endl;
                cout << "2 1 3" << endl;
                cout << "2 2 1" << endl;
                cout << "2 3 2" << endl;
                cout << "3 1 1" << endl;
                cout << "3 2 2" << endl;
                cout << "3 3 3" << endl;
            }
            if (k >= 3) {
                cout << "1 1 3" << endl;
                cout << "1 2 1" << endl;
                cout << "1 3 2" << endl;
                cout << "2 1 1" << endl;
                cout << "2 2 2" << endl;
                cout << "2 3 3" << endl;
                cout << "3 1 2" << endl;
                cout << "3 2 3" << endl;
                cout << "3 3 1" << endl;
            }
        }
    }

    return 0;
}
