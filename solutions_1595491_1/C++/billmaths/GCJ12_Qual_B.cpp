#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(void) {
    FILE *fin = fopen("B-large.in", "r");
    FILE *fout = fopen("B-large.out", "w");
    int T, N, S, p;
    int g[100];
    fscanf(fin, "%d", &T);
    for (int ni = 1; ni <= T; ++ni) {
        fscanf(fin, "%d %d %d", &N, &S, &p);
        for (int i = 0; i < N; ++i) fscanf(fin, "%d", &g[i]);
        int c1 = 0;
        int c2 = 0;
        for (int i = 0; i < N; ++i) {
            int x = g[i] / 3;
            if (g[i] % 3 == 0) {
                if (x >= p) c1++;
                else if (x != 0 && x + 1 == p) c2++;
            } else if (g[i] % 3 == 1) {
                if (x + 1 >= p) c1++;
            } else {
                if (x + 1 >= p) c1++;
                else if (x + 2 == p) c2++;
            }
        }
        int res = c1 + min(c2, S);
        fprintf(fout, "Case #%d: %d\n", ni, res);
    }
    fclose(fin);
    fclose(fout);

    return 0;
}
