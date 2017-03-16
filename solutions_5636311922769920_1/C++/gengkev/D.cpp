#include <iostream>
#include <vector>
using namespace std;

#define ll long long

vector<ll> solve(int K, int C, int S) {
    vector<ll> out;

    int Sn = (K + C-1) / C; // S needed = ceil(K/C)
    if (S < Sn) {
        return out;
    }

    int nextPos = 0;
    for (int i = 0; i < Sn; i++) {
        ll val = 0;
        for (int j = 0; j < C && nextPos < K; j++) {
            val = K * val + nextPos;
            nextPos++;
        }
        out.push_back(val+1LL);
    }
    return out;
}

int main() {
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        int K, C, S; cin >> K >> C >> S;
        vector<ll> res = solve(K, C, S);

        cout << "Case #" << i << ":";
        if (res.empty()) {
            cout << " IMPOSSIBLE" << endl;
        } else {
            for (ll num : res) {
                cout << " " << num;
            }
            cout << endl;
        }
    }
    return 0;
}
