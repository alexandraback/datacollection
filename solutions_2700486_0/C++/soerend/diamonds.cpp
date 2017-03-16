#include <iostream>
#include <algorithm>

using namespace std;

double binomial(int n, int k, int n2)
{
    if (n == 0)
        return 0;
    if (k == 0 || k == n) {
        double d = 1;
        for (int i = 0; i < n2; ++i)
            d /= 2.0;
        return d;
    }
    double nfact = 1.0;
    for (int i = 1; i <= k; ++i) {
        nfact *= (double)(n - k + i)/(double)i;
        if (n2-- > 0)
            nfact /= 2.0;
    }
    while (n2-- > 0)
        nfact /= 2.0;
    return nfact;
}

int main()
{
    int t;
    cin >> t;
    int n, x,y;
    for (int c = 1; c <= t; ++c) {
        cin >> n >> x >> y;
        x = abs(x);
        y = abs(y);
        int xy = x + y;
        int tri = (xy + 1) * (xy + 2) / 2;
        if (n >= tri) {
            cout << "Case #" << c << ": " << 1.0 << endl;
            continue;
        }
        if (n <= tri - xy - xy - 1 || x == 0) {
            cout << "Case #" << c << ": " << 0.0 << endl;
            continue;
        }
        if (tri - xy - xy - 1 + xy + y + 1 <= n) {
            cout << "Case #" << c << ": " << 1.0 << endl;
            continue;
        }
        int toplace = n - tri + xy + xy + 1;
        if (toplace <= y) {
            cout << "Case #" << c << ": " << 0.0 << endl;
            continue;
        }
        long long pow2 = 1 << toplace;
        double prob = 0.0;
        for (int i = y+1; i <= toplace; ++i)
            prob += (double)binomial(toplace, i, toplace);
        cout << "Case #" << c << ": " << prob << endl;
    }
}
