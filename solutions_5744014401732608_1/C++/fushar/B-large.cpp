#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int N;
ll M;
ll cnt[50];

int G[50][50];

int main() {
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N >> M;
        memset(G, 0, sizeof G);

        cnt[0] = cnt[1] = 1;
        G[1][0] = 1;
        for (int i = 2; i < N-1; i++) {
            cnt[i] = 2 * cnt[i-1];
            for (int j = i-1; j >= 0; j--) {
                G[j][i] = 1;
            }
        }

        for (int i = N-2; i >= 0; i--) {
            if (M >= cnt[i]) {
                M -= cnt[i];
                G[N-1][i] = 1;
            }
        }

        cout << "Case #" << tc << ": ";
        if (M) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << "POSSIBLE" << endl;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    cout << G[N-i-1][N-j-1];
                }
                cout << endl;
            }
        }
    }
}
