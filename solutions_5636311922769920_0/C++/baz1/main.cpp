#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <string>
#include <random>
#include <chrono>

#include <gmpxx.h>

using namespace std;

typedef unsigned long long mint;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T;) {
        mint K, C, S;
        cin >> K >> C >> S;
        if (S < ((K + C - 1) / C)) {
            cout << "Case #" << (++i) << ": IMPOSSIBLE" << endl;
            continue;
        }
        cout << "Case #" << (++i) << ":";
        mint *p = new mint[C];
        p[0] = 1;
        for (int i = 1; i < C; ++i)
            p[i] = K * p[i - 1];
        for (int i = 0; i < K; i += C) {
            int max_j = C;
            if (i + max_j > K)
                max_j = K - i;
            mint current = 0;
            for (int j = 0; j < max_j; ++j)
                current += p[j] * (i + j);
            cout << " " << (current + 1);
        }
        delete[] p;
        cout << endl;
    }
    return 0;
}
