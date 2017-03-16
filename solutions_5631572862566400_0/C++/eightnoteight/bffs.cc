#include <bits/stdc++.h>
#ifdef __mr__
    #include "prettyprint.hpp"
#else
    #define endl                    '\n'
#endif
#define len(x)                      (uint)(x).size()
#define int                         int32_t
#define uint                        uint32_t
#define ulong                       uint64_t
#define long                        int64_t
#define t_max(x)                    numeric_limits<x>::max()
#define t_min(x)                    numeric_limits<x>::min()
using namespace std;
const ulong mod = 1000000007ul;

int main(int argc, char const *argv[]) {
    #ifndef __mr__
        ios::sync_with_stdio(0);cin.tie(0);
    #endif
    int testcases;
    cin >> testcases;
    for (int t = 1; t <= testcases; ++t) {
        int n;
        cin >> n;
        vector<int> bffs(n);
        for (int i = 0; i < n; ++i) {
            cin >> bffs[i];
            bffs[i]--;
        }
        int c = 3;
        int ans = 0;
        while (c < (1 << n)) {
            vector<int> perm;
            for (int i = 0; i < n; ++i) {
                if (c & (1 << i)) {
                    perm.push_back(i);
                }
            }
            c++;
            if (perm.size() < 2)
                continue;
            do {
                if (bffs[perm[0]] != perm[1] && bffs[perm[0]] != perm.back()) {
                    continue;
                }
                if (bffs[perm.back()] != perm[perm.size() - 2] && bffs[perm.back()] != perm[0]) {
                    continue;
                }
                int cfl = 0;
                for (int i = 1; i < perm.size() - 1; ++i) {
                    if (bffs[perm[i]] != perm[i - 1] && bffs[perm[i]] != perm[i + 1]) {
                        cfl = 1;
                        break;
                    }
                }
                if (cfl)
                    continue;
                ans = max(ans, (int)perm.size());
                // cout << perm << endl << flush;
            } while(next_permutation(perm.begin(), perm.end()));
        }
        cout << "Case #" << t << ": " << ans << endl << flush;
    }
    return 0;
}
