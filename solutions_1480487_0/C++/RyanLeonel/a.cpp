// headers
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std; // program namespace

int main(int argc, char *argv[]) // main function
{ 
    bool neg = false;
    double pts, pts2;
    int cnt, i, j, n, n2, t, x;
    vector <int> s;
    vector <double> m;
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    cin >> t;
    for (cnt = 1; cnt <= t; cnt++)
    {
        cin >> n; x = 0;
        s.resize(n); m.resize(n);
        for (i = 0; i < n; i++) { cin >> s[i]; x += s[i]; }
        pts = (2.0 * (double)x) / (double)n;
        pts2 = (2.0 * (double)x); n2 = n;
        for (i = 0; i < n; i++)
        {
            m[i] = (pts - (double)s[i]) * 100.0 / (double)x;
            if (m[i] < 0.0) { m[i] = 0.0; neg = true; pts2 -= (double)s[i]; n2--; }
        }
        pts2 /= (double)n2;
        for (i = 0; i < n; i++)
        {
            if (m[i] > 0.0) m[i] = (pts2 - (double)s[i]) * 100.0 / (double)x;
        }
        printf("Case #%d:", cnt);
        for (i = 0; i < n; i++) printf(" %.6f", m[i]);
        printf("\n");
    }
    return 0;
}
