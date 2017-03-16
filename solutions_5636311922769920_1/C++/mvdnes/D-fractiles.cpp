#include <iostream>
#include <algorithm>

using namespace std;

void doit() {
    long long K, C, S;
    cin >> K >> C >> S;
    long long needed = (K + C - 1) / C;
    if (needed > S) {
        cout << " IMPOSSIBLE" << endl;
        return;
    }

    long long next = 0;
    while (next < K) {
        long long base = 1;
        long long val = 0;
        for (long long j = 0; j < C && next < K; ++j) {
            val += base * next;
            next++;
            base *= K;
        }
        cout << " " << val+1;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ":";
        doit();
    }
}
