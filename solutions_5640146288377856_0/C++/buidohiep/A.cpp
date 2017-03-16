#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a, b) for(int i = a; i >= b; i--)
#define sz(x) (int)x.size()

typedef pair<int, int> II;
const int inf = 1e9;
const int Nmax = 100100;

int f[Nmax];

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("ans.out", "w", stdout);
    int test;
    cin >> test;
    FOR(t, 1, test){
        int r, c, w;
        cin >> r >> c >> w;
        f[w] = w;
        FOR(i, 0, w - 1) f[i] = 0;
        FOR(i, w + 1, c) {
            f[i] = inf;
            FOR(j, 1, i) {
                int hit = w + 1;
                int miss = f[j - 1] + f[i - j] + 1;
                if (j - 1 >= w || i - j >= w) f[i] = min(f[i], max(hit, miss));
                else {
                        f[i] = min(f[i], hit);
                }
            }
            //if (w == 1) cout << f[i] << endl;
        }
        printf("Case #%d: %d\n", t, r * f[c]);
    }
    return 0;
}
