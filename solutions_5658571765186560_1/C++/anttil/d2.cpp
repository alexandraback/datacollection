#include <iostream>

using namespace std;

int t;
int x, r, c;

void solve(int x) {
    cout << "Case #" << x << ": ";
    cin >> x >> r >> c;
    if ((r*c)%x != 0) {
        cout << "RICHARD\n";
        return;
    }
    if (x == 1 || x == 2) {
        cout << "GABRIEL\n";
    }
    if (x == 3) {
        if (r == 1 || c == 1) cout << "RICHARD\n";
        else cout << "GABRIEL\n";
    }
    if (x == 4) {
        if (r <= 3 && c <= 3) cout << "RICHARD\n";
        else if (r <= 2 || c <= 2) cout << "RICHARD\n";
        else cout << "GABRIEL\n";
    }
    if (x == 5) {
        if (r <= 4 && c <= 4) cout << "RICHARD\n";
        else if (r <= 3 || c <= 3) cout << "RICHARD\n";
        else cout << "GABRIEL\n";
    }
    if (x == 6) {
        if (r <= 5 && c <= 5) cout << "RICHARD\n";
        else if (r <= 3 || c <= 3) cout << "RICHARD\n";
        else cout << "GABRIEL\n";
    }
    if (x >= 7) {
        cout << "RICHARD\n";
    }
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}
