#include <set>
#include <iostream>

using namespace std;

double solve(double c, double f, double x, int med) {
    double time = 0;
    for (size_t j = 0; j < med; j++)
         time += 1.0 / (2.0 + j * f);
    time *= c;
    time += x / (2.0 + med * f);
    return time;
}

int main() {
   freopen("B-large.in", "rt", stdin);
   freopen("file.out", "wt", stdout);
    size_t n;
    cin >> n;
    for (size_t i = 0; i < n; i++) {
        double c, f, x;
        cin >> c >> f >> x;
        int l = 0, r = x / c + 1;
        double l_ans = solve(c, f, x, l);
        double r_ans = solve(c, f, x, r);
        while (r - l > 2) {
            int med1 = l + (r - l) / 3;
            int med2 = l + 2 * (r - l) / 3;
            double time1 = solve(c, f, x, med1);
            double time2 = solve(c, f, x, med2);
            if (time1 < time2) {
                r_ans = time2;
                r = med2;
            } else {
                l_ans = time1;
                l = med1;
            }
        }
        double ans = solve(c, f, x, r);
        for (size_t j = l; j < r; j++)
            ans = min(ans, solve(c, f, x, j));
        cout.setf(ios::fixed);
        cout.precision(7);
        cout << "Case #" << i + 1 << ": " << ans << endl;
    }
    return 0;
}
