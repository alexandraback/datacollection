#include <iostream>

using namespace std;

const int MAXN = 100;

int N, M, a[MAXN][MAXN];
int max_row[MAXN], max_col[MAXN];

void solve()
{
    for (int r = 0; r < N; ++r) {
        max_row[r] = a[r][0];
        for (int c = 1; c < M; ++c)
            if (a[r][c] > max_row[r]) max_row[r] = a[r][c];
    }

    for (int c = 0; c < M; ++c) {
        max_col[c] = a[0][c];
        for (int r = 1; r < N; ++r)
            if (a[r][c] > max_col[c]) max_col[c] = a[r][c];
    }

    for (int r = 0; r < N; ++r)
        for (int c = 0; c < M; ++c)
            if (a[r][c] < max_row[r] && a[r][c] < max_col[c]) {
                cout << "NO" << endl;
                return;
            }

    cout << "YES" << endl;
}

int main()
{
    int T; cin >> T;

    for (int t = 0; t < T; ++t) {
        cout << "Case #" << t+1 << ": ";

        cin >> N >> M;
        for (int r = 0; r < N; ++r)
            for (int c = 0; c < M; ++c) cin >> a[r][c];

        solve();
    }


    return 0;
}
