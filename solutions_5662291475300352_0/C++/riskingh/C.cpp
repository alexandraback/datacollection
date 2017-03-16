#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct man {
    double d, m;
    man(double d, double m): d(d), m(m) {}
};

bool operator < (const man &m1, const man &m2) {
    return m1.d < m2.d || (m1.d == m2.d && m1.m < m2.m);
}

void slow() {
    int n, i, j, d, h, m;
    cin >> n;

    vector<man> M;
    for (i = 0; i < n; ++i) {
        cin >> d >> h >> m;
        for (j = 0; j < h; ++j)
            M.push_back(man(d, m + j));
    }

    if (M.size() != 2) {
        cout << 0 << "\n";
        return;
    }

    man m1 = (M[0] < M[1]) ? M[0] : M[1];
    man m2 = (M[0] < M[1]) ? M[1] : M[0];

    double t1 = (360.0 - m1.d) * 360.0 / m1.m;
    double t2 = (360.0 - m2.d) * 360.0 / m2.m;

    int ans = 1;

    if (m1.m < m2.m) {
        // cerr << "-- 1\n";
        double t = (m2.d - m1.d) * 360.0 / (m2.m - m1.m);
        if (t >= t1)
            ans = 0;
        else {
            t1 -= t;
            t2 -= t;
            t = 360.0 * 360.0 / (m2.m - m1.m);
            if (t > t1)
                ans = 0;
            else
                ans = 1;
        }
    }
    else if (m1.m == m2.m) {
        // cerr << "-- 2\n";
        ans = 0;
    }
    else {
        // cerr << "-- 3\n";
        double t = (m2.d - m1.d) * 360.0 / (m1.m - m2.m);
        if (t1 < t)
            ans = 0;
        else
            ans = 1;
    }

    cout << ans << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int _T, T;
    scanf("%d", &T);
    for (_T = 1; _T <= T; ++_T) {
        printf("Case #%d: ", _T);
        slow();
    }
    return 0;
}