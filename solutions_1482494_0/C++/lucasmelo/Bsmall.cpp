#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct Case {
    int val, ind;
    bool operator<(const Case &c) const {
        return val < c.val;
    }
};

Case a[10], b[10], c[10];
bool u[10];

int main() {
    int T, N, numused, starnum;
    bool solved;
    scanf("%d", &T);
    for(int casenum=1; casenum<=T; casenum++){
        scanf("%d", &N);
        for(int i=0; i<N; i++){
            int av, bv;
            scanf("%d%d", &av, &bv);
            a[i].val = av; a[i].ind = i;
            b[i].val = bv; b[i].ind = i;
        }
        sort(b, b+N);
        int mn = -1;
        for(int i=0; i < (1 << N); i++) {
            int len = __builtin_popcount(i);
            for(int j=0,pos=0; j<N; j++)
                if (i & (1 << j))
                    c[pos++] = a[j];
            sort(c, c+len);
            int k=0, m=0, starnum=0;
            memset(u, false, sizeof(u));
            while (k < N || m < len) {
                if (k == N || m < len && c[m].val < b[k].val) {
                    if (c[m].val > starnum) break;
                    if (!u[c[m].ind]) starnum ++;
                    u[c[m].ind] = true;
                    m ++;
                } else {
                    if (b[k].val > starnum) break;

                    if (u[b[k].ind]) starnum += 1;
                    else starnum += 2;
                    u[b[k].ind] = true;
                    k ++;
                }
            }
            if (k == N && m == len) {
                if (mn == -1 || mn > len+N) mn = len+N;
            }
        }

        printf("Case #%d: ", casenum);
        if (mn == -1) {
            printf("Too Bad\n");
        }
        else printf("%d\n", mn);
    }
    return 0;
}
