#include <algorithm>
#include <iostream>

using namespace std;

int solve (int e, int r, int n, int v[]) {
    if (n == 0)
        return 0;

    int best = 0;
    for (int i = 0; i <= e; ++i) {
        best = max(best, i * v[0] + solve(min(e, e + r - i), r, n - 1, v + 1));
    }

    return best;
}
       

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int e, r, n;
        cin >> e >> r >> n;
        int v[n];
        for (int j = 0; j < n; ++j) {
            cin >> v[j];
        }

        cout << "Case #" << i << ": " << solve(e, r, n, v) << endl;
    }
}
