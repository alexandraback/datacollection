#include <bits/stdc++.h>

using namespace std;

#define ll long long

int D, P[1005];
int main() {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small.out", "w", stdout);
    int T;
    cin>>T;
    for (int cc = 1; cc <= T; cc++) {
        cin>>D;
        int max_p = 0;
        for (int i = 1; i <= D; i++) {
            cin>>P[i];
            max_p = max(max_p, P[i]);
        }

        int res = 1 << 30;
        for (int i = 1; i <= max_p; i++) {
            int idle = 0;
            for (int j = 1; j <= D; j++) {
                int num_moves = (P[j] - 1) / i;
                idle += num_moves;
            }
            res = min(res, idle + i);
        }

        printf("Case #%d: %d\n", cc, res);
    }
    return 0;
}
