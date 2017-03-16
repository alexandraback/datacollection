#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
//#include <conio.h>

using namespace std;

#define oo 1000000000
#define X first
#define Y second
#define sqr(a) ((a)*(a))
#define FR(i,n) for (int i = 0; i < (n); i++)
#define DN(i,a) for(int i = (a)-1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define DOWN(i,a,b) for(int i = (a); i >= (b); i--)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define MAXN 105
#define esl 1e-7

typedef pair<int, int> PII;
typedef vector<int> VI;

double h, d[MAXN][MAXN];
bool dd[MAXN][MAXN];
int cel[MAXN][MAXN], flo[MAXN][MAXN], m, n;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool ok(int u, int v) {
    if (u < 1 || u > m) return false;
    if (v < 1 || v > n) return false;
    return true;
}

bool pass(int u1, int v1, int u2, int v2, double time) {
    double cur = h - time * 10;
    if (cur + 50 > cel[u2][v2]) return false;
    if (flo[u1][v1] + 50 > cel[u2][v2]) return false;
    if (flo[u2][v2] + 50 > cel[u2][v2]) return false;
    if (flo[u2][v2] + 50 > cel[u1][v1]) return false;
    return true;
}

double timepass(int i, int j, double time) {
    double cur = h - time * 10;
    if (cur - flo[i][j] >= 20) return 1;
    return 10;
}

void loang() {
    queue <PII> Q;
    bool dd[MAXN][MAXN];
    memset(dd, 0, sizeof(dd));
    Q.push(PII(1, 1));
    dd[1][1] = true;
    while (!Q.empty()) {
        PII V = Q.front();
        Q.pop();
        int u1 = V.X;
        int v1 = V.Y;
        d[u1][v1] = 0;
        FOR(i, 0, 3) {
            int u2 = u1 + dx[i];
            int v2 = v1 + dy[i];

            if (ok(u2, v2) && !dd[u2][v2] && pass(u1, v1, u2, v2, 0)) {
                Q.push(PII(u2, v2));
                dd[u2][v2] = true;
            }
        }
    }
}

void process() {
    FOR(i, 1, m)
        FOR(j, 1, n) {
            d[i][j] = oo;
        }
    loang();
    memset(dd, 0, sizeof(dd));
    while (1) {
        double mins = oo + 1;
        int li, lj;
        FOR(i, 1, m)
            FOR(j, 1, n) {
                if (!dd[i][j] && d[i][j] < mins) {
                    mins = d[i][j];
                    li = i;
                    lj = j;
                }
            }
        //cout << li << ' ' << lj << ' ' << d[li][lj] << endl;
        dd[li][lj] = true;
        if (li == m && lj == n) {
            printf("%.7lf\n", d[m][n]);
            return;
        }
        FOR(i, 0, 3) {
            int u = li + dx[i];
            int v = lj + dy[i];
            if (!ok(u, v) || dd[u][v]) continue;
            double time = d[li][lj] + max(0.0, (h - d[li][lj] * 10 - (cel[u][v] - 50)) / 10);
            //cout << u << ' ' << v << ' ' << time << endl;
            if (pass(li, lj, u, v, time + esl)) {
                d[u][v] = min(d[u][v], time + timepass(li, lj, time));
            }
        }
    }
}

int main () {
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int ntest;
    cin >> ntest;
    FOR(test, 1, ntest) {
        cin >> h >> m >> n;
        FOR(i, 1, m)
            FOR(j, 1, n) cin >> cel[i][j];
        FOR(i, 1, m)
            FOR(j, 1, n) cin >> flo[i][j];
        printf("Case #%d: ", test);
        process();
    }
    return 0;
}
