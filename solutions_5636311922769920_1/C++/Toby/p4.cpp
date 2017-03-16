#include <cstdint>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

int64_t K, C, S;

void solve() {
    cin >> K >> C >> S;

    if (S * C < K) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    int64_t num = 0;
    for (int64_t i = 0; i < K; i++) {
        if (i > 0 && i % C == 0) {
            cout << (num + 1) << ' ';
            num = 0;
        }
        num = num * K + i;
    }
    cout << (num + 1) << endl;
}

int main() {
    int T;
    cin >> T;
    for (int testcase = 1; testcase <= T; testcase++) {
        cout << "Case #" << testcase << ": ";
        solve();
    }
    return 0;
}
