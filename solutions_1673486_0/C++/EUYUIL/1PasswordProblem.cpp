#include <cstdio>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 111000;

double p[N], q[N];
int T, al, to;

inline double before(int i) {
    double r = 0.0;
    for ( ; i >= 0; --i)
        r += q[i];
    return r;
}

inline double after(int i) {
    double r = 0.0;
    for ( ; i <= al; ++i)
        r += q[i];
    return r;
}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);

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
