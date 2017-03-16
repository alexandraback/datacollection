#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int T, N, K;
int Valid[1 << 20];
char Process[200], Keys[200][200], KeyNeeded[200], KeyCount[1 << 20][200], KeyUsed[1 << 20][200];

int main(void){
    scanf("%d", &T);
    for (int tc = 0; tc < T; tc ++){
        scanf("%d%d", &K, &N);
        memset(Process, 0, sizeof(Process));
        memset(Keys, 0, sizeof(Keys));
        for (int i = 0; i < K; i ++){
            int x;
            scanf("%d", &x);
            Process[x - 1] ++;
        }
        for (int i = 0; i < N; i ++){
            int count;
            scanf("%d%d", KeyNeeded + i, &count);
            KeyNeeded[i] --;
            for (int j = 0; j < count; j ++){
                int x;
                scanf("%d", &x);
                Keys[i][x - 1] ++;
            }
        }
        memset(KeyUsed, 0, sizeof(KeyUsed));
        for (int i = 0; i < (1 << N); i ++) memcpy(KeyCount[i], Process, sizeof(Process));
        for (int i = 0; i < (1 << N); i ++){
            for (int j = 0; j < N; j ++){
                if ((i >> j) & 1){
                    int ni = i - (1 << j);
                    for (int k = 0; k < 200; k ++){
                        KeyCount[i][k] = KeyCount[ni][k] + Keys[j][k];
                        KeyUsed[i][k] = KeyUsed[ni][k];
                    }
                    KeyUsed[i][KeyNeeded[j]] ++;
                    break;
                }
            }
        }
        memset(Valid, 255, sizeof(Valid));
        Valid[(1 << N) - 1] = 0;
        for (int i = (1 << N) - 1; i >= 0; i --){
            for (int j = 0; j < N; j ++){
                if ((i >> j) & 1) continue;
                int ni = i + (1 << j);
                if (Valid[ni] != -1 && KeyCount[i][KeyNeeded[j]] > KeyUsed[i][KeyNeeded[j]]){
                    Valid[i] = ni;
                    break;
                }
            }
        }
        if (Valid[0] != -1){
            printf("Case #%d:", tc + 1);
            for (int i = 0; i != (1 << N) - 1; i = Valid[i]){
                int ni = Valid[i];
                for (int j = 0; j < N; j ++){
                    if (((ni - i) >> j) & 1){
                        printf(" %d", j + 1);
                        break;
                    }
                }
            }
            printf("\n");
        }  else {
            printf("Case #%d: IMPOSSIBLE\n", tc + 1);
        }
    }
    return 0;
}
