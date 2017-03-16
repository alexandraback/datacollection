#include <iostream>
#define epsi 1e-6
using namespace std;

int main() {
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int task;
    cin >> task;
    for (int t = 1; t <= task; t++) {
        int a, b;
        cin >> a >> b;
        double res = b + 2;
        double p, exp;
        exp = 1;
        for (int i = 1; i <= a; i++) {
            cin >> p;
            exp = exp * p;
            long double temp = a - i + b - i + 1 + (1 - exp) * (b + 1);
            if (res - temp > epsi) {
                res = temp;
            }
        }
        printf("Case #%d: %.6f\n", t, res);
    }
    return 0;
}
