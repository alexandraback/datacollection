#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    long long cnt, d0, d1, i, j, m0, m1, n, res, t, t0, t1, temp;
    vector <long long> d, h, m;
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    cin >> t;
    for (cnt = 1; cnt <= t; cnt++)
    {
        cin >> n;
        d.resize(n); h.resize(n); m.resize(n);
        for (i = 0; i < n; i++) { cin >> d[i]; cin >> h[i]; cin >> m[i]; }
        if ((n == 1) && (h[0] == 1)) res = 0;
        if ((n == 1) && (h[0] == 2)) res = 0;
        if (n == 2) {
            /*possibilities:
            1) slower hiker on the back or parallel
            - follow slower hiker, no encounter between hikers before slower one reach 360 -> res = 0
            - follow slower hiker, 1 encounter between hikers before slower one reach 360 -> overtake and follow the faster one, res = 1
            - follow slower hiker, 2+ encounter between hikers before slower one reach 360 -> overtake and follow the faster one, res = 1 (no need to do more rounds)
            2) slower hiker on the front = faster hiker on the back
            - if the faster one do not intersect before 360, tail faster hiker until the end -> res = 0
            - if the faster one do intersect before 360, tail until intersection
            2a) after intersection:
            - if faster one do overtake again before slower one reach 360, overtake the slower one and tail the faster one until 360 -> res = 1
            - if faster one do not overtake again before slower one reach 360, follow the slower one -> res = 0
            3) both hikers are equally fast, can ride along -> res = 0*/
            d0 = d[0]; d1 = d[1]; m0 = m[0]; m1 = m[1];
            if (m0 == m1) res = 0;
            if (m0 < m1) { // m0 must > m1 --> m0 = slower hiker, m1 = faster hiker
                temp = m0; m0 = m1; m1 = temp;
                temp = d0; d0 = d1; d1 = temp;
            }
            t0 = (360 - d0) * m0;
            t1 = (360 - d1) * m1;
            //cout << d0 << " " << d1 << " " << m0 << " " << m1 << " " << endl;
            // case 1
            if (d0 <= d1) {
                t1 = (720 - d1) * m1;
                res = 0; if (t1 <= t0) res = 1;
            }
            // case 2
            if (d0 > d1) {
                if (t1 >= t0) res = 0;
                if (t1 < t0) {
                    t1 = (720 - d1) * m1;
                    res = 0; if (t1 <= t0) res = 1;
                }
            }
        }
        if (n > 2) res = 0; // not yet implemented
        cout << "Case #" << cnt << ": " << res << endl;
    }
    return 0;
}
