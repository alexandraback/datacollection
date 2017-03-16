#include <cstdio>
#include <algorithm>

using namespace std;

const int M = 10000000;

int main() {
    int t;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; ++kase) {
        double C, F, X;
        scanf("%lf %lf %lf", &C, &F, &X);
        double t = 1e100;

        double time = 0;
        for (int k = 0; k < M; ++k) {
            t = min(t, time + X / (2 + k * F));
            time += C / (2 + k * F);
        }

        printf("Case #%d: %.7lf\n", kase, t);
    }
}
