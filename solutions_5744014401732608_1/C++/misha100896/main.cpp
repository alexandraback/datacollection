#include <bits/stdc++.h>

using namespace std;

int a[50][50];
long long p[55];


int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;

    p[0] = 1;
    for (int i = 1; i < 55; ++i)
        p[i] = p[i - 1] * 2;

    for (int x = 0;  x < t; ++x) {
        cout << "Case #" << x + 1 << ": ";
        long long n, m;
        cin >> n >> m;

        if (m > p[n - 2]) {
            cout << "IMPOSSIBLE\n";
            continue;
        }
        cout << "POSSIBLE\n";

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                a[i][j] = 0;

        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n - 1; ++j)
                a[i][j] = 1;
        }
        for (int i = n - 2; i >= 1; --i) {
            if (p[i - 1] <= m) {
                m -= p[i - 1];
                a[i][n - 1] = 1;
            }
        }
        if (m != 0)
            a[0][n - 1] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                cout << a[i][j];
            cout << '\n';
        }
    }
    return 0;
}
