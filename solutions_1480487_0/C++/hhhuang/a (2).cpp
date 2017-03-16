#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int s[210];
int x;
int n;
int score = 0;
double y[210];
double norm = 0;

int count() {
    int size = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] >= 0)
            ++size;
    }

    double norm = 0;
    int base = 0;
    for (base = 0; base < n; ++base)
        if (s[base] >= 0)
            break;

    for (int i = base + 1; i < n; ++i) {
        if (s[i] < 0)
            continue;

        y[i] = (double)(s[base] - s[i]) / x;
        norm += y[i];
    } 
    y[base] = (1 - norm) / size;
    for (int i = base + 1; i < n; ++i) {
        if (s[i] < 0)
            continue;
        y[i] += y[base];
    }
    int flag = 0;
    for (int i = base; i < n; ++i) {
        if (s[i] < 0)
            continue;
        if (y[i] <= 0) {
            s[i] = -1;
            y[i] = 0;
            flag = 1;
        }
    }
    return flag;
}

int main() {
    int num_cases;
    int turn;
    int ans;
    scanf("%d", &num_cases);

    for (turn = 1; turn <= num_cases; ++turn) {
        scanf("%d", &n);
        x = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &s[i]);
            x += s[i];
        }
        while (count())
            ;

        printf("Case #%d:", turn);
        for (int i = 0; i < n; ++i) {
            printf(" %.6lf", (y[i]) * 100);
        }
        printf("\n");
    }
    return 0;
}
