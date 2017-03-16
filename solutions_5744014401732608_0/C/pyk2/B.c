#include <stdio.h>

int main(){

    int z, t, b, m, i, j, k;
    int ans[50][50];
    
    scanf("%d", &t);
    for(i=0; i<50; i++){
        for(j=0; j<50; j++){
            ans[i][j] = 0;
        }
    }
    for(z=1; z<=t; z++){
        scanf("%d %d", &b, &m);
        printf("Case #%d: ", z);
        
        if(m>=b){
            printf("IMPOSSIBLE\n");
        }else{
            printf("POSSIBLE\n");
            for(i=0; i<m; i++){
                for(j=0; j<=i; j++){
                    ans[j][b-i-1] = 1;
                }
            }
            for(i=0; i<b; i++){
                for(j=0; j<b; j++){
                    printf("%d", ans[i][j]);
                }
                printf("\n");
            }
        }
        for(i=0; i<b; i++){
            for(j=0; j<b; j++){
                ans[i][j] = 0;
            }
        }
        
    }

    return 0;

}
