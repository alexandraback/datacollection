#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;

const int MAXN = 100001;
double p[MAXN];
double mul[MAXN];

int main() {
    int nTests;
    cin >> nTests;
    for (int test = 1; test <= nTests; ++test) {
        int A, B;
        cin >> A >> B;
        for (int i = 0; i < A; ++i) {
            cin >> p[i];
        }
        mul[0] = p[0];
        for (int i = 1; i < A; ++i) {
            mul[i] = p[i] * mul [i - 1];
        }
        double ret = -1.0;
        // first case
        double temp = 0.0;
        double P = mul[A - 1];
        temp += P * (B - A + 1.0);
        temp += (1.0 - P) * (B - A + 1.0 + B + 1.0);
        if (ret < -0.5 || temp < ret) ret = temp;
        // second case
        for (int i = 1; i <= A; ++i) {
            temp = 0.0;
            if (A - i - 1 < 0) P = 1.0;
            else P = mul[A - i - 1];
            temp += P * (i + B - A + i + 1.0);
            temp += (1.0 - P) * (i + B - A + i + 1.0 + B + 1.0);
            if (ret < -0.5 || temp < ret) ret = temp;
        }
        // third case
        temp = 0.0;
        if (A == B) P = mul[A - 1];
        else P = 0.0;
        temp += P * 1.0;
        temp += (1.0 - P) * (1.0 + B + 1.0);
        if (ret < -0.5 || temp < ret) ret = temp;

        cout.setf(ios::fixed);
        cout.precision(10);
        cout << "Case #" << test << ": " << ret << endl;
    }
    return 0;
}
