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
#include <conio.h>

using namespace std;

#define oo 1000000000
#define fi first
#define se second
#define sqr(a) ((a)*(a))
#define FR(i,n) for (int i = 0; i < (n); i++)
#define DN(i,a) for(int i = (a)-1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define DOWN(i,a,b) for(int i = (a); i >= (b); i--)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define MAXN 205

typedef pair<int, int> PII;
typedef vector<int> VI;

int a[MAXN], s, n;

bool check(int v, int m) {
    double x = m / 10000000.0;
    double remain = 100 - x;
    double k = x * s + a[v] * 100;
    //cout << k << endl;
    FOR(i, 1, n) {
        if (i != v) {
            remain -= max((k - a[i] * 100) / s, 0.0);
        }
    }
    //cout << v << ' ' << x << ' ' << remain << endl;
    //getch();
    if (remain > 0) return false;
    return true;
}

double get(int i) {
    int l = 0, r = 1000000000, m, lm;
    do {
        m = (l + r) / 2;
        if (check(i, m)) {
            lm = m;
            r = m - 1;
        } else l = m + 1;
    } while (l <= r);
    return lm / 10000000.0;
}

void process() {
    FOR(i, 1, n) {
        printf("%.6lf ", get(i));
    }
    cout << endl;
}

int main () {
    freopen("A-small-attempt2.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int ntest;
    cin >> ntest;
    FOR(test, 1, ntest) {
        cin >> n;
        s = 0;
        FOR(i, 1, n) {
            cin >> a[i];
            s += a[i];
        }
        printf("Case #%d: ", test);
        process();
    }
    return 0;
}
