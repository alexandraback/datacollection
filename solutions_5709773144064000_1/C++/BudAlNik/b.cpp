#include <cstdio>
#include <iostream>

using namespace std;
const double eps = 1e-9;

int t;
double c, f, x;

int main() {
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> c >> f >> x;
        
        double temp = x / 2;
        //cout << temp << endl;
        int k = 0;
        while ((c - x) / (2 + k * f) + x / (2 + (k + 1) * f) < -eps) {
            //printf("+ %.8lf\n", (c - x) / (2 + k * f) + x / (2 + (k + 1) * f));
            temp += (c - x) / (2 + k * f) + x / (2 + (k + 1) * f);
            //printf("%.8lf\n", temp);
            ++k;
        }
        printf("Case #%d: %.7lf\n", i + 1, temp);
    }

    return 0;
}