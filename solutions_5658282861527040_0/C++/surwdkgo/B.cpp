#include <stdio.h>
#include <string.h>
long long ans, add;
int v[3], cas, inp[3][32], tmp[3][32], l[3], id[3];
int mul[3][3][3] = {{{1, 0, 1}, {1, 0, 1}, {2, 0, 2}}, {{1, 0, 1}, {0, 1, 1}, {1, 1, 2}}, {{2, 0, 2}, {1, 1, 2}, {3, 1, 4}}};
int main() {
    scanf("%d", &cas);
    for (int ii=0; ii<cas; ii++) {
        scanf("%d%d%d", &v[0], &v[1], &v[2]);
        memset(inp, 0, sizeof(inp));
        for (int i=0; i<3; i++) {
            l[i] = 0;
            while (v[i] > 0){
                inp[i][l[i]] = (v[i] & 1) > 0 ? 1:0;
                v[i] = v[i] >> 1;
                l[i] ++;
            }
        }
        ans = 0;
        for (id[0] = 0; id[0] < l[0]; id[0]++) {
            if (inp[0][id[0]] != 1) continue;
            for (id[1] = 0; id[1] < l[1]; id[1]++) {
                if (inp[1][id[1]] != 1) continue;
                for (id[2] = 0; id[2] < l[2]; id[2]++) {
                    if (inp[2][id[2]] != 1) continue;
                    add = 1;
                    memcpy(tmp, inp, sizeof(tmp));
                    for (int i=0; i<3; i++) {
                        for (int j=0; j<id[i]; j++) tmp[i][j] = 2;
                        tmp[i][id[i]] = 0;
                    }
                    for (int i=0; i<32; i++) add = add * mul[tmp[0][i]][tmp[1][i]][tmp[2][i]];
                    ans += add;
                }
            }
        }
        printf ("Case #%d: %lld\n", ii+1, ans);
    }
    return 0;
}