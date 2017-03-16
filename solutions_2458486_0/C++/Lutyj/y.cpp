#include <algorithm>
#include <iostream>

using namespace std;

const int MAXN = 20, MAXK = 40;

int start[MAXK], K, N, what[MAXN];
int good[1<<MAXN], nkeys[201], G[MAXN][MAXK+1];

void solve()
{
    fill(good, good + (1<<N), -1);
    good[0] = 0;

    for (int j = 0; j < K; ++j) ++nkeys[start[j]];

    for (int mask = 1; mask < (1<<N); ++mask) {
        for (int i = 0; i < N; ++i)
            if (!(mask & (1<<i))) {
                --nkeys[what[i]];
                for (int j = 1; j <= G[i][0]; ++j) ++nkeys[G[i][j]];
            }

        for (int i = 0; i < N; ++i)
            if (mask & (1<<i)) {
                if (nkeys[what[i]] == 0) continue;
                if (good[mask ^ (1<<i)] != -1) { good[mask] = i; break; }
            }

        for (int i = 0; i < N; ++i)
            if (!(mask & (1<<i))) {
                ++nkeys[what[i]];
                for (int j = 1; j <= G[i][0]; ++j) --nkeys[G[i][j]];
            }
    }

    for (int j = 0; j < K; ++j) --nkeys[start[j]];

    if (good[(1<<N)-1] == -1) { cout << " IMPOSSIBLE" << endl; return; }

    int cur = (1<<N)-1;

    while (cur != 0) {
        cout << " " << good[cur]+1;
        cur ^= (1<<good[cur]);
    }

    cout << endl;
}

int main()
{
    int T; cin >> T;
    for (int t = 0; t < T; ++t) {
        cin >> K >> N;
        for (int j = 0; j < K; ++j) cin >> start[j];

        for (int i = 0; i < N; ++i) {
            cin >> what[i] >> G[i][0];
            for (int j = 1; j <= G[i][0]; ++j) cin >> G[i][j];
        }

        cout << "Case #" << t+1 << ":";
        solve();
    }


    return 0;
}
