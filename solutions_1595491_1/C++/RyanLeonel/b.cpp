#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int cnt, i, len, n, np, p, p0, p1, s, s1, t;
    vector <int> v;
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    cin >> t;
    for (cnt = 1; cnt <= t; cnt++)
    {
        cin >> n; cin >> s; cin >> p;
        v.resize(n); for (i = 0; i < n; i++) cin >> v[i];
        p0 = (3 * p) - 2; p1 = (3 * p) - 4; // p0 = min non-surprising score, p1 = min surprising score
        if (p == 0) { p0 = 0; p1 = 0; }
        if (p == 1) { p0 = 1; p1 = 1; }
        np = 0; s1 = 0;
        for (i = 0; i < n; i++)
        {
            if (v[i] >= p0) np++;
            else
            {
                if ((v[i] >= p1) && (s1 < s)) { np++; s1++; }
            }
        }
        cout << "Case #" << cnt << ": " << np << endl;
    }
    return 0;
}
