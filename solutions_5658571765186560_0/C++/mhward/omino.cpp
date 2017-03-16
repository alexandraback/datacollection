#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int x, r, c;

bool answer() {
    if (r < c) {
        int tmp = r;
        r = c;
        c = tmp;
    }
    if (x == 1)
        return true;
    if (x == 2)
        return (r % 2 == 0 || c % 2 == 0);
    if (x == 3)
        return (r > 1 && c % 3 == 0) || (c > 1 && r % 3 == 0);
    return (r == 4 && c == 4) || (r == 4 && c == 3);
}

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cin >> x >> r >> c;
        cout << "Case #" << tc << ": " << (answer() ? "GABRIEL" : "RICHARD")  << endl;
    }
}
