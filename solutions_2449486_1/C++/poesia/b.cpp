#include <iostream>

using namespace std;

int h[100][100], mx[200];

int main() {
    int t;
    cin >> t;

    for(int tc = 1; tc <= t; tc++) {

        int n, m;
        cin >> n >> m;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                cin >> h[i][j];
                mx[i] = mx[n+j] = -1;
            }

        for(int j = 0; j < m; j++)
            for(int i = 0; i < n; i++) {
                mx[i] = max(mx[i], h[i][j]);
                mx[n+j] = max(mx[n+j], h[i][j]);
            }

        bool all = true;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                all = all && (h[i][j] == mx[i] || h[i][j] == mx[n+j]);

        cout << "Case #" << tc << ": " << (all ? "YES" : "NO") << '\n';
    }

    return 0;
}
