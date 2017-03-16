#include <iostream>
#include <vector>

using namespace std;

long double nchoosek(int n, int k) {
    long double res = 1;
    for (int i = 0; i < k; i++) {
        res *= (n - i);
        res /= (1+i);
    }
    return res;
}

int main()
{
    int coden, t;
    cin >> t;
    // define vars
    int n, x, y;
    int k;
    int basenum;
    int left; // n - basenum;

    for (coden = 1; coden <= t; coden++) {
        cin >> n >> x >> y;

        k = (x > 0) ? x : (-x);
        k = (k + y) / 2;
        basenum = k * (2*k-1);

        // output result
        cout << "Case #" << coden << ": ";

        if (x == 0) {
            // special case
            if (n >= (k+1)*(2*k+1)) {
                cout << "1.0" << endl;
            } else {
                cout << "0.0" << endl;
            }
        } else if (n <= basenum + y) {
            //cout << "(n=" << n << ") <= (basenum=" << basenum << ") + (y=" << y << ")" << endl;
            cout << "0.0" << endl;
        } else if (n >= basenum + 2 * k + y + 1) {
            //cout << "(n=" << n << ") >= (basenum=" << basenum << ") + 2*(k=" << k << ") + (y=" << y << ") + 1" << endl;
            cout << "1.0" << endl;
        } else {
            left = n - basenum;
            // y+1 <= left <= 2 * k + y
            long double sum = 0;
            for (int i = 0; i <= y; i++) {
                sum += nchoosek(left, i);
            }
            for (int i = 0; i < left; i++) {
                sum /= 2;
            }
            cout << (1 - sum) << endl;
        }


    }
    return 0;
}

