#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <map>

using namespace std;

int N, M;
int G[128][128], Cut[128][128];

int main(void){
    int T;
    scanf("%d", &T);
    for (int tc = 0; tc < T; tc ++){
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; i ++)
            for (int j = 0; j < M; j ++) scanf("%d", G[i] + j);
        for (int i = 0; i < N; i ++)
            for (int j = 0; j < M; j ++) Cut[i][j] = 100;
        int found = 1;
        while (found){
            found = 0;
            for (int i = 0; i < N; i ++){
                int maxValue = 0, cutMaxValue = 0;
                for (int j = 0; j < M; j ++){
                    maxValue = max(maxValue, G[i][j]);
                    cutMaxValue = max(cutMaxValue, Cut[i][j]);
                }
                if (cutMaxValue > maxValue){
                    for (int j = 0; j < M; j ++) Cut[i][j] = maxValue;
                    found = 1;
                }
            }

            for (int i = 0; i < M; i ++){
                int maxValue = 0, cutMaxValue = 0;
                for (int j = 0; j < N; j ++){
                    maxValue = max(maxValue, G[j][i]);
                    cutMaxValue = max(cutMaxValue, Cut[j][i]);
                }
                if (cutMaxValue > maxValue){
                    for (int j = 0; j < N; j ++) Cut[j][i] = maxValue;
                    found = 1;
                }
            }
        }

        int valid = 1;
        for (int i = 0; i < N; i ++)
            for (int j = 0; j < M; j ++)
                if (G[i][j] != Cut[i][j]) valid = 0;
        if (valid) printf("Case #%d: YES\n", tc + 1);
        else printf("Case #%d: NO\n", tc + 1);
    }

    return 0;
}
