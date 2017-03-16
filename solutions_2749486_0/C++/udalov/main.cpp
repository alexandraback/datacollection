#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdarg>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); i++)
#define forit(it, v) for (auto it : v)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

#define N 65100000

char ans[512];
int X, Y;
int q[N];
int prev[N];

const int SHIFT = 120;
const int INF = 1000000000;
const int DX[] = {1, 0, -1, 0};
const int DY[] = {0, 1, 0, -1};
const char DC[] = "ENWS";

bool good(int x, int y) {
    return -120 <= x && x <= 120 && -120 <= y && y <= 120;
}

int enc(int x, int y, int z) {
    int u = 0;
    u += ((x + SHIFT) << 18);
    u += ((y + SHIFT) << 9);
    u += z;
    return u;
}

void dec(int v, int& x, int& y, int& z) {
    x = (v >> 18) - SHIFT;
    y = ((v >> 9) & 511) - SHIFT;
    z = v & 511;
}

void go() {
    int qb = 0, qe = 0;
    int start = enc(0, 0, 0);
    q[qe++] = start;
    memset(prev, -1, sizeof prev);

    int ansz = -1;
    while (qb < qe) {
        int v = q[qb++];
        int x, y, z;
        dec(v, x, y, z);
        if (x == X && y == Y) { ansz = z; break; }
        forn(dd, 4) {
            int xx = x + (z+1)*DX[dd], yy = y + (z+1)*DY[dd];
            if (!good(xx, yy)) continue;
            int u = enc(xx, yy, z+1);
            // eprintf("u %d xx %d yy %d z+1 %d\n", u, xx, yy, z+1);
            assert(0 <= u && u < N);
            if (prev[u] == -1) {
                prev[u] = (v << 2) + dd;
                q[qe++] = u;
            }
        }
    }

    if (ansz == -1) { ans[0] = 0; return; }

    int v = enc(X, Y, ansz);
    int ansp = 0;
    while (v != start) {
        assert(0 <= v && v < N);
        int dd = prev[v] & 3;
        ans[ansp++] = DC[dd];
        v = prev[v] >> 2;
    }
    ans[ansp] = 0;
    reverse(ans, ans + ansp);
}

int main() {
    int __;
    scanf("%d", &__);
    forn(_, __) {
        printf("Case #%d: ", _+1);
        scanf("%d%d", &X, &Y);
        go();
        printf("%s\n", ans);
    }
    return 0;
}

