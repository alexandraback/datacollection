#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long I64;
typedef unsigned long long U64;

int gK;
int gC;
int gS;

void solve(FILE* fout) {
    int n = max(1, gK - gC + 1);

    if (gS < n) {
        fprintf(fout, " IMPOSSIBLE");
        return;
    }

    I64 start = 0;
    for (int i = 1; i <= gK - n; i++)
        start = start * gK + i;

    while (n-- > 0)
        fprintf(fout, " %lld", ++start);
}

int main(int argc, char* argv[]) {
    FILE* fin = fopen(argv[1], "rt");
    FILE* fout = fopen(argv[2], "wt");

    int T;

    fscanf(fin, "%d", &T);
    for (int tn = 1; tn <= T; tn++) {
        fscanf(fin, "%d %d %d", &gK, &gC, &gS);
        fprintf(fout, "Case #%d:", tn);
        solve(fout);        
        fprintf(fout, "\n");
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
