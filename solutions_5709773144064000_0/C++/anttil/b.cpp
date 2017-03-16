#include <iostream>
#include <cstdio>

using namespace std;

int t;
double c, f, x;

int main() {
    cin >> t;
    for (int z = 1; z <= t; z++) {
        double q = 999999999;
        cin >> c >> f >> x;
        double r = 2;
        double a = 0;
        while (true) {
            double u = a+x/r;
            if (u >= q) break;
            q = u;
            a += c/r;
            r += f;
        }
        printf("Case #%i: %.10f\n", z, q);
    }
}
