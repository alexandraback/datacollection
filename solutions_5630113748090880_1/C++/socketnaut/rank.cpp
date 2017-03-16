#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        map<int, int> app;

        int N;
        cin >> N;

        for (int r = 0; r < 2 * N - 1; r++) {
            int val;
            for (int c = 0; c < N; c++) {
                cin >> val;
                app[val]++;
            }

        }

        cout << "Case #" << tc << ":";

        for (auto p : app) {
            if (p.second & 1)
                cout << " " << p.first;
        }

        cout << "\n";
    }

    return 0;
}

