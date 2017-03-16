#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long I64;
typedef unsigned long long U64;

int gJ;
int gP;
int gS;
int gK;

unordered_map<int,int> gJP;
unordered_map<int,int> gJS;
unordered_map<int,int> gPS;

vector<int> gV(3, 0);
vector<vector<int>> gR;
vector<vector<int>> gT;

void solve(int j, int p, int s) {
    if (j >= gJ || p >= gP || s >= gS) {
        if (gR.size() < gT.size())
            gR = gT;
        return;
    }

    int jp = j * 100 + p;
    int js = j * 100 + s;
    int ps = p * 100 + s;
    if (gJP[jp] >= gK || gJS[js] >= gK || gPS[ps] >= gK) {
        if (gR.size() < gT.size())
            gR = gT;
        solve(j + 1, p    , s    );
        solve(j    , p + 1, s    );
        solve(j    , p    , s + 1);
    } else {
        ++gJP[jp];
        ++gJS[js];
        ++gPS[ps];
        gV[0] = j + 1;
        gV[1] = p + 1;
        gV[2] = s + 1;
        gT.push_back(gV);

        solve(j + 1, p    , s    );
        solve(j    , p + 1, s    );
        solve(j    , p    , s + 1);

        --gJP[jp];
        --gJS[js];
        --gPS[ps];
        gT.pop_back();
    }
}

int main(int argc, char* argv[]) {
    FILE* fin = fopen(argv[1], "rt");
    FILE* fout = fopen(argv[2], "wt");

    int T;

    fscanf(fin, "%d", &T);
    for (int tn = 1; tn <= T; tn++) {
        fscanf(fin, "%d %d %d %d", &gJ, &gP, &gS, &gK);

        gJP.clear();
        gJS.clear();
        gPS.clear();
        gR.clear();
        gT.clear();
        solve(0, 0, 0);

        fprintf(fout, "Case #%d: %d\n", tn, gR.size());
        for (int i = 0; i < gR.size(); i++) {
            fprintf(fout, "%d %d %d\n", gR[i][0], gR[i][1], gR[i][2]);
        }
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
