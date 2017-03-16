#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 20
#define MAXS 100000
#define MAXR (MAXN*MAXS+10)

int N;
int tab[MAXN+1][MAXR*2+10];
int S[MAXN];

int main() {
    int T;
    scanf("%d", &T);
    for (int caseno = 1; caseno <= T; caseno++) {
        scanf("%d", &N);
        for (int i = 0; i < N; i++) scanf("%d", &S[i]);
        for (int u = 0; u < MAXR*2; u++) tab[0][u] = 0;
        for (int i = 0; i < N; i++) {
            for (int u = -MAXR; u <= MAXR; u++) {
                tab[i+1][u+MAXR] = tab[i][u+MAXR];
            }
            for (int u = -MAXR; u <= MAXR; u++) {
                if (u == 0 || tab[i][u+MAXR] != 0) {
                    int lu = u - S[i], hu = u + S[i];
                    if (lu >= -MAXR && !tab[i][lu+MAXR]) tab[i+1][lu+MAXR] = -(i+1);//, fprintf(stderr, "tab[%d][%d]=%d\n", i+1, lu, -(i+1));
                    if (hu <=  MAXR && !tab[i][hu+MAXR]) tab[i+1][hu+MAXR] =  (i+1);//, fprintf(stderr, "tab[%d][%d]=%d\n", i+1, hu,  (i+1));
                }
            }
        }
        printf("Case #%d:\n", caseno);
        if (!tab[N][0+MAXR]) {
            printf("Impossible.\n");
            continue;
        }
        vector<int> SA, SB;
        int cursor = 0;
        int el = N;
        while (1) {
//            fprintf(stderr, "[el=%d S=%d cursor=%d]\n", el, S[el-1], cursor);
            el = tab[el][cursor+MAXR];
            if (el > 0) {
                cursor -= S[el-1];
                SA.push_back(S[el-1]);
            }
            else {
                el = -el;
                cursor += S[el-1];
                SB.push_back(S[el-1]);
            }
            el--;
//            fprintf(stderr, "[next el=%d cursor=%d]\n", el, cursor);
            if (cursor == 0) break;
        }
        for (unsigned i = 0; i < SA.size(); i++) printf("%d%c", SA[i], i+1==SA.size()?'\n':' ');
        for (unsigned i = 0; i < SB.size(); i++) printf("%d%c", SB[i], i+1==SB.size()?'\n':' ');
    }
    return 0;
}
