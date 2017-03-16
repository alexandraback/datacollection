#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <clocale>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
using namespace std;

int test;

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    ios_base::sync_with_stdio(false);
    cout << setprecision(8);

    cin >> test;
    for (int i = 0; i < test; i++) {
        double c, f, x;
        cin >> c >> f >> x;
        double left = 0.0, right = 1e200;
        double eps = 1e-8;
        while (right - left > eps) {
            double t = (left + right)/2.0;
            double grow = 2.0;
            double res = grow*t;
            while (x - res > eps) {
                double rem_t = c/grow;
                if (t - rem_t > eps) {
                    res -= c;
                    t -= rem_t;
                    grow += f;
                    res += t*f;
                }
                else break;
            }

            if (x - res > eps) {
                left = (left + right)/2.0;
            }
            else  right = (left + right)/2.0;
        }
        cout << fixed << "Case #" << i + 1 << ": " << right << endl;
        cout.flush();
    }

    return 0;
}
