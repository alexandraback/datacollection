
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#define MAXN 1000

using namespace std;

int n;
int f[MAXN];

int solve() {
    for (int k = n; k > 1; k--) {
        vector <int> ord(n);
        for (int i = 0; i < n; i++)
            ord[i] = i;
        do {
            bool valid = true;
            for (int i = 0; i < k; i++) {
                int i0 = ord[i];
                int i1 = ord[(i + 1) % k];
                int i2 = ord[(i - 1 + k) % k];
                if (f[i0] != i1 && f[i0] != i2) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                return k;
        } while (next_permutation(ord.begin(), ord.end()));
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> f[i];
            f[i]--;
        }
        cout << "Case #" << t << ": " << solve() << endl;
    }
}
