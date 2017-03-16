#include <iostream>

using namespace std;

typedef long long ll;

int t;
ll b, m;
bool c[50][50];

int main() {
    cin >> t;
    for (int C = 0; C ++< t;) {
        cin >> b >> m;
        ll mx = 1 << (b - 2);
        cout << "Case #" << C << ": ";
        if (mx < m) cout << "IMPOSSIBLE\n";
        else {
            cout << "POSSIBLE\n";
            for (int i = b; i --> 0;) for (int j = b; j --> 0;) c[i][j] = i < j;
            for (ll i = 1; mx > m; ++i) if (mx - (1 << (b - 2 - i)) >= m) mx -= 1 << (b - 2 - i), c[0][i] = 0;
            for (int i = 0; i < b; ++i) {
                for (int j = 0; j < b; ++j) cout << c[i][j];
                cout << '\n';
            }
        }
    }
}

