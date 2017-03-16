#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

typedef long long I64;
typedef unsigned long long U64;

int gN;
unordered_set<int> gDS;
unordered_set<I64> gNS;

I64 solve() {
    gDS.clear();
    gNS.clear();

    I64 n = 0;
    while (gDS.size() < 10) {
        n += gN;
        if (gNS.find(n) != gNS.end())
            return -1;
        gNS.insert(n);

        I64 t = n;
        while (t) {
            gDS.insert(t % 10);
            t /= 10;
        }
    }

    return n;
}

int main(int argc, char* argv[]) {
    FILE* fin = fopen(argv[1], "rt");
    FILE* fout = fopen(argv[2], "wt");

    int T;

    fscanf(fin, "%d", &T);
    for (int tn = 1; tn <= T; tn++) {
        fscanf(fin, "%d", &gN);

        I64 res = solve();

        fprintf(fout, "Case #%d: ", tn);
        if (res <= 0)
            fprintf(fout, "%s\n", "INSOMNIA");
        else
            fprintf(fout, "%lld\n", res);
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
