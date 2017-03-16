#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("Usage: You're doing it wrong\n");
        return 1;
    }

    FILE* fin = fopen(argv[1], "r");
    FILE* fout = fopen(argv[2], "w");
    int T,t,i,j,k;
    fscanf(fin, "%d", &T);
    for (t=0; t<T; t++) {
        int A,B,C,D;
        fscanf(fin, "%d %d", &A, &B);
        C=A;
        D=B-A;
        double best;
        best = B + 2.; // Base 'give up' case
        double probRight = 1.0;
        for (i=0; i<A; i++) {
            C--;
            double pt;
            fscanf(fin, "%lf", &pt);
            probRight *= pt;
            double rightCost = 2*C + D + 1;
            double wrongCost = rightCost + B + 1;
            double expectedCost = rightCost * probRight + wrongCost * (1 - probRight);
            if (expectedCost < best)
                best = expectedCost;
        }
        fprintf(fout, "Case #%d: %.6lf\n", t+1, best);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
