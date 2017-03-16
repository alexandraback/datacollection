#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < n; i++)
#define what_is(x) cerr << #x << ": " << x << endl;

#define file "f"

using namespace std;

int T;
long long B, M;

int a[50][50];

void fill_a(void) {
    forn(i, B) {
        for (int j = 0; j <= i; j++)
            a[i][j] = 0;
        for (int j = i + 1; j < B; j++)
            a[i][j] = 1;
    }

    forn(i, B) {
        a[B - 1][i] = 0;
    }
}

void print_sol(void) {
    cout << "POSSIBLE\n";
    forn(i, B) {
        forn(j, B) {
            cout << a[i][j];
        }
        cout << "\n";
    }
}

void solve(void) {
    static int test_case = 0;
    cout << "Case #" << ++test_case << ": ";

    if (M > (1L << (B - 2)))  {
        cout << "IMPOSSIBLE\n";
        return;
    }

    if (M == (1L << (B - 2))) {
        print_sol();
        return;
    }

    forn(i, B) {
        a[0][i] = 0;
    }

    for (int i = 1; i < B - 1; i++) {
        if (M & (1L << (B - i - 2)))
            a[0][i] = 1;
    }
    
    print_sol();
}

int main(void) {
    freopen(file".in", "r", stdin);
    freopen(file".out", "w", stdout);

    ios_base::sync_with_stdio(false);


    cin >> T;
    forn(t, T) {
        cin >> B >> M;
        fill_a();
        solve();
    }
}

