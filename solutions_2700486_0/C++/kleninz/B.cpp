#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <utility>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define INF 2e9
#define pb push_back
#define mp make_pair
#define forn(i,n) for (int i = 0; i < n; i++)
#define MAXN 2000

using namespace std;

typedef long long ll;
typedef double ld;

int t, n, x, y;
ll d[MAXN];
ld pw[MAXN];
ld c[MAXN][MAXN];

ld cnk(int n, int k) {
    if (n < k) {
        return 0.;
    }
    if (n == k || k == 0) {
        return 1. / pw[n];
    }
    if (c[n][k] != -1.) {
        return c[n][k];
    }
    return c[n][k] = (cnk(n - 1, k - 1) + cnk(n - 1, k)) / 2.;
}

ld solve() {
    cin >> n >> x >> y;
    int k = -1, q, s = x + y;
    if (s % 2) {
        return 0.;
    }
    s /= 2;
    if (n == 1) {
        if (s == 0) {
            return 1.;
        } else {
            return 0.;
        }
    }
    for (int i = 0; ; i++) {
        if (d[i] > n) {
            k = i;
            q = n - d[i - 1];
            break;
        }
    }
    //printf(">%d\n", k);
    if (s < k) {
        return 1.0;
    }
    if (s > k) {
        return 0.;
    }
    //printf("HEY %d!\n", q);
    ld ans = 0.;
    //ans += cnk(q, y);
    if (x == 0) {
        if (q == d[k] - d[k - 1]) {
            return 1.;
        }
        else {
            return 0.;
        }
    }
    int flag = 0;
    if (q > 2 * k && 2 * k + y >= q) {
        flag = 1;
        //printf("yeah\n");
        for (int j = 0; j < q - 2 * k; j++) {
            ans += cnk(2 * k + j, j) * pw[2 * k + j] / pw[q];
            //printf("<<%d %d\n", 2 * k + j, j);
        }
    }

    for (int j = 0; j <= y; j++) {
        if (q - j <= 2 * k) {
           // printf(">> %d %d\n", q, j);
            ans += cnk(q, j);
        }
    }
   // printf("ans = %lf\n", ans);

    return 1. - ans;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    pw[0] = 1.;
    for (int i = 1; i < MAXN; i++) {
        pw[i] = pw[i - 1] * 2.;
    }
    forn (i, MAXN) {
        forn (j, MAXN) {
            c[i][j] = -1.;
        }
    }
    //printf(">>>>%lf\n", cnk(3, 2));

    d[0] = 1;


    for (int i = 2; i < MAXN; i++) {
        d[i - 1] = d[i - 2] + 4 * i - 3;
    }

    forn (test, t) {
        printf("Case #%d: %.8lf\n", test + 1, solve());
    }
    return 0;
}
