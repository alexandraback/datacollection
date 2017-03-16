#include <cstdio>
#include <cassert>
#include <cmath>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 2000;
const int MAXA = 250;
const double EPS = 1e-7;

double D; int N, A;
double t[MAXN], x[MAXN], a[MAXA];

double sqr(double x) {
    return x * x;
}

int main() {
    int T;
    assert(scanf("%d", &T) == 1);
    for (int tst = 1; tst <= T; tst++) {
        assert(scanf("%lf %d %d", &D, &N, &A) == 3);
        for (int i = 0; i < N; i++) {
            assert(scanf("%lf %lf", t + i, x + i) == 2);
        }
        for (int i = 0; i < A; i++) {
            assert(scanf("%lf", a + i) == 1);
        }

        printf("Case #%d:\n", tst);
        for (int i = 0; i < A; i++) {
            double curPos = 0, curSpeed = 0, curTime = 0;
            if (x[0] < D) {
                for (int j = 1; j < N && curPos < D; j++) {
                    double nxtPos = x[j], nxtTime = t[j];
                    if (x[j] > D) {
                        nxtPos = D;
                        nxtTime = t[j - 1] + (D - x[j - 1]) /
                                            (x[j] - x[j - 1]) * (t[j] - t[j - 1]);
                        assert(fabs(t[j - 1] - curTime) < EPS);
                    }

                    double myPos = curPos + curSpeed * (nxtTime - curTime) +
                                0.5 * a[i] * sqr(nxtTime - curTime);
                    if (myPos <= nxtPos) {
                        curSpeed = curSpeed + a[i] * (nxtTime - curTime);
                        curPos = myPos;
                        curTime = nxtTime;
                    } else {
                        // Need to hit position nxtPos while maximising curSpeed
                        // at the end.

                        // v0t + 0.5at^2 = nxtPos - curPos
                        // v0 + at max
                        // v0 = (nxtPos - curPos - 0.5at^2) / t
                        // => C + 0.5at + at max => a max => stay stationary for a
                        // while, then let maximum acceleration

                        curSpeed = a[i] * sqrt(2 * (nxtPos - curPos) / a[i]);
                        curPos = nxtPos;
                        curTime = nxtTime;
                    }
                }
            }
            if (curPos < D) {
                // curSpeed t + 0.5 a t^2 = D - curPos
                double pA = 0.5 * a[i], pB = curSpeed, pC = curPos - D;
                double delta = pB * pB - 4 * pA * pC;
                double t = (-pB + sqrt(delta)) / pA * 0.5;
                assert(fabs(0.5 * a[i] * t * t + curSpeed * t - D + curPos) < EPS);
                curTime += t;
            }
            printf("%.7lf\n", curTime);
        }
    }
    return 0;
}
