#include <bits/stdc++.h>
using namespace std;

int runTest() {
    int c; cin >> c;
    int d; cin >> d;
    int v; cin >> v;
    vector<bool> possible (v + 1);
    possible[0] = true;
    auto update = [&] (int value) {
        for (int i = v; i >= value; --i) {
            possible[i] = possible[i] || possible[i - value];
        }
    };
    for (int i = 0; i < d; ++i) {
        int value; cin >> value;
        update(value);
    }
    int result = 0;
    for (int x = 1; x <= v; ++x) if (!possible[x]) update(x), ++result;
    return result;
}

int main() {
    assert(freopen("C-small-0.in", "r", stdin));
    assert(freopen("C-small-0.out", "w", stdout));
    ios::sync_with_stdio(false);
    int numTests; cin >> numTests;
    for (int test = 0; test < numTests; ++test) {
        cout << "Case #" << test + 1 << ": " << runTest() << '\n';
    }
    return 0;
}
