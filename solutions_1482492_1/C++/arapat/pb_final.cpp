#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn = 2000 + 10;

int zero(double r)
{
        double e = 1e-8;
        if (r < -e)
                return -1;
        return r > e;
}

int main(void)
{
        int T;
        cin >> T;
        for (int loop = 1; loop <= T; loop++) {
                double d;
                int n, a;
                cin >> d >> n >> a;

                double dd[maxn], tt[maxn];
                for (int i = 0; i < n; i++)
                        cin >> tt[i] >> dd[i];

                cout << "Case #" << loop << ":" << endl;
                for (int k = 0; k < a; k++) {
                        double acc;
                        cin >> acc;

                        double answer, speed;
                        double me = sqrt(2.0 * d / acc);
                        if (zero(dd[0] - d) >= 0) {
                                answer = me;
                        } else {
                                answer = 0.0;
                                speed = 0.0;
                                for (int i = 0; i + 1 < n; i++) {
                                        double d0 = dd[i], d1 = dd[i + 1];
                                        double t0 = tt[i], t1 = tt[i + 1];
                                        if (zero(d0 - d) >= 0)
                                                break;
                                        if (zero(d1 - d) > 0) {
                                                t1 = (d - d0) * (t1 - t0) / (d1 - d0) + t0;
                                                d1 = d;
                                        }
                                        double ime = (-speed + sqrt(speed * speed + 2 * acc * (d1 - d0))) / acc;
                                        double ihe = (t1 - t0);
                                        double it = ime < ihe ? ihe : ime;
                                        speed = speed + it * acc;
                                        answer += it;
                                }
                        }
                        printf("%.8lf\n", answer);
                }
        }

        return 0;
}
