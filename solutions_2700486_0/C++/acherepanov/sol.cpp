#include <iostream>
#include <cstring>

using namespace std;

#define debug(x) // cerr << #x << ": " << x << endl

const int N = 1e3;
long double c[N][N];

void precalc () {
    memset(c, 0, sizeof(c));
    for (int i = 0; i < N; ++i) {
        c[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
}

double sol (int n, int x, int y) {
    if (x < 0) {
        x *= -1;
    }
    
    int r;
    for (r = 0; n >= 2 * r + 1; r += 2) {
        n -= 2 * r + 1;
    }
    
    int lev = (x + y);
    
    debug(n);
    debug(lev);
    debug(r);
    
    if (lev < r) {
        return 1.;
    }
    if (lev > r) {
        return 0.;
    }
    
    long double total = 0, good = 0;
    for (int i = 0; i <= n; ++i) {
        if (i <= r && n - i <= r) {
            total += c[n][i];
            if (i >= y + 1) {
                good += c[n][i];
            }
        }
    }
    debug(good);
    debug(total);
    
    return good / total;
}

void sol (int testNum) {
    int n, x, y;
    cin >> n >> x >> y;
    cout.precision(10);
    cout.setf(ios::fixed | ios::showpoint);
    cout << "Case #" << testNum + 1 << ": " << sol(n, x, y) << "\n";
}

int main () {
    precalc();
    
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        sol(i);
    }
    return 0;
}
