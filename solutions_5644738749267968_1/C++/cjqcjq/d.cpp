#include <stdint.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

const int32_t N = 1001;
double A[N];
double B[N];
int32_t n;
int32_t Solve(double a[], double b[]) {
    int32_t ret = 0;
    int32_t j = 0;
    for (int32_t i = 0; i < n; i++) {
        while (j < n && b[j] < a[i]) {
            j++;
        }
        if (j < n) {
            ret++;
            j++;
        }
    }
    return ret;
}
int32_t main() {
    int32_t cas;
    scanf("%d", &cas);
    for (int32_t ic = 1; ic <= cas; ic ++) {
        scanf("%d", &n);
        for (int32_t i = 0; i < n; i++) {
            scanf("%lf", &A[i]);
        }
        for (int32_t i = 0; i < n; i++) {
            scanf("%lf", &B[i]);
        }
        sort(A, A + n);
        sort(B, B + n);
        printf("Case #%d: %d %d\n", ic, Solve(B, A), n - Solve(A, B));
    }
    return 0;
}
