#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

double C, F, X;

double solve_iter() {
    double taken = 0;

    for (int falm = 0; falm < 1000001; ++falm) {
        double time_for_cookie_farm = C / (falm * F + 2.0);
        double time_for_done_without_farm = X / (falm * F + 2.0);

        double time_for_done_with_farm_expected = X / ((falm+1)*F + 2.0);

        if (time_for_cookie_farm + time_for_done_with_farm_expected > time_for_done_without_farm)
            return taken + time_for_done_without_farm;

        taken += time_for_cookie_farm;
    }

    return taken;
}

int main() {
    int T;
    cin >> T;

    for (int testCase = 1; testCase <= T; ++testCase) {
        cin >> C >> F >> X;

        printf("Case #%d: %.7lf\n", testCase, solve_iter());
    }

    return 0;
}
