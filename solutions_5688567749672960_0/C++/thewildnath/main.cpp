#include <cstdio>
#include <queue>
using namespace std;

const int NMAX = 1000000;
const int INF = 1000000000;

int d[NMAX + 1];
int inv[NMAX + 1];

inline int invers (int n) {
    int m = 0;

    while (n) {
        m = m * 10 + n % 10;
        n /= 10;
    }

    return m;
}

void bfs () {
    queue<int> q;
    q.push (0);

    while (!q.empty ()) {
        int n = q.front ();
        q.pop ();

        if (n < NMAX && d[n + 1] > d[n] + 1) {
            d[n + 1] = d[n] + 1;
            q.push (n + 1);
        }
        if (inv[n] < NMAX && d[inv[n]] > d[n] + 1) {
            d[inv[n]] = d[n] + 1;
            q.push (inv[n]);
        }
    }
}

int main () {
    //freopen ("date.in", "r", stdin);
    //freopen ("date.out", "w", stdout);
    int t, n;

    for (int i = 1; i <= NMAX; ++i) {
        inv[i] = invers (i);
        d[i] = INF;
    }

    bfs ();

    scanf ("%d", &t);
    for (int i = 1; i <= t; ++i) {
        scanf  ("%d", &n);
        printf ("Case #%d: %d\n", i, d[n]);
    }
}
