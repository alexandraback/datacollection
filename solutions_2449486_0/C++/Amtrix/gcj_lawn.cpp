#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>
using namespace std;

const int maxn = 100 + 55;

int h,w;
int mat[maxn][maxn];

int main() {
    freopen("Ulaz.txt","r",stdin);
    freopen("Izlaz.txt","w",stdout);
    int tests; scanf("%d",&tests);
    for (int t = 1; t <= tests; ++t) {
        scanf("%d%d",&h,&w);
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j)
                scanf("%d",&mat[i][j]);
        }


        bool sol = true;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                bool hok = 1,wok = 1;
                int cut = mat[i][j];
                for (int k = 0; k < h && hok; ++k) hok = mat[k][j] <= cut;
                for (int k = 0; k < w && wok; ++k) wok = mat[i][k] <= cut;

                bool ok = hok || wok;
                if (!ok) sol = false;
            }
        }

        if (sol) printf("Case #%d: YES\n",t);
        else printf("Case #%d: NO\n",t);
    }
    return 0;
}
