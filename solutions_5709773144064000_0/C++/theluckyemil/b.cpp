#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int test_amo; cin >> test_amo;
    for (int test_num = 1; test_num <= test_amo; test_num++) {
        double C, F, X; cin >> C >> F >> X;
        double ans = X / 2;
        double prod = 2;
        double cur = 0;
        for (int it = 1; it <= 100000; it++) {
            cur += C / prod;
            prod += F;
            ans = min(ans, cur + X / prod);
        }
        printf("Case #%d: ", test_num);
        printf("%.10lf\n", ans);
    }

    return 0;
}
