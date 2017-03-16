#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


float max(float a, float b){
 
    return(a > b) ? a : b;
    
}


void main(){


    int T, N, i, j, X, x, menor, z, n;
    double Y,v;
    
    fscanf(stdin, "%d", &T);
    
    for(i = 1; i <= T; i++){
  
        
        fscanf(stdin, "%d", &N);
        
        int * pontos = (int *) malloc(N * sizeof(int));
        
        z = 0;
        X = 0;
        menor = 200;
        for(j = 0; j < N; j++){

            fscanf(stdin, "%d", &pontos[j]);
            X += pontos[j];
            menor = (pontos[j] < menor) ? pontos[j] : menor;
        }
        x = X*2;
        
//         printf("z: %d\n", z);
        printf("Case #%d:", i);
        
        n = (double)X/((double)N/2);
//         printf("n: %d\n", n);
        for(j = 0; j < N; j++){
            
            if(pontos[j] >= n){
                z++;
                x -= pontos[j];
            }
            
        }
        z = (z == 0) ? N : N-z;
        
        for(j = 0; j < N; j++){
            //             v = max((double)X/((double)n/2), pontos[j]);
            if(pontos[j] >= n){
                v = pontos[j];
            }else{
                v = (double)x/((double)z);
            }
            
            //             Y = 100*(((v) - (double)pontos[j])/(double)X);
            Y = 100*((v - (double)pontos[j])/X);
            printf(" %.6f", Y);
            
        }
        printf("\n");
        
        
        free(pontos);

        
    }


}