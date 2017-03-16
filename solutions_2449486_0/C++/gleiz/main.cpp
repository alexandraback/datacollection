#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int stat[128][128] = {{0}};
int lawn[128][128] = {{0}};

void calc_r(int row, int cols){
    int _max = -1;
    for (int i = 0; i<cols; i++){
        if (lawn[row][i] > _max)
            _max = lawn[row][i];
    }

    for (int i = 0; i<cols; i++){
        if (lawn[row][i] == _max){
            stat[row][i] = 1;
        }
    }
    return;
}

void calc_c(int col, int rows){
    int _max = -1;
    for (int i = 0; i<rows; i++){
        if (lawn[i][col] > _max)
            _max = lawn[i][col];
    }

    for (int i = 0; i<rows; i++){
        if (lawn[i][col] == _max){
            stat[i][col] = 1;
        }
    }
    return;
}

int main()
{
    int T = 0;
    int N = 0, M = 0;
    scanf("%d", &T);

    for (int cas = 1; cas <= T; cas++){
        scanf("%d %d", &N, &M);
        memset(stat, 0, sizeof(stat));

        for (int i = 0; i<N; i++){
            for (int j = 0; j<M; j++){
                scanf("%d", &lawn[i][j]);
            }
        }

        for (int i = 0; i<N; i++){
            calc_r(i, M);
        }

        for (int i = 0; i<M; i++){
            calc_c(i, N);
        }

        int able = 1;
        for (int i = 0; i<N; i++){
            for (int j = 0; j<M && able; j++){
                if (stat[i][j] == 0){
                    able = 0;
                    break;
                }
            }
        }

        if (able == 0){
            printf("Case #%d: NO\n", cas);
        }else{
            printf("Case #%d: YES\n", cas);
        }
    }
    return 0;
}
