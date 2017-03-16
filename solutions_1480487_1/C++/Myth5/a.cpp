#include <iostream>
#include <string>
using namespace std;

const int maxn = 200 + 5;

int n, a[maxn];

int main()
{
    freopen("a2.in", "r", stdin);
    freopen("a2.out", "w", stdout);

    int t2;
    cin >> t2;
    for (int t1 = 1; t1 <= t2; ++t1) {
        cin >> n;
        int s = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            s += a[i];
        }
        printf("Case #%d:", t1);
        for (int i = 1; i <= n; ++i) {
            double lef = 0, rig = 1;
            while (lef + 1e-7 < rig) {
                double mid = (lef + rig) / 2;
                bool ok = false;
                double t = 1 - mid;
                for (int j = 1; j <= n; ++j)
                    if (j != i && a[j] < a[i] + s * mid) {
                        double p = (a[i] + s * mid - a[j]) / s;
                        if (p < t)
                            t -= p;
                        else {
                            ok = true;
                            break;
                        }
                    }
                if (ok)
                    rig = mid;
                else
                    lef = mid;
            }
            printf(" %.6lf", lef * 100);
        }
        printf("\n");
    }
    
    return 0;
}
