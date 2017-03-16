#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory>
#include <cstring>
#include <string.h>
using namespace std;
const int maxn = 1011;
int g[maxn][20];
int a[maxn], f[maxn], b[maxn], line[maxn * 2];
int test, n, ll, rr;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> test;
    for (int t = 1; t <= test; t++) {
        cin >> n; memset(a, 0, sizeof(a)); memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &g[i][0]);
            for (int j = 1; j <= g[i][0]; j++) {
                scanf("%d", &g[i][j]); a[g[i][j]]++;
            }
        }
        for (int i = 1; i <= n; i++) b[i] = a[i];
        bool ans = false;
        for (int ss = 1; ss <= n; ss++)
            if (b[ss] == 0) {
                for (int i = 1; i <= n; i++) a[i] = b[i];
                memset(f, 0, sizeof(f));
                f[ss] = 1;
                ll = 0; rr = 1; line[1] = ss;
                while (ll < rr) {
                    ll++;
                    int i = line[ll];
                   // cout << i << endl;

                        for (int j = 1; j <= g[i][0]; j++) {
                            if (f[g[i][j]] == 0) {
                                rr++; f[g[i][j]] = 1; line[rr] = g[i][j];
                            } else {ans = true; break;}
                        }

                    if (ans) break;
                }
            }
        cout << "Case #" << t << ": ";
        if (ans) cout << "Yes"; else cout << "No";
        cout << endl;
    }
    return 0;
}
