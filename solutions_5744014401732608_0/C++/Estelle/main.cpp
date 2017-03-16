//
//  main.cpp
//  1C_B
//
//  Created by Estelle :) on 08/05/2016.
//  Copyright © 2016 Estelle :). All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);
    for (int k=1; k<=T; k++) {
        printf("Case #%d:", k);
        int B;
        long long int M;
        scanf("%d%lld", &B, &M);
        int mat[B][B];
        bool fnd=false;
        for (int i=1; i<(1<<(B*(B-1)/2)); i++) {
            int p=0;
            memset(mat,0,sizeof(mat));
            int ways[B];
            memset(ways,0,sizeof(ways));
            ways[0]=1;
            for (int j=0; j<B; j++) {
                for (int m=j+1; m<B; m++) {
                    if (1<<p & i) {
                        mat[j][m]=1;
                    }
                    p++;
                }
            }
            for (int j=1; j<B; j++) {
                for (int m=0; m<j; m++) {
                    if (mat[m][j]==1) ways[j]+=ways[m];
                }
            }
            if (ways[B-1]==M) {
                fnd=true;
                printf(" POSSIBLE\n");
                for (int j=0; j<B; j++) {
                    for (int m=0; m<B; m++) {
                        printf("%d", mat[j][m]);
                    }
                    printf("\n");
                }
                break;
            }
        }
        if (!fnd) printf(" IMPOSSIBLE\n");
    }
}
