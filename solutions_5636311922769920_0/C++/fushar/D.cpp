#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll K, C, S;
int main() {
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> K >> C >> S;
        cout << "Case #" << tc << ":";

        if (K > S * C) {
            cout << " IMPOSSIBLE" << endl;
            continue;
        }

        for (int i = 0; i < (K+C-1)/C; i++) {
            ll id = 0;
            for (int j = 0; j < C; j++) {
                id = id * K + (min(K, i*C+j) % K);
            }
            cout << " " << (id+1);
        }
        cout << endl;
    }
}
