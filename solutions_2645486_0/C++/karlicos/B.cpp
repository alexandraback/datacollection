#include <iostream>
#include <vector>
using namespace std;

long long solve(int e, int r, const vector<int> &v, int cure, int pos) {
    if (pos == v.size()) {
        return 0;
    }
    long long maxe = -1;
    for (int i = 0; i <= cure; i++) {
        maxe = max(maxe, solve(e, r, v, min(e, cure - i + r), pos + 1) + v[pos] * i);
    }
    return maxe;
}

int main() {
    int t;
    cin >> t;
    for (int test = 0; test < t; test++) {
        int e, r, n;
        cin >> e >> r >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        long long ans = solve(e, r, v, e, 0);
        cout << "Case #" << test + 1 << ": " << ans << endl;
    }
    return 0;
}