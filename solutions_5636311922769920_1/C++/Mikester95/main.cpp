#include <iostream>
#include <vector>
#include <fstream>
#include <cstdio>

using namespace std;

void solve() {
    long long k, c, s;
    cin >> k >> c >> s;

    if (s*c < k) {
        cout << "IMPOSSIBLE";
        return;
    }

    long long current = 0;
    for (int i = 0; i < k; ++i) {
        current = current * k + i;
        if (i % c == c-1 || i == k-1) {
            cout << current + 1 << " ";
            current = 0;
        }
    }
}

int main()
{
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int test, n, k;
    cin >> test;
    for (int k = 1; k <= test; ++k) {
        cout << "Case #" << k << ": ";
        solve();
        cout << "\n";
    }
}
