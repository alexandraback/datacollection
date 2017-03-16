#include<cstdio>
#include<cstring>

int table[20][10];
int E, R, N;
int v[20];

int main(){
    int T;
    int cnt = 0;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d", &E, &R, &N);
        for(int i = 0; i < N; i++){
            scanf("%d", &v[i]);
        }
        memset(table, -1, sizeof(table));
        table[0][E] = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j <= E; j++){
                if(table[i][j] >= 0){
                    for(int k = 0; k <= j; k++){
                        int nn = table[i][j] + v[i]*k;
                        int ee = (j-k+R<=E)?(j-k+R):E;
                        if(nn > table[i+1][ee]) table[i+1][ee] = nn;
                    }
                }
            }
        }
        int mmax = 0;
        for(int i = 0; i <= E; i++){
            if(mmax < table[N][i]) mmax = table[N][i];
        }
        printf("Case #%d: %d\n", ++cnt, mmax);
    }
    return 0;
}
