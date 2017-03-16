
#include <algorithm>
#include <cstdio>

using namespace std;

int A, B;
double p[100000];

double solve() {
    double s = B + 2;
    double probAll = 1;
    for (int i = 0; i <= A; i++) {
        double num = 2.0 * (A - i) + (B - A) + 1;
        double numExtra = B + 1;
        s = min(s, num + (1 - probAll) * numExtra);
        if (i < A)
            probAll *= p[i];
    }
    return s;
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d%d", &A, &B);
        for (int j = 0; j < A; j++)
            scanf("%lf", &p[j]);

        printf("Case #%d: %.10lf\n", i + 1, solve());
    }
}
