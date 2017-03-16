#include <cstdio>
#include <algorithm>

#define MAX_R 100
#define INF 1000000005
using namespace std;

int T;
int R, C, h[105][105];
int maxC[105], maxR[105];
bool noAns;

int main() {
    freopen ("q2.in", "r", stdin);
    freopen ("q2.out", "w", stdout);
    scanf ("%d", &T);
    for (int tC = 1; tC <= T; tC++) {
        printf ("Case #%d: ", tC);
        scanf ("%d %d", &R, &C);
        noAns = false;
        for (int i = 1; i <= MAX_R; i++) {
            maxC[i] = maxR[i] = 0;
        }
        for (int i = 1; i <= R; i++) {
            for (int p = 1; p <= C; p++) {
                scanf ("%d", &h[i][p]);
                maxC[p] = max (maxC[p], h[i][p]);
                maxR[i] = max (maxR[i], h[i][p]);
            }
        }
        for (int i = 1; i <= R; i++) {
            for (int p = 1; p <= C; p++) {
                if (h[i][p] != maxR[i] && h[i][p] != maxC[p]) {
                    noAns = true;
                }
            }
        }
        if (noAns) printf ("NO\n");
        else printf ("YES\n");
    }
    return 0;
}
        
