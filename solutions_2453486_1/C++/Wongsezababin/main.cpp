#include<stdio.h>
#include<stdlib.h>
int checkBingo(int** table){
    int j, k;
    for(j=0;j<4;j++){
        for(k=0;k<4;k++){
            if(table[j][k] == 0) break;
        }
        if(k == 4) return 1;
    }
    for(k=0;k<4;k++){
        for(j=0;j<4;j++){
            if(table[j][k] == 0) break;
        }
        if(j == 4) return 1;
    }
    for(j=0;j<4;j++)
        if(table[j][j] == 0) break;
    if(j == 4) return 1;
    for(j=0;j<4;j++)
        if(table[j][3-j] == 0) break;
    if(j == 4) return 1;
    return 0;
}
int main(){
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T, full, j, k;
    int **tableO, **tableX;
    char alphabet[5];
    tableO = (int **)malloc(4 * sizeof(int *));
    tableX = (int **)malloc(4 * sizeof(int *));
    for(int i=0;i<4;i++){
        tableO[i] = (int *)malloc(4 * sizeof(int));
        tableX[i] = (int *)malloc(4 * sizeof(int));
    }
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        full = 1;
        for(j=0;j<4;j++){
            scanf("%s",alphabet);
            for(k=0;k<4;k++){
                switch(alphabet[k]){
                    case 'O':   tableO[j][k] = 1;
                                tableX[j][k] = 0; break;
                    case 'X':   tableO[j][k] = 0;
                                tableX[j][k] = 1; break;
                    case 'T':   tableO[j][k] = 1;
                                tableX[j][k] = 1; break;
                    case '.':   tableO[j][k] = 0;
                                tableX[j][k] = 0;
                                full = 0;
                    default:    break;
                }
            }
        }
        printf("Case #%d: ", i+1);
        //check O won
        if(checkBingo(tableX))      printf("X won\n");
        //check X won
        else if(checkBingo(tableO)) printf("O won\n");
        //Draw or Game has not completed
        else if(full)               printf("Draw\n");
        else                        printf("Game has not completed\n");
    }
}
