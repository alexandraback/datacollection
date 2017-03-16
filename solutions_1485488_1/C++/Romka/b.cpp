#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <memory.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

const int di[] = {1, 0, -1, 0};
const int dj[] = {0, 1, 0, -1};

int n, m, h, C[110][110], F[110][110], u[110][110], it;
int d[110][110];

void solve() {
    scanf("%d %d %d", &h, &n, &m);
    forn(i, n)
        forn(j, m)
            scanf("%d", &C[i][j]);
    forn(i, n)
        forn(j, m)
            scanf("%d", &F[i][j]);

    vector<pii> q;
    q.pb(pii(0, 0));
    forn(i, n) forn(j, m) d[i][j] = (int)1e9;
    d[0][0] = 0;

    while (!q.empty()) {
        vector<pii> nq;
        it++;
        forn(i, q.size()) {
            int ci = q[i].first;
            int cj = q[i].second;

            forn(w, 4) {
                int ni = ci + di[w];
                int nj = cj + dj[w];
                if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
                if (C[ni][nj] - F[ni][nj] < 50) continue;
                if (C[ni][nj] - F[ci][cj] < 50) continue;
                if (C[ci][cj] - F[ni][nj] < 50) continue;
                int cl = h - d[ci][cj];
                int nl = C[ni][nj] - 50;
                int w = max(0, cl - nl);
                // printf("nl = %d, cl = %d, w = %d\n", nl, cl, w);
                w += (cl - w - F[ci][cj] >= 20 ? 10 : 100) * (cl - w < h);

                if (d[ni][nj] > d[ci][cj] + w) {
                    // printf("%d,%d <- %d,%d (%d + %d)\n", ni, nj, ci, cj, d[ci][cj], w);
                    d[ni][nj] = d[ci][cj] + w;
                    if (u[ni][nj] != it) {
                        u[ni][nj] = it;
                        nq.pb(pii(ni, nj));
                    }
                }

            }
        }
        q = nq;
    }

    printf("%.8f\n", d[n-1][m-1] / 10.0);
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int q = 1; q <= tc; q++) {
        printf("Case #%d: ", q);
        solve();
    }
}
