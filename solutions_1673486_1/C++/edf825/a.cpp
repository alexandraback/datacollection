#include <stdio.h>

#define MIN(X,Y) ((X)<(Y)?(X):(Y))

int main() {
    int T;
    int a, b;

    scanf("%d", &T);

    for (int K = 1; K <= T; K++) {
        scanf("%d%d", &a, &b);

        double result;

        double *prob = new double[a];

        for (int i = 0; i < a; i++) {
            scanf("%lf", &prob[i]);
        }

        double costToComplete = 1;
        double costToRedo = b + 2;
        double *bkspCost = new double[a];

        double allRightProb = 1.0;

        double best = 1e10;

        for (int i = 0; i < a; i++) {
            costToComplete *= prob[i];
        }

        for (int i = a - 1; i >= 0; i--) {
            allRightProb *= prob[a - 1 - i];

            bkspCost[i] = i + (b - a + i + 1) +
                          (1 - allRightProb) * (b + 1);

            best = MIN(best, bkspCost[i]);

            //printf("%lf %lf %d %d\n", allRightProb, bkspCost[i], i + (b - a + i + 1), b + 1);
        }

        costToComplete = (b - a + 1) + (1.0 - costToComplete) * (b + 1);

        best = MIN(best, costToRedo);
        best = MIN(best, costToComplete);


        printf("Case #%d: %.6lf\n", K, best);
    }

    return 0;
}
