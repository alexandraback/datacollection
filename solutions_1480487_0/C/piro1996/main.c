#include <stdio.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

void solve(int index);

int main(void)
{
    int i, n;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        solve(i + 1);
    return 0;
}

void solve(int index) {
    int i, n, judge[200];
    double sum = 0, maximum, diff[200];
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &judge[i]);
        sum += judge[i];
    }
    maximum = sum * 2.0 / n;
    sum = 0;
    for(i = 0; i < n; i++) {
        diff[i] = maximum - judge[i];
        if(diff[i] < 0)
            diff[i] = 0;
        sum += diff[i];
    }
    printf("Case #%d: %f", index, diff[0] * 100.0 / sum);
    for(i = 1; i < n; i++) {
        printf(" %f", diff[i] * 100.0 / sum, 0);
    }
    printf("\n");
}
