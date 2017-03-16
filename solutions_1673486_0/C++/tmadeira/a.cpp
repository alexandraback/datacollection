#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define NMAX 131072

double P[NMAX], A[NMAX];
double back[NMAX];
int n, k;

int main() {
    int tests;
    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        scanf("%d %d", &k, &n);
        A[0] = 1;
        for (int i = 0; i < k; i++) {
            scanf("%lf", P+i);
            A[i+1] = A[i] * P[i];
        }

        double best = 2 + n;

        for (int i = 0; i <= k; i++) {
            // right
            int rbackspaces = k - i;
            int rnewkeys = n - i;
            int renter = 1;
            // wrong
            int wbackspaces = k - i;
            int wnewkeys = n - i + n;
            int wenter = 2;

            back[i] = A[i] * (rbackspaces + rnewkeys + renter) +
                      (1 - A[i]) * (wbackspaces + wnewkeys + wenter);
            best = min(best, back[i]);
        }
        printf("Case #%d: %.6f\n", test, best);
    }
    return 0;
}

