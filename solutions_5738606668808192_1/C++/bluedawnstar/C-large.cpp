#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long I64;
typedef unsigned long long U64;

int gN;
int gJ;

unsigned int gS;
int gT[11][11][32];
int gD[9];

void makeTable() {
    for (int base = 2; base <= 10; base++) {
        for (int div = 2; div <= 10; div++) {
            int r = 1;
            for (int i = 0; i < 32; i++) {
                r %= div;
                gT[base][div][i] = r;
                r *= base;
            }
        }
    }
}

bool check() {
    int n = 0;

    for (int base = 2; base <= 10; base++) {
        bool found = false;
        for (int div = 2; div <= 10; div++) {
            int r = 0;
            for (int i = 0; i < 32; i++) {
                if (gS & (1 << i))
                    r += gT[base][div][i];
            }
            if (r % div == 0) {
                gD[n++] = div;
                found = true;
                break;
            }
        }
        if (!found)
            return false;
    }

    return true;
}

const char* getS(int n) {
    static char s[33];

    s[n] = '\0';
    for (int t = gS; --n >= 0; t >>= 1)
        s[n] = (t & 1) ? '1' : '0';

    return s;
}

void solve(FILE* fout) {
    gS = (1u << (gN - 1)) + 1u;

    int cnt = 0;
    do {
        gS += 2;
        if (check()) {
            cnt++;
        
            fprintf(fout, "%s", getS(gN));
            for (int i = 0; i < 9; i++)
                fprintf(fout, " %d", gD[i]);
            fprintf(fout, "\n");
        }
    } while (cnt < gJ);

    fclose(fout);
}

int main(int argc, char* argv[]) {
    FILE* fin = fopen(argv[1], "rt");
    FILE* fout = fopen(argv[2], "wt");

    int T;

    makeTable();

    fscanf(fin, "%d", &T);
    for (int tn = 1; tn <= T; tn++) {
        fscanf(fin, "%d %d", &gN, &gJ);
        
        fprintf(fout, "Case #%d:\n", tn);
        solve(fout);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
