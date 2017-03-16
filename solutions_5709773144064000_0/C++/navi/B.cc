#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int T;
double C, F, X;

double gao() {
    double rate = 2.0;
    double base = 0.0;
    double ret = X / rate;
    for (int i = 0; i < 1000000; ++i) {
        base += C / rate;
        rate += F;
        double cur = base + X / rate;
        ret = min(ret, cur);
    }
    return ret;
}

int main() {
    scanf("%d", &T);
    for (int caseNum = 1; caseNum <= T; ++caseNum) {
        scanf("%lf%lf%lf", &C, &F, &X);
        printf("Case #%d: %.13f\n", caseNum, gao());
    }
    return 0;
}

/*
--
X / 2
C / 2 + X / (2 + F)
C / 2 + C / (2 + F) + X / (2 + 2F)
C / 2 + C / (2 + F) + ... + C / (2 + kF) + X / (2 + (k + 1)F)

(C - X) / (2 + kF) + X / (2 + (k + 1)F)

*/
