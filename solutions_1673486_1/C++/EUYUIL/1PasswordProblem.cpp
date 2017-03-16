#include <cstdio>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 111000;

double p[N], q[N], cache[N];
int T, al, to;

inline double before_old(int i) {
    double r = 0.0;
    for ( ; i >= 0; --i)
        r += q[i];
    return r;
}

inline double after_old(int i) {
    double r = 0.0;
    for ( ; i <= al; ++i)
        r += q[i];
    return r;
}

inline double before(int i) {
    if (i < 0) return 0.0;
    return cache[i];
}

inline double after(int i) {
    if (i < 1) return cache[al];
    return cache[al] - cache[i - 1];
}

inline void init() {
    cache[0] = q[0];
    for (int i = 1; i <= al; ++i)
        cache[i] = cache[i - 1] + q[i];
}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    cin >> T;
    for (int cs = 1; cs <= T; ++cs)
    {
        cin >> al >> to;
        memset(p, 0, sizeof p);
        for (int i = 0; i < al; ++i)
            cin >> p[i];
        double prod = 1.0;
        for (int i = 0; i <= al; ++i) {
            q[i] = prod * (1.0 - p[i]);
            prod *= p[i];
        }
        init();
        double pred = 11111111111111.0;
        for (int i = 0; i <= al; ++i) {
            int j = al - i;
            int succ = 2 * i + to - al + 1;
            double s = double(succ) * after(j);
            int fail = succ + to + 1;
            double f = double(fail) * before(j - 1);
            pred = min(pred, s + f);
        }
        if (al == to) {
            pred = min(pred, q[al] + double(to + 2) * before(al - 1));
        } else {
            pred = min(pred, double(to + 2));
        }
        cout.setf(ios::fixed); cout.precision(6);
        cout << "Case #" << cs << ": " << pred << endl;
    }
    return 0;
}
