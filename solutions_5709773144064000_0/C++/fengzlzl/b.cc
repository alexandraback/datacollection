#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        double C, F, X;
        scanf("%lf%lf%lf", &C, &F, &X);
       // cout << C << " " << F << " " << X << endl;
        //printf("C=%lf F=%lf X=%lf\n", C, F, X);
        double tot_time = 0;
        double speed = 2.0;
        while (true) {
            double buy_none = X / speed;
            double buy_one = C / speed + X / (speed + F);
            if (buy_none <= buy_one) break;
            tot_time += C / speed;
            speed += F;
        }
        tot_time += X / speed;
        printf("Case #%d: %.10f\n", cas, tot_time);
    }
    return 0;
}
