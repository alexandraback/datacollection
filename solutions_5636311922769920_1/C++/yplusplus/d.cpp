#include <iostream>
#include <vector>
using namespace std;

const int N = 111;
int K, C, S;
long long fac[N];

void solve() {
    if ((K + C - 1) / C > S) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    fac[0] = 1; for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * K;

    int X = 0;
    while (X < K) {
        long long p = 1;
        for (int i = 1; i <= C; i++) {
            p += fac[C - i] * X;
            X++;
            if (X == K || i == C) {
                cout << p << (X == K ? "\n" : " ");
                break;
            }
        }
    }
}

int main() {
    int T, Case = 1;
    cin >> T;
    while (T--) {
        cin >> K >> C >> S;
        cout << "Case #" << Case++ << ": ";
        solve();
    }
    return 0;
}
