#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int f[N];
int maxIn[N];
int mark[N];

int main() {
    ios::sync_with_stdio(false);
    int nt; cin >> nt;
    for (int tc = 1; tc <= nt; ++tc) {
        int n; cin >> n;
        for (int i = 0; i < n; ++i) cin >> f[i], --f[i];
        memset(maxIn, 0, sizeof maxIn);
        int res = 0;
        for (int start = 0; start < n; ++start) {
            memset(mark, -1, sizeof mark);
            int time = 0;
            int u = start, last = -1;
            while (mark[u] == -1) {
                assert(0 <= u && u < n);
                mark[u] = time++;
                if (f[u] != last) maxIn[u] = max(maxIn[u], time);
                last = u;
                u = f[u];
            }
            res = max(res, time - mark[u]);
        }
        int tmp = 0;
        for (int i = 0; i < n; ++i) if (f[f[i]] == i)
            tmp += maxIn[i] + maxIn[f[i]];
        assert(tmp % 2 == 0);
        cout << "Case #" << tc << ": " << max(res, tmp / 2) << '\n';
    }
    return 0;
}
