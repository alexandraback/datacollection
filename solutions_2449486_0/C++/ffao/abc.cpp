#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int T;

int b[200][200];
int teste;

int main() {
    for (scanf("%d", &T); T; T--) {
        int n,m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &b[i][j]);
            }
        }

        bool ok = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bool line = true, col = true;
                for (int k = 0; k < m; k++) {
                    if (b[i][k] > b[i][j]) line = false;
                }
                for (int k = 0; k < n; k++) {
                    if (b[k][j] > b[i][j]) col = false;
                }

                if (!line && !col) ok = false;
            }   
        }

        printf("Case #%d: %s\n", ++teste, ok?"YES":"NO");
    }
}