#include <iostream>
#include <algorithm>

using namespace std;
int b[100][100], h, w;

int main() {
    int i, j, k, p, tn = 0;
    scanf("%*d");
    while (2 == scanf("%d %d", &h, &w)) {
        tn++;
        for (i = 0; i < h; i++) {
            for (j = 0; j < w; j++) scanf("%d", &b[i][j]);
        }

        for (i = 0; i < h; i++) {
            for (j = 0; j < w; j++) {
                int t = b[i][j];

                bool f = false;
                for (k = 0; k < w; k++) if (b[i][k] > t) break;
                if (k == w) f = true;
                else
                {
                    for (k = 0; k < h; k++) if (b[k][j] > t) break;
                    if (k == h) f = true;
                }
                if (!f) goto IMP;
            }
        }

        printf("Case #%d: YES\n", tn);
        continue;
IMP:
        printf("Case #%d: NO\n", tn);
    }
    return 0;
}