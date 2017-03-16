#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* fin = fopen("cookie.in", "r");
    FILE* fou = fopen("cookie.txt", "w");
    int c, t;
    fscanf(fin, "%d\n", &t);
    for (c = 0; c < t; c++) {
        double C, F, X, best, tk, p0 = 2.0;
        int k;
        fscanf(fin, "%lf %lf %lf\n", &C, &F, &X);
        fprintf(fou, "Case #%d: ", c + 1);
        k = 0;
        best = X / p0;
        tk = 0;
        while (tk < X / p0 && k < 1000000) {
            tk += C / (p0 + (k++) * F);
            if (best > tk + X / (p0 + k * F))
                best = tk + X / (p0 + k * F);
        }
        fprintf(fou, "%.7lf\n", best);
    }
    fclose(fou);
    fclose(fin);
    return 0;
}
