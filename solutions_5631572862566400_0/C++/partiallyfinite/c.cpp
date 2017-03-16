#include <iostream>
#include <algorithm>

using namespace std;

int t, n, v[10], f[10];

int main() {
    cin >> t;
    for (int x = 0; x ++< t;) {
        cin >> n;
        int m = 0;
        for (int i = 0; i < n; ++i) cin >> f[i], --f[i], v[i] = i;
        do {
            for (int k = n; k >= 2; --k) {
                for (int j = 0; j < k; ++j) if (v[(j-1+k)%k] != f[v[j]] && v[(j+1)%k] != f[v[j]]) goto no;
                m = max(m, k);
                break;
no:;
            }
        } while (next_permutation(v, v + n));
        cout << "Case #" << x << ": " << m << '\n';
    }
}

