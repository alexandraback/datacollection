#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

typedef long long ll;

int main() {
    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        // Each "L" represent a set cover that all its along index
        // are "L".
        // Since L expands to its original pattern and G expands to G.
        int K, C, S;
        cin >> K >> C >> S;
        if (S * C < K) {
            cout << "Case #" << (i + 1) << ": IMPOSSIBLE" << endl;
            continue;
        }
        vector<ll> res;
        int st = 0;
        while (st < K) {
            // Check the cover of 0,...,C - 1;
            ll temp = 0;
            for (int j = st; j < st + C && j < K; j++) {
                temp = temp * K + j;
            }
            res.push_back(temp + 1);
            st += C;
        }

        cout << "Case #" << (i + 1) << ": ";
        cout << res[0];
        for (int j = 1; j < res.size();j++) {
            cout << " " << res[j];
        }
        cout << endl;
    }    
    return 0;
}
