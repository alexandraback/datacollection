#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

int T, t, i, j, k, n;
char sa[1000], sb[1000];
char si[1000], sj[1000];

int abs(int a) {
    if (a < 0) return -a;
    return a;
}
int main() {
    scanf("%d", &T);
    for (t = 1; t <= T; t++) {
        printf("Case #%d: ", t);
        scanf("%s%s", sa, sb);
        int len = strlen(sa);
        int bi, bj;
        bi = bj = -1;
        char fmt[111];
        sprintf(fmt, "%%0%dd", len);
        for (i = 0; i < 1000; i++) {
            for (j = 0; j < 1000; j++) {
                sprintf(si, fmt, i);
                sprintf(sj, fmt, j);
                if (strlen(si) != len) continue;
                if (strlen(sj) != len) continue;
                int q;
                for (q = 0; q < len; q++) {
                    if ( (sa[q] == '?' || si[q] == sa[q]) && (sb[q] == '?' || sb[q] == sj[q]) ) continue;
                    break;
                }
                if (q >= len) {
                    if (bi == -1) {
                        bi = i; bj = j;
                    }
                    if ((abs(bi-bj) > (abs(i-j)) || (abs(bi-bj) == abs(i-j) && i < bi) || (abs(bi-bj) == abs(i-j) && bi == i && j < bj))) {
                        bi = i; bj = j;
                    }
                }
            }
        }
        sprintf(si, fmt, bi);
        sprintf(sj, fmt, bj);
        printf("%s %s\n", si, sj);
    }
    return 0;
}
