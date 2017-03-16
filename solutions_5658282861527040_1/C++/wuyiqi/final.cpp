#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
long long f[100][2][2][2];
bool valid(int a, int b, int x, int y, int k, int bita, int bitb, int bitk) {
    if(a == 0 && x > bita) return false;
    if(b == 0 && y > bitb) return false;
    if(k == 0 && (x & y) > bitk) return false;
    return true;
}
int main() {
    int T,ca = 1;
 //   freopen("B-large.in", "r", stdin);
 //   freopen("B-large.out","w",stdout);
    scanf("%d", &T);
    while(T--) {
        int A,B,C;
        scanf("%d%d%d",&A,&B,&C);
        memset(f, 0, sizeof(f));
        f[30][0][0][0] = 1;
        for(int len = 30; len >= 1; len--) {
            int bita = (A >> (len - 1) & 1);
            int bitb = (B >> (len - 1) & 1);
            int bitk = (C >> (len - 1) & 1);
            for(int a = 0; a < 2; a++) {
                for(int b = 0; b < 2; b++) {
                    for(int k = 0; k < 2; k++) if(f[len][a][b][k]){
    //                    printf("f[%d][%d][%d][%d] = %lld\n", len, a, b, k, f[len][a][b][k]);
                        for(int x = 0; x < 2; x++) {
                            for(int y = 0; y < 2; y++) {
                                if(!valid(a, b, x, y, k, bita, bitb, bitk)) continue;
                                int flag = ( (x & y) < bitk );
                                f[len - 1][a | (x < bita)][b | (y < bitb)][k | flag] += f[len][a][b][k];
                            }
                        }
                    }
                }
            }
        }
        long long ret = 0;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 1; j++) {
                for(int k = 0; k < 2; k++) {
                    ret += f[0][i][j][k];
                }
            }
        }
        printf("Case #%d: %lld\n", ca++, f[0][1][1][1]);
    }
}
