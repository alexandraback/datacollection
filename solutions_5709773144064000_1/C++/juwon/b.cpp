#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int cs = 1; cs <= T; ++cs) {
        printf("Case #%d: ", cs);
        double C, F, X;
        scanf("%lf %lf %lf", &C, &F, &X);

        double v = 2.0;
        double elapsed = 0.0;
        double sol = X;
        for (;;) {
            if (elapsed + X / v < sol) {
                sol = elapsed + X / v;
            } else {
                break;
            }
            elapsed += C / v;
            v += F;
        }
        printf("%.7lf\n", sol);
    }
    return 0;
}

