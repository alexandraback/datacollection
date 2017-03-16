#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        int r, c, m;
        cin >> r >> c >> m;

        cout << "Case #" << tc << ":\n";

        int d = r*c - m;
        bool specialCase = d == 1 || r == 1 || c == 1;
        bool fillCorner = false;

        int cl = -1, ch = -1, crem = -1;

        for (int l = 2; l <= r; l++) {
            int h = d / l;
            int rem = d % l;

            if (h >= 2 && h <= c && (h + (rem > 0) <= c)) {
                if (rem != 1) {
                    cl = l;
                    ch = h;
                    crem = rem;
                    break;
                } else if (h >= 3 && l >= 3) {
                    cl = l;
                    ch = h;
                    crem = rem + 1;
                    fillCorner = true;
                    break;
                }
            }
        }

        if (!specialCase && cl == -1)
            cout << "Impossible\n";
        else if (r == 1 || c == 1) {
            cout << "c" << (r == 1 ? "" : "\n");

            for (int i = 1; i < max(c, r); i++)
                cout << (i < d ? '.' : '*') << (r == 1 ? "" : "\n");

            if (r == 1)
                cout << '\n';
        } else {
            if (specialCase)
                cl = crem = -1;

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (i == 0 && j == 0)
                        cout << "c";
                    else if (i == cl - 1 && j == ch - 1 && fillCorner)
                        cout << "*";
                    else if ((i < cl) && (j < ch || (j == ch && i < crem)))
                        cout << ".";
                    else
                        cout << "*";
                }

                cout << '\n';
            }
        }
    }

    return 0;
}
