#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int T;
    cin >> T;
    cout << setprecision(10) << fixed;
    for (int c = 1; c <= T; c++) {
        double C, F, X, t = 0, rate = 2;
        cin >> C >> F >> X;
        while(C/rate + X/(rate+F) < X/rate) {
            t += C/rate;
            rate += F;
        }
        t += X/rate;
        cout << "Case #" << c << ": " << t << endl;
    }

    return 0;
}
