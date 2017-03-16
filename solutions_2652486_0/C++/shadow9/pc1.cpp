#include<cstdio>
#include<cstring>

int R, N, M, K;
int nn[3];
bool appear[100][140];

void DFS(int s, int p, int now){
    if(now == 4){
        appear[s][p] = true;
        return;
    }
    DFS(s, p, now+1);
    DFS(s, p*nn[now], now+1);
}

int main(){
    for(int i = 0; i < 64; i++){
        int tmp = i;
        for(int j = 0; j < 3; j++){
            nn[j] = (tmp%4)+2;
            tmp /= 4;
        }
        DFS(i, 1, 0);
    }
    scanf("%*d");
    scanf("%d%d%d%d", &R, &N, &M, &K);
    printf("Case #1:\n");
    while(R--){
        int p[10];
        for(int i = 0; i < K; i++){
            scanf("%d", &p[i]);
        }
        for(int i = 0; i < 64; i++){
            bool ac = true;
            for(int j = 0; j < K && ac; j++){
                if(appear[i][p[j]] == false) ac = false;
            }
            if(ac){
                for(int j = 0; j < N; j++){
                    printf("%d", (i%4)+2);
                    i /= 4;
                }
                printf("\n");
                break;
            }
        }
    }
    return 0;
}
