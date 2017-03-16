#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int T, A, B;
double p [1000000];
double ans;

int main () {
    cin >> T;
    cout << setprecision (6);
    cout << fixed;
    for (int t = 0; t < T; t ++) {
        cin >> A >> B;
        for (int i = 0; i < A; i ++)
            cin >> p [i];
        for (int i = 1; i < A; i ++)
            p [i] = p [i] * p [i - 1];
        //for (int i = 0; i < A; i ++)
        //    cout << p [i] << " ";
        //cout << endl;
        ans = B + 2;
        for (int d = 0; d < A; d ++) {
            double a = p [A - d - 1] * (2 * d + B - A + 1)
                     + (1 - p [A - d - 1]) * (2 * d + B - A + 1 + B + 1);
            ans = min (ans, a);
        }
        cout << "Case #" << t + 1 << ": " << ans << endl;
    }
}
