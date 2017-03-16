#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX 100

int checkpattern(int lawn[10][10], int n, int m) {
    int i, j;
    for(i = 0; i < n ; i ++ ) {
        for(j = 0; j < m; j ++) {
            if(lawn[i][j] == MAX) continue;
            if(lawn[i][j] == 1){
                int k = 0;
                int her = 1;
                int vet = 1;
                for(k = 0; k < m ; k ++ ) {
                    if(lawn[i][k] == 2) {
                        break;
                    }
                }
                if(k != m) {
                    her = 0;
                    for(k = 0; k < n ; k ++ ) {
                        if(lawn[k][j] == 2) {
                            break;
                        }
                    } 
                    if(k != n) return 0;
                    for(k = 0; k < n; k ++ ) {
                        lawn[k][j] = MAX;
                    }
                }
                else {
                     for(k = 0; k < m; k ++ ) {
                        lawn[i][k] = MAX;
                    }
                }
            
            }
        }
    }
    return 1;
}



int main() {
    char* filename = "test.in";
    int numCase =0;
    
    FILE* fin = fopen(filename, "r");
    fscanf(fin, "%d\n", &numCase);

    int i,j,k;
    int lawn[10][10];
    for(i = 0; i < numCase; i ++ ) {
        int n, m;
        fscanf(fin, "%d %d", &n, &m);

        for(j = 0; j < n; j ++ ) {
            for(k = 0 ; k < m; k ++ ) {
                fscanf(fin, "%d", &lawn[j][k]);
            }
        }
        /*
        for(j = 0; j < n; j ++ ) {
            for(k = 0 ; k < m; k ++ ) {
                printf("%d ", lawn[j][k]);
            }
            printf("\n");
        }*/

        
        int ret = checkpattern(lawn, n, m);
        if(ret == 0) {
            printf("Case #%d: NO\n", i +1);
        }
        else {
            printf("Case #%d: YES\n", i +1);
        }
    }


    return 0;
}
