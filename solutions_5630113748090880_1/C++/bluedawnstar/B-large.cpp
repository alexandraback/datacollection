#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long I64;
typedef unsigned long long U64;

int gN;
unordered_map<int,int> gM;

int main(int argc, char* argv[]) {
    FILE* fin = fopen(argv[1], "rt");
    FILE* fout = fopen(argv[2], "wt");

    int T;

    fscanf(fin, "%d", &T);
    for (int tn = 1; tn <= T; tn++) {
        gM.clear();

        fscanf(fin, "%d", &gN);
        for (int i = 0; i < 2 * gN - 1; i++) {
            for (int j = 0; j < gN; j++) {
                int x;
                fscanf(fin, "%d", &x);
                gM[x]++;
            }
        }

        vector<int> v;
        v.reserve(gN);

        for (auto it = gM.begin(); it != gM.end(); ++it) {
            if ((it->second & 1) == 1)
                v.insert(v.end(), it->first);
        }
        sort(v.begin(), v.end());

        fprintf(fout, "Case #%d:", tn);
        for (auto it = v.begin(); it != v.end(); ++it) {
            fprintf(fout, " %d", *it);
        }
        fprintf(fout, "\n");
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
