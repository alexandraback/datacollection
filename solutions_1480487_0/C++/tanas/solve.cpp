#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>

using namespace std;

typedef long long llong;
typedef long double ldouble;

int main()
{
    freopen("in", "rt", stdin);
    freopen("out", "wt", stdout);
    int t;
    cin >> t;
    for (int test_case = 1; test_case <= t; ++test_case) {
        int n;
        cin >> n;
        vector<ldouble> a(n);
        ldouble sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        printf("Case #%d:", test_case);
        for (int i = 0; i < n; ++i) {
            ldouble L = 0, R = 1;
            while (L + 1e-12 < R) {
                ldouble cur = (L + R) / 2;
                //cur = 33.3333333;
                //ldouble need = (a[i] + cur * sum) * n - sum - cur * sum;
                ldouble will = a[i] + sum * cur;
                ldouble need = 0;
                for (int j = 0; j < n; ++j) {
                    if (j != i && a[j] < will) {
                        need += will - a[j];
                    }
                }
                //printf("%.5f %.5f\n", need, sum * (100 - cur));
                
                if (sum * (1 - cur) > need) {
                    L = cur;
                } else {
                    R = cur;
                }

            }
            printf(" %.9f", (double)(L * 100));
        }
        printf("\n");
    }

    return 0;
}
