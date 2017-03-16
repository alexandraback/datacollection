#include <bits/stdc++.h>
using namespace std;

int main() {
    assert(freopen("A-large-0.in", "r", stdin));
    assert(freopen("A-large-0.out", "w", stdout));
    int numTests; cin >> numTests;
    for (int test = 0; test < numTests; ++test) {
        int r; cin >> r;
        int c; cin >> c;
        int w; cin >> w;
        cout << "Case #" << test + 1 << ": " << (c / w) * r + w - 1 + (c % w != 0 ? 1 : 0) << '\n';
    }
    return 0;
}
