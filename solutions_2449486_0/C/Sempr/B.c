#include <stdio.h>
#include <string.h>

int v[101][101];
char r[101][101];

int sol(){
    int i, j, N, M, t;
    int top;
    scanf("%d %d", &N, &M);
    memset(r,0,sizeof(r));
    for(i=0;i<N;i++) for (j=0;j<M;j++) scanf("%d", &v[i][j]);
    // row detect
    for (i=0;i<N;i++){
        top = 0;
        for (j=0;j<M;j++){
            t = v[i][j];
            if (t>=top){
                top = t;
                r[i][j] |= 1;
            }
        }
        top = 0;
        for (j=M-1;j>=0;j--){
            t = v[i][j];
            if (t>=top){
                top = t;
                r[i][j] |= 2;
            }
        }
    }
    for (j=0;j<M;j++){
        top = 0;
        for (i=0;i<N;i++){
            t = v[i][j];
            if (t>=top){
                top = t;
                r[i][j] |= 4;
            }
        }
        top = 0;
        for (i=N-1;i>=0;i--){
            t = v[i][j];
            if (t>=top){
                top = t;
                r[i][j] |= 8;
            }
        }
    }
    for (i=0;i<N;i++) for (j=0;j<M;j++){
        t = r[i][j];
        if ((t&12) == 12) continue;
        if ((t&3) == 3) continue;
        return 0;
    }
    return 1;
}

int main(){
    int T, cas;
    scanf("%d", &T);
    for (cas=1; cas<=T; cas++)
        printf("Case #%d: %s\n", cas, sol()?"YES":"NO");
    return 0;
}
