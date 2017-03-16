#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scanAndSolve(int caseN) {
    double farmCost;
    double farmRate;
    double winThresh;

    scanf("%lf %lf %lf", &farmCost, &farmRate, &winThresh);

    double curRate = 2.0;
    double curTime = 0;
    double curAmt = 0.0;

    while (true) {
        double noBuyTime = winThresh / curRate;
        double buyTime = farmCost / curRate + winThresh / (curRate + farmRate);

        if (noBuyTime < buyTime) {
            // We're not buying, so we're done!
            curTime += noBuyTime;
            break;
        } else {
            // We're buying, so add the amount of time taken to save up enough
            // to buy the farm to curTime, and increment curRate.
            curTime += farmCost / curRate;
            curRate += farmRate;
        }
    }

    printf("Case #%d: %.7f\n", caseN, curTime);
}

int main(void) {
    int nC;
    scanf("%d", &nC);

    for (int cC = 0; cC < nC; ++cC) {
        scanAndSolve(cC + 1);
    }
    return 0;
}
