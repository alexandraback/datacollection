#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

double C, F, X;

double solve(int falm) {
    double time_for_cookie_farm = C / (falm * F + 2.0);
    double time_for_done_without_farm = X / (falm * F + 2.0);

    double time_for_done_with_farm_expected = X / ((falm+1)*F + 2.0);

    if (time_for_cookie_farm + time_for_done_with_farm_expected > time_for_done_without_farm)
        return time_for_done_without_farm;

    double time_for_done_with_farm = solve(falm+1);

    double time_built = time_for_cookie_farm + time_for_done_with_farm;
    double time_not_built = time_for_done_without_farm;

    return min(time_built, time_not_built);
}

int main() {
    int T;
    cin >> T;

    for (int testCase = 1; testCase <= T; ++testCase) {
        cin >> C >> F >> X;
        printf("Case #%d: %.7lf\n", testCase, solve(0));
    }

    return 0;
}
