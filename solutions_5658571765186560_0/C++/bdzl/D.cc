#include <bits/stdc++.h>
using namespace std;

const string kFirstPlayerName = "RICHARD";
const string kSecondPlayerName = "GABRIEL";
const string kUnknown = "UNKNOWN";

int main()
{
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        cout << "Case #" << test << ": ";
        int x, r, c;
        cin >> x >> r >> c;
        if (r > c) {
            swap(r, c);
        }
        if (x > c || (r * c) % x != 0) {
            cout << kFirstPlayerName << endl;
            continue;
        }
        if (r == 1) {
            if (x <= 2) {
                cout << kSecondPlayerName << endl;
            } else {
                cout << kFirstPlayerName << endl;
            }
            continue;
        }
        if (r == 2) {
            if (x <= 3) {
                cout << kSecondPlayerName << endl;
                continue;
            }
            if (x >= 4) {
                cout << kFirstPlayerName << endl;
                continue;
            }
            continue;
        }
        if (x >= 7) {
            cout << kFirstPlayerName << endl;
            continue;
        }
        if (x <= 4) {
            cout << kSecondPlayerName << endl;
            continue;
        }
        cout << kUnknown << endl;
    }

    return 0;
}
