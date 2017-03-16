#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    if (argc != 3) {
        printf("USAGE:\n\t%s in out\n", argv[0]);
        return -1;
    }
    FILE *fin = fopen(argv[1], "r");
    if (fin == NULL) {
        printf("Failed to open in file %s\n", argv[1]);
        return -1;
    }

    FILE *fout = fopen(argv[2], "w");
    if (fout == NULL) {
        printf("Failed to open out file %s\n", argv[2]);
        fclose(fin);
        return -1;
    }
    int T;
    fscanf(fin, "%d", &T);
    int i;
    for (i = 0; i < T; ++i) {
        int J, P, S, K;
        fscanf(fin, "%d %d %d %d", &J, &P, &S, &K);
        char u[J][P][S];
        char jp[J][P];
        char js[J][S];
        char ps[P][S];
        memset(u, 0, sizeof(u));
        memset(js, 0, sizeof(js));
        memset(jp, 0, sizeof(jp));
        memset(ps, 0, sizeof(ps));
        int j, p, s;
        int count = 0;
        while (1) {
            char found = 0;
            for (j = 0; j < J; j++)
                for (p = 0; p < P; p++) {
                    if (jp[j][p] < K) {
                        for (s = 0; s < S; s++) {
                            if (u[j][p][s])
                                continue;
                            if (js[j][s] < K && ps[p][s] < K) {
                                js[j][s]++;
                                ps[p][s]++;
                                jp[j][p]++;
                                u[j][p][s] = 1;
                                count++;
                                found = 1;
                                goto end;
                            }
                        }
                    }
                }
end:
            if (!found)
                break;
        }
        fprintf(fout, "Case #%d: %d\n", i+1, count);
        for (j = 0; j < J; j++)
            for (p = 0; p < P; p++)
                for (s = 0; s < S; s++)
                    if (u[j][p][s])
                        fprintf(fout, "%d %d %d\n", j + 1, p + 1, s + 1);
    }
    fclose(fout);
    fclose(fin);
    return 0;
}
