#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve() {
    int C, D, V;
    cin >> C >> D >> V;
    vector<int> a(D);
    for (int i = 0; i < D; ++i)
        cin >> a[i];

    vector<bool> can(V + 1);
    can[0] = true;
    for (int i = 0; i < D; ++i)
        for (int j = V; j >= 0; --j) {
            if (!can[j])
                continue;
            for (int k = 1; k <= C; ++k) {
                int val = j + a[i] * k;
                if (val > V)
                    break;
                can[val] = true;
            }
        }

    int result = 0;
    while (true) {
        int i = 0;
        while (i <= V && can[i])
            ++i;
        if (i > V)
            break;
        ++result;
        for (int j = V; j >= 0; --j)
            if (can[j]) {
                for (int k = 1; k <= C; ++k) {
                    int val = j + i * k;
                    if (val > V)
                        break;
                    can[val] = true;
                }
            }
    }

    return result;
}

int main() {
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; ++t) {
        cout << "Case #" << t << ": " << solve() << '\n';
    }

    return 0;
}

