#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int z = 1; z <= T; ++z) {
        cout << "Case #" << z << ": ";
        int A, B;
        cin >> A >> B;
        vector<double> p;
        for (int i = 0; i < A; ++i) {
            double C;
            cin >> C;
            p.push_back(C);
        }
        vector<double> ppp;
        ppp.push_back(p[0]);
        for (int i = 1; i < A; ++i) {
            ppp.push_back(ppp.back() * p[i]);
        }
        double min = 2 + B;
        for (int i = 0; i < A; ++i) {
            // backspace `i' times, remainder of password, enter
            double tmin = i + (i + B - A) + 1;
            tmin += (1 - ppp[ppp.size()-1-i]) * (B + 1);
            if (tmin < min) min = tmin;
        }
        cout << fixed << setprecision(6) << min << endl;
    }
}