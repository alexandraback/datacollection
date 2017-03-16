#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

long long make_number(int K, int low, int high) {
    assert(high - low <= K);
    long long res = 0;
    for (int i = low; i < high; i++)
        res = res * K + i;
    return res;
}

int main() {
    int T, K, C, S;
    cin >> T;
    for (int Case = 1; Case <= T; Case++) {
        cin >> K >> C >> S;
        cout << "Case #" << Case << ":";
        if (K <= C * S) {
            vector<long long> res;
            for (int i = 0; i < K; i += C)
                res.push_back(make_number(K, i, min(i + C, K)));
            sort(begin(res), end(res));
            for(auto v: res)
                cout << " " << v + 1;
            cout << endl;
        } else {
            cout << " IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
