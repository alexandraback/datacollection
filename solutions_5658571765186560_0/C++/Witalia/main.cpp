#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;

const string player1 = "RICHARD";
const string player2 = "GABRIEL";

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        cout << "Case #" << (t + 1) << ": ";

        int x, r, c;
        cin >> x >> r >> c;
        if (r > c) swap(r, c);
        if (x == 1) {
            cout << player2 << endl;
        } else if (x == 2) {
            cout << ((r * c) % 2 == 0 ? player2 : player1) << endl;
        } else if (x == 3) {
            if (r > 1 && c == 3 || r == 3 && c == 4)
                cout << player2 << endl;
            else cout << player1 << endl;
        } else {
            if (c == 4 && r > 2)
                cout << player2 << endl;
            else cout << player1 << endl;
        }
    }

    return 0;
}
