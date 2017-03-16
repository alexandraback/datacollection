#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int testnum) {
    int n, X0, Y0;
    cin >> n >> X0 >> Y0;
    int tx = (Y0 + X0) / 2;
    int ty = (Y0 - X0) / 2;
    X0 = tx;
    Y0 = ty;
    long long def_need_to_fall = 0;
    for (int layer = 0; layer < max(X0, Y0); ++layer) {
        def_need_to_fall += 1 + 4 * layer;
        if (def_need_to_fall > n) break;
    }
    double ans = 0;
    if (def_need_to_fall > n) ans = 0.0; else {
        n -= def_need_to_fall;
        int layer = max(X0, Y0);
        if (n >= 1 + 4 * layer) ans = 1.0; else {
            int pos = min(X0, Y0) + layer;
            // pos = 0 means that we need at least 1 diamond at this direction.
            if (pos == 2 * layer) ans = 0.0; else {
                cerr << n << " " << layer << " " << pos << endl;
                vector<double> probs;
                probs.push_back(1.0);
                for (int r = 0; r < n; ++r) {
                    vector<double> np;
                    np.push_back(probs[0] / 2.0);
                    for (int w = 1; w < (int)probs.size(); ++w) np.push_back((probs[w] + probs[w - 1]) / 2.0);
                    np.push_back(probs[probs.size() - 1] / 2.0);
                    probs = np;
                }
//                for (int r = 0; r < (int)probs.size(); ++r) cerr << probs[r] << " ";
//                cerr << endl;
                ans = 0.0;
                for (int i = 0; i < (int)probs.size(); ++i) { 
                    int w = i + max(0, n - i - 2 * layer);
//                    cerr << i << " " << n << " " << w << endl;
                    if (w > pos) ans += probs[i];
                }
            }
        }
    }
    cout << "Case #" << testnum << ": ";
    printf("%.15lf\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) solve(i);
    return 0;
}

