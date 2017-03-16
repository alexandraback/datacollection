#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;



int main() {
    int T;
    cin >> T;
    for (int times = 1; times <= T; ++times) {
        double C, F, X;
        cin >> C >> F >> X;
        double TP = 0, S = 2, ans = 1e20;
        for (int i = 0; i <= 1000000; ++i) {
            ans = min(ans, TP + X / S);
            double T = C / S;
            TP += T;
            S += F;
        }
        printf("Case #%d: %.10lf\n", times, ans);
    }
    return 0;
}
