#include <iostream>

using namespace std;

int t, n, v;
int s[2501];

int main() {
    cin >> t;
    for (int x = 0; x ++< t;) {
        for (int h = 0; h <= 2500; ++h) s[h] = 0;
        cin >> n;
        for (int i = 0; i < n * (2 * n - 1); ++i) cin >> v, ++s[v];
        cout << "Case #" << x << ": ";
        for (int h = 0; h <= 2500; ++h) if (s[h] % 2) cout << h << ' ';
        cout << '\n';
    }
}

