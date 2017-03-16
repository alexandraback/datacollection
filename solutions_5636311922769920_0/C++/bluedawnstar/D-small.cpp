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
    I64 d = 1;
    for (int i = 1; i < gC; i++)
        d *= gK;

    for (int i = 1; i <= gS; i++) {
        fprintf(fout, " %lld", d * i);
    }
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
