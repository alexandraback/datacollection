#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp1(const void *a, const void *b) {
    double v1 = *(double *)a, v2 = *(double *)b;
    if (v1 > v2)
        return 1;
    else if (v1 < v2)
        return -1;
    else
        return 0;
}

void show(double *list, int size) {
    for (int i = 0; i < size; ++i)
        printf("%lf ", list[i]);
    puts("");
}

int deceitful_war(double *naomi, double *ken, int size) {
    int score = 0;
    int p = 0;
    int i, j;
    for (i = size - 1; i >= 0; --i) {
        for (j = p; j < size; ++j)
            if (naomi[j] > ken[i]) {
                ++score;
                naomi[j] = -1.0;
                break;
            }
        if (j >= size)
            ++p;
    }
    return score;
}

int war(double *naomi, double *ken, int size) {
    int score = 0;
    int p, q;

    for (p = 0, q = 0; p < size; ++p) {
        while (q < size && ken[q] < naomi[p]) {
            q++;
            score++;
        }
        if (q >= size)
            break;
        q++;
    }
    return score;
}

void run() {
    double ken[1200], naomi[1200];
    int size;
    scanf("%d", &size);
    for (int i = 0; i < size; ++i)
        scanf("%lf", &naomi[i]);
    for (int i = 0; i < size; ++i)
        scanf("%lf", &ken[i]);
    qsort(naomi, size, sizeof(ken[0]), cmp1);
    qsort(ken, size, sizeof(ken[0]), cmp1);
    printf(" %d %d\n", deceitful_war(naomi, ken, size),
        war(naomi, ken, size));
}

int main() {
    int num_cases;
    scanf("%d", &num_cases);
    for (int t = 1; t <= num_cases; ++t) {
        printf("Case #%d: ", t);
        run();
    }
    return 0;
}
