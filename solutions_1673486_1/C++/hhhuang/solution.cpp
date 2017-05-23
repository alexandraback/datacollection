#include <stdio.h>

int a, b;
double prob[100010];

double count() {
    int i, j;
    double keep = 1, enter =1;
    double min, tmp;
    static double rights[100010];
    rights[0] = 1;

    for (i = 1; i <= a; ++i)
        rights[i] = prob[i - 1] * rights[i - 1];
    keep = (b - a + 1) * rights[a] + (b - a + 1 + b + 1) * (1 - rights[a]);
    enter = (b + 2);
    min = keep;
    if (min > enter)
        min = enter;
    for (i = 0; i <= a; ++i) {
        tmp = (a - i + b - i + 1) * rights[i] + 
            (a - i + b - i + 1 + b + 1) * (1 - rights[i]);
//        printf("%d: %lf\n", i, tmp);
        if (tmp < min)
            min = tmp;
    }
    return min;
}

int main() {
    int i, j;

    int num_cases;
    int t;
    scanf("%d", &num_cases);

    for (t = 1; t <= num_cases; ++t) {
        scanf("%d%d", &a, &b);
        for (i = 0; i < a; ++i)
            scanf("%lf", &prob[i]);
        printf("Case #%d: %.6lf\n", t, count());
    }
    return 0;
}
