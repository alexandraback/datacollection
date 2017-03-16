#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calcSpec(int P, int K) {
    int x = P / K + (P % K != 0);
    return x - 1;
}

int solve(int d, vector<int>& p) {
    sort(p.rbegin(), p.rend());
    int res = p[0];
    for (int K = 1; K <= p[0]; ++K) {
        int spec = 0;
        for (int j = 0; j < d; ++j) {
            spec += calcSpec(p[j], K);
        }
        res = min(res, spec + K);
    }
    return res;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int testId = 1; testId <= T; ++testId) {
        int d;
        cin >> d;
        vector<int> p(d);
        for (int j = 0; j < d; ++j)
            cin >> p[j];
        cout << "Case #" << testId << ": " << solve(d, p) << "\n";
    }
    return 0;
}
