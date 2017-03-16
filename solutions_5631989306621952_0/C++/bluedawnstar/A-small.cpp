#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long I64;
typedef unsigned long long U64;

char gS[1002];

int main(int argc, char* argv[]) {
    FILE* fin = fopen(argv[1], "rt");
    FILE* fout = fopen(argv[2], "wt");

    int T;

    fscanf(fin, "%d", &T);
    for (int tn = 1; tn <= T; tn++) {
        fscanf(fin, "%s", gS);

        string s;
        s += gS[0];
        for (int i = 1; gS[i]; i++) {
            if (s[0] <= gS[i])
                s.insert(0, 1, gS[i]);
            else
                s += gS[i];
        }

        fprintf(fout, "Case #%d: %s\n", tn, s.c_str());
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
