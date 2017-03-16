#include <iostream>
#include <cstdint>
using namespace std;

int main(void) {
    int t, k, c, s;
    cin >> t;
    int offset;
    uint64_t start;
    for (int i = 1; i <= t; ++i) {
        cin >> k >> c >> s;
        start = 2;
        offset = k - 3;
        cout << "Case #" << i << ":";
        if (s < k + 1 - c) {
            cout << " IMPOSSIBLE" << endl;
            continue;
        }
        if (1 == c) {
            for (int j = 1; j <= k; ++j) cout << " " << j;
            cout << endl;
            continue;
        }
        if (1 == k) {
            cout << " 1" << endl;
            continue;
        }
        for (int j = 2; j < c && offset >= 0; ++j) {
            start *= k;
            start -= offset;
            --offset;
        }
        do {
            cout << " " << start;
            ++start;
        } while (start % k != 1);
        cout << endl;
    }
    return 0;
}

