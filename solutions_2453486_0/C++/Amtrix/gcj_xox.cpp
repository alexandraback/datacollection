#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
using namespace std;

const int maxn = 10;

char mat[maxn][maxn];

bool hasfour(char c) {
    for (int i =0 ; i < 4; ++i) {
        bool ok = true;
        for (int j = 0; j < 4; ++j)
            if (mat[i][j] != c && mat[i][j] != 'T') ok = false;
        if (ok) return ok;
        ok = true;
        for (int j = 0; j < 4; ++j)
            if (mat[j][i] != c && mat[j][i] != 'T') ok = false;
        if (ok) return ok;
    }
    bool d1ok = true, d2ok = true;
    for (int i = 0; i < 4; ++i) {
        if (mat[i][i] != c && mat[i][i] != 'T') d1ok = false;
        if (mat[i][3-i] != c && mat[i][3-i] != 'T') d2ok = false;
    }
    return d1ok || d2ok;
}

int main() {
    freopen("Ulaz.txt","r",stdin);
    freopen("Izlaz.txt","w",stdout);
    int tests; scanf("%d",&tests);
    for (int t = 1; t <= tests; ++t) {
        bool more = false;
        for (int i = 0; i < 4; ++i) {
            scanf("%s",mat[i]);
            for (int j = 0; j < 4; ++j)
                if(mat[i][j] == '.') more = true;
        }

        printf("Case #%d: ",t);
        if (hasfour('X')) printf("X won\n");
        else if (hasfour('O')) printf("O won\n");
        else if (more) printf("Game has not completed\n");
        else printf("Draw\n");

    }
    return 0;
}
