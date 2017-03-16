#include <cstdio>
#include <algorithm>

using namespace std;

int E, R, N;
int cache[2][10000005];
int items[1000];

//int dp(int energy, int items) {
//    if(energy < 0) {
//        return -1;
//    }
//    
//    if(energy > E) {
//        energy = E;
//    }
//    
//    if(cache[energy][items] == -1) {
//        cache[energy][items] = 0;
//        
//        for(int i = max(0, energy - R); i <= E; i++) {
//            
//        }
//    }
//    
//    return cache[energy][items];
//}

int main() {
    freopen("energy.txt", "r", stdin);

    int T;
    scanf("%d", &T);

    for (int c = 0; c < T; c++) {
        scanf("%d %d %d", &E, &R, &N);

        for (int i = 0; i < N; i++) {
            scanf("%d", &items[i]);
        }

        for (int i = 0; i <= E; i++) {
            cache[0][i] = (E - i) * items[0];
        }

//        for (int j = 0; j <= E; j++) {
//            for (int i = 0; i < 2; i++) {
//                printf("%2d ", cache[i][j]);
//            }
//            printf("\n");
//        }
//        printf("\n");

        int cur = 1, last = 0;
        for (int i = 1; i < N; i++) {
            for (int j = 0; j <= E; j++) {
                cache[cur][j] = 0;
                for (int k = max(0, j - R); k <= E; k++) {
                    cache[cur][j] = max(cache[cur][j], cache[last][k] + ((min(k + R, E) - j) * items[i]));
                }
            }

            cur = (cur + 1) % 2;
            last = (last + 1) % 2;
        }

        //int best = -1;
        //for (int i = 0; i < E + 1; i++) {
        //    best = max(best, cache[i][N - 1]);
        //}

        //printf("Case #%d: %d\n", c + 1, best);

        int best = 0;
        for (int j = 0; j <= E; j++) {
            best = max(best, cache[last][j]);
//            printf("%2d ", cache[last][j]);
//            printf("\n");
        }
        
        printf("Case #%d: %d\n", c + 1, best);
    }

    return 0;
}

