#include <cstdio>

int main() {
    int T, a, b;
    const int MAXN = 100010;
    static double p[MAXN], pp[MAXN], cp[MAXN];
    double best, cur;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        scanf("%d%d", &a, &b);
        for (int i = 0; i < a; i++)
            scanf("%lf", &p[i]);
        pp[0] = p[0];
        cp[0] = 1 - p[0];
        for (int i = 1; i < a; i++) {
            pp[i] = p[i] * pp[i - 1];
            cp[i] = (1 - p[i]) * pp[i - 1];
        }

        // cont typing
        best = pp[a - 1] * (b - a + 1) + (1 - pp[a - 1]) * (2 * b - a + 2);
        //printf("Cont: %f\n", best);

        // press enter
        if (b + 2 < best) best = b + 2;
        //printf("Enter: %f\n", double(b + 2));

        // press backspace
        for (int i = 1; i < a; i++) {
            int typed = a - i;
            cur = (pp[typed - 1] * (i + (b - typed) + 1)) + ((1 - pp[typed - 1]) * (i + (b - typed) + 1 + b + 1));
            //printf("Press %d bs: %f\n", i, cur);
            if (cur < best)
                best = cur;
        }
        printf("Case #%d: %.20f\n", t, best);
    }
}
