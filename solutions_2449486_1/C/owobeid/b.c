#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int t,T;
    int N,M,n,m,i,j,c,r;
    int field[101][101];
    int flag;

    scanf("%d",&T);
    
    for (t=0;t<T;t++){
        //printf("t=%d\n",t);
        flag = 0;
        
        scanf("%d %d",&N,&M);
       // printf("N=%d  M=%d\n",N,M);
        
        for (n=0;n<N;n++)
            for (m=0;m<M;m++)
                scanf("%d",&(field[n][m]));
        
        /*
        for (n=0;n<N;n++) {
            for (m=0;m<M;m++)
                printf("%d ",field[n][m]);
            printf ("\n");
        }
        printf("\n");
        */
        
        if (N == 1 || M == 1);
        else {
            for (n = 0; n < N; n++) {
                if (flag) break;
                for (m = 0; m < M; m++) {
                    c = r = 1;
                    for(i=0;i<M;i++) {
                        if (field[n][i] > field[n][m])
                            r = 0;
                    }
                    for(i=0;i<N;i++) {
                        if (field[i][m] > field[n][m])
                            c = 0;
                    }
                    
                    if (!c && !r){
                        flag = 1;
                        break;
                    }
                }
            }
        }
        
        if (flag)
            printf("Case #%d: NO\n",t+1);
        else
            printf("Case #%d: YES\n",t+1);
    } 
}
