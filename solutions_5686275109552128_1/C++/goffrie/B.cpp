#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void tc() {
    int D; cin >> D;
    vector<int> val(D); for (int i = 0; i < D; ++i) cin >> val[i];
    unsigned best = -1;
    for (int k = 1; k <= 1000; ++k) {
        unsigned v = k;
        for (int i = 0; i < D; ++i) {
            v += (val[i]-1) / k;
        }
        best = min(best, v);
    }
    static int cas = 1;
    cout << "Case #" << cas++ << ": " << best << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) tc();
}
