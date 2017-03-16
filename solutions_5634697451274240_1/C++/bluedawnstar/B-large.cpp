#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long I64;
typedef unsigned long long U64;

char gS[200];

int solve() {
    int res = 0;

    int n = strlen(gS) - 1;

    while (n >= 0) {
        while (gS[n] == '+')
            n--;
        if (n < 0)
            break;

        if (gS[0] == '+') {
            for (int i = 0; gS[i] == '+'; i++)
                gS[i] = '-';
            res++;
        }

        reverse(gS, gS + n + 1);
        for (int i = 0; i <= n; i++)
            gS[i] = (gS[i] == '+') ? '-' : '+';
        res++;
    }

    return res;
}

int main(int argc, char* argv[]) {
    FILE* fin = fopen(argv[1], "rt");
    FILE* fout = fopen(argv[2], "wt");

    int T;

    fscanf(fin, "%d", &T);
    for (int tn = 1; tn <= T; tn++) {
        fscanf(fin, "%s", gS);
        fprintf(fout, "Case #%d: %d\n", tn, solve());
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
