#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
typedef long long ll;
typedef long double ld;
using namespace std;
ll a[55][55];
bool f[55];
ll cnt, n, way, nt;

void go(int x) {
    if (x == n - 1) {
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++)
        if ((f[i] == false) && (a[x][i] == 1)) {
            f[i] = true;
            go(i);
            f[i] = false;
        }
}

int main() {
    freopen("B.in", "r", stdin);
    freopen("B.ou", "w", stdout);
    cin >> nt;
    for (int kk = 1; kk <= nt; kk++) {
        cout << "Case #" << kk << ": ";
        cin >> n >> way;
        ll sz = n * n - n;
        bool pos = false;

        for (ll s = 0; s < (1ll << sz); s++) {
        int k = 0;

        for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        if (i != j) {
            a[i][j] = ((s >> k) & 1);
            k++;
        }

        for (int i = 0; i < n; i++)
            a[n - 1][i] = 0;

        memset(f, false, sizeof(f));
        f[0] = true;
        cnt = 0;

        go(0);

        if (cnt == way) {
            cout << "POSSIBLE\n";
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++)
                    cout << a[i][j] << " ";
                cout << "\n";
            }
            pos = true;
            break;
        }
        }
        if (!pos) cout << "IMPOSSIBLE\n";
    }

    /**/return 0;
}

