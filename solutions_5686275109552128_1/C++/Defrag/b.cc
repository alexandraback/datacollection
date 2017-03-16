#include "math.h"
#include "stdio.h"
#include "algorithm"

int main(int argc, char const *argv[])
{
    int numCases = 0;
    scanf("%d", &numCases);

    int P[1000];
    int lenP = 0;
    for (int i=0; i<1000; ++i) {
        P[i] = -1;
    }

    for (int caseNum=0; caseNum<numCases; ++caseNum) {
        scanf("%d", &lenP);
        // printf("lenP = %d\n", lenP);

        for (int i=0; i<lenP; ++i) {
            scanf("%d", P+i);
            // printf("  p[%d] = %d\n", i, P[i]);
        }


        int maxHeight = 0;
        for (int i=0; i<lenP; ++i) {
            maxHeight = std::max(maxHeight, P[i]);
        }

        int minTime = maxHeight;
        int t;
        for (int h=1; h<maxHeight; ++h) {
            t = h;  // eating time

            // moving time
            for (int i=0; i<lenP; ++i) {
                t +=  ((P[i] + h - 1) / h) - 1; // ceil(P[i] / h) - 1;
            }
            // printf("   h %d \t time: %d\n", h, t);
            minTime = std::min(minTime, t);
        }

        // for (int cutOff=0; cutOff<1000; ++cutOff) {
        //     for (int i=0; i<1000; ++i) {
        //         if (i<cutOff) {
        //             total += i;
        //         }
        //     }
        // }
        // printf("%i\n", total);
        printf("Case #%d: %d\n", caseNum+1, minTime);
    }


    // for (int i=0; i<10; ++i) {
    //     int a=-1;
    //     scanf("%d", &a);
    //     printf("%d\n", a);
    // }

    return 0;
}
