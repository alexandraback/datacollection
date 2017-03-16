#include <iostream>
#include <stdio.h>
using namespace std;

double getMinDurationToCookies(double c, double f, double x) {
    double secs = 0;
    double cookiesPerSec = 2;

    while(true) {
        double remainingSecs = x / cookiesPerSec;

        double neededSecToBuyFarm = c / cookiesPerSec;
        double cookiesPerSecWithNewFarm = cookiesPerSec + f;
        double remainingSecsWithNewFarm = neededSecToBuyFarm + x / cookiesPerSecWithNewFarm;

        if (remainingSecs <= remainingSecsWithNewFarm) {
            secs += remainingSecs;
            break;
        } else {
            secs += neededSecToBuyFarm;
            cookiesPerSec = cookiesPerSecWithNewFarm;
        }
    }
    return secs;
}

int main() {
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        double c, f, x;
        cin >> c >> f >> x;
        double secs = getMinDurationToCookies(c, f, x);
        printf("Case #%d: %.7f\n", i, secs);
    }

    return 0;
}
