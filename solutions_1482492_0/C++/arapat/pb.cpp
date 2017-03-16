#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

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

                double d0, d1, t0, t1;
                if (n == 1)
                        cin >> t0 >> d0;
                else
                        cin >> t0 >> d0 >> t1 >> d1;

                cout << "Case #" << loop << ":" << endl;
                for (int k = 0; k < a; k++) {
                        double acc;
                        cin >> acc;

                        double answer;
                        double me = sqrt(2.0 * d / acc);
                        if (zero(d0 - d) >= 0) {
                                answer = me;
                        } else {
                                double he = (d - d0) * (t1 - t0) / (d1 - d0);
                                answer = me < he ? he : me;
                        }
                        printf("%.8lf\n", answer);
                }
        }

        return 0;
}
