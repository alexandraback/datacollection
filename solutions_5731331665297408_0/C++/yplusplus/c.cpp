#include <iostream>
using namespace std;

const int N = 10;
string zip[N];
bool g[N][N];
int path[N], tail;
int n, m;

void solve() {
    int a[N];
    string ans_str(5 * n, '9');
    for (int i = 0; i < n; i++) a[i] = i + 1;
    do {
        tail = 0;
        path[tail++] = a[0];
        bool found = false;
        for (int i = 1; i < n; i++) {
            for (; tail; tail--) {
                if (g[path[tail - 1]][a[i]]) {
                    path[tail++] = a[i];
                    break;
                }
            }
            if (tail == 0) {
                found = true;
                break;
            }
        }
        if (!found) {
            string tmp_str;
            for (int i = 0; i < n; i++) {
                tmp_str += zip[a[i]];
            }
            ans_str = min(ans_str, tmp_str);
        }
    } while (next_permutation(a, a + n));
    cout << ans_str << endl;
}

int main() {
    freopen("C-small.in", "r", stdin);
    freopen("C-small.out", "w", stdout);
    int T, Case = 1;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        memset(g, 0, sizeof(g));
        for (int i = 1; i <= n; i++) cin >> zip[i];
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            g[a][b] = g[b][a] = 1;
        }
        cout << "Case #" << Case++ << ": ";
        solve();
    }
    return 0;
}

