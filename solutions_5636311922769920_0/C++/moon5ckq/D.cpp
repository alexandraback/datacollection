/*
 * D.cpp
 * Copyright (C) 2016 mlckq <moon5ckq@gmail.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cout << "Case #" << i << ":";
        int k, c, s;
        cin >> k >> c >> s;
        if (c * s < k) cout << " IMPOSSIBLE\n";
        else {
            for (int j = 1; j <= k; j += c) {
                long long res = j;
                for (int x = 1; x < c; ++x) {
                    int next = j + x;
                    if (next > k) next = 1;
                    res = (res - 1) * k + next;
                }
                cout << ' ' << res;
            }
            cout << endl;
        }
    }

    return 0;
}
