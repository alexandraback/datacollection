#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int ii = 1; ii <= t; ii++) {
        int n;
        cin >> n;
        vector<int> f;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            f.push_back(x - 1);
        }
        vector<int> ringlen(n), pathlen(n), joinroot(n);
        vector<int> maxdep(n);
        for (int i = 0; i < n; i++) {
            vector<int> acc(n);
            fill(acc.begin(), acc.end(), -1);
            int p = i;
            int c = 0;
            while (acc[p] == -1) {
                acc[p] = c;
                c++;
                p = f[p];
            }
            ringlen[i] = c - acc[p];
            pathlen[i] = c;
            joinroot[i] = p;
            if (c - 1 > maxdep[p]) maxdep[p] = acc[p];
        }
        // first, largest ring
        int maxring = 0;
        for (int i = 0; i < n; i++) {
            if (ringlen[i] > maxring) {
                maxring = ringlen[i];
            }
        }
        // second, ring of size 2
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (f[f[i]] != i) continue;
            res += maxdep[i] + 1;
        }
        if (maxring > res) res = maxring;
        cout << "Case #" << ii << ": " << res << endl;
    }
    return 0;
}
