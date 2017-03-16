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
int gV[2000];
vector<int> gC[2000];

bool gVis[2000];

int dfs(int x) {
    int res = 1;
    for (int i = 0; i < gC[x].size(); i++) {
        if (!gVis[gC[x][i]]) {
            gVis[gC[x][i]] = true;
            res = max(res, dfs(gC[x][i]) + 1);
            gVis[gC[x][i]] = false;
        }
    }

    return res;
}

int solve() {
    int res = 0;

    memset(gVis, 0, sizeof(gVis));

    for (int i = 0; i < gN; i++) {
        gVis[i] = true;
        res = max(res, dfs(i));
        gVis[i] = false;
    }

    return res;
}

int main(int argc, char* argv[]) {
    FILE* fin = fopen(argv[1], "rt");
    FILE* fout = fopen(argv[2], "wt");

    int T;

    for (int i = 0; i < sizeof(gC) / sizeof(gC[0]); i++)
        gC[i].reserve(100);

    fscanf(fin, "%d", &T);
    for (int tn = 1; tn <= T; tn++) {
        fscanf(fin, "%d", &gN);

        for (int i = 0; i < gN; i++)
            gC[i].clear();

        for (int i = 0; i < gN; i++) {
            int x;
            fscanf(fin, "%d", &x);
            x--;
            gV[i] = x;
            gC[x].push_back(i);
            gC[i].push_back(x);
        }

        for (int i = 0; i < gN; i++) {
            sort(gC[i].begin(), gC[i].end());
            gC[i].erase(unique(gC[i].begin(), gC[i].end()), gC[i].end());
        }

        fprintf(fout, "Case #%d: %d\n", tn, solve());
    }
    
    fclose(fin);
    fclose(fout);

    return 0;
}
