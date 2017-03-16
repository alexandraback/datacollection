#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; t++) {
        cout << "Case #" << t << ": ";
        int x;
        int r;
        int c;
        cin >> x >> r >> c;
        if (r > c) {
            swap(r, c);
        }
        bool first_win = false;
        for (int k0 = 1; k0 <= x; k0++) {
            int k1 = x + 1 - k0;
            if (max(k0, k1) > max(r, c)) {
                first_win = true;
            }
            if (min(k0, k1) > min(r, c)) {
                first_win = true;
            }
        }
        if ((r * c) % x != 0) {
            first_win = true;
        }
        if (first_win) {
            cout << "RICHARD\n";
            continue;
        }
        if (x == 1) {
            cout << "GABRIEL\n";
            continue;
        }
        if (x == 2) {
            cout << "GABRIEL\n";
            continue;
        }
        if (x == 3) {
            cout << "GABRIEL\n";
            continue;
        }
        if (x == 4) {
            cout << (r == 2 ? "RICHARD" : "GABRIEL") << "\n";
            continue;
        }
        if (x == 5) {
            cout << "GABRIEL\n";
            continue;
        }
        if (x == 6) {
            cout << (r == 3 ? "RICHARD" : "GABRIEL") << "\n";
            continue;
        }
        if (x >= 7) {
            cout << "RICHARD\n";
            continue;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
