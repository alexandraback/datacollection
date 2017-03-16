
#include <iostream>
#include <string>

using namespace std;

// Notes:
// S_i = {positions of Ls after i-th split}
// S_{i+1} = {K*x+y for x in S_i, y in S_1}
// S_C = {all numbers with digits in S_1}
// Collection needs every digit to appear
// Feasible iff S*C >= K

void solve(int K, int C, int S) {
    if (S * C < K) {
        cout << " " << "IMPOSSIBLE" << endl;
        return;
    }

    int cnt = 0;
    while (S--) {
        long long num = 0;
        for (int i = 0; i < C; i++) {
            num = num * K + (cnt % K);
            cnt++;
        }
        cout << " " << num + 1;
        if (cnt >= K)
            break;
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int K, C, S;
        cin >> K >> C >> S;
        cout << "Case #" << t << ":";
        solve(K, C, S);
    }
}
