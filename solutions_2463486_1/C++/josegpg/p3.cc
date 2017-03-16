#include<stdio.h>
#include<string.h>
#include<cmath>
#include <stdlib.h>

char K[10002];
int flag;
int T;
long long A, B;
long long A2, B2, palin;
char cuadrado[10002];

void find_palin() {
    int len,i,tmp,t,tmp1;
    len = strlen(K);
    flag = 1;
    for(i=0; i<len; i++) {
        if(K[i] != '9') {
            flag = 0;
            break;
        }
    }
    if(flag == 1) {
        K[0] = '1';
        for(i=1; i<len; i++)
            K[i] = '0';
        K[len] = '1';
        K[len+1] = '\0';
        return ;
    }
    flag = 0;
    for(i=0; i<len/2; i++) {
        if(K[i] < K[len-i-1])
            flag = -1;
        else if(K[i] > K[len-i-1])
            flag = 1;
        K[len-i-1] = K[i];
    }
    if(flag == -1 || flag==0) {
        t = 0;
        if(len%2 == 0)
            tmp1 = len/2-1;
        else
            tmp1 = len/2;
            while(K[tmp1-t] == '9') {
                K[tmp1-t] = '0';
                K[len-1-tmp1+t] = '0';
                t ++;
            }
            K[tmp1-t] ++;
            K[len-1-tmp1+t] = K[tmp1-t];
    }
    return ;
}

bool palindromo() {
    int l = strlen(cuadrado);
    int mitad = l / 2;
    bool es = true;
    for (int i = 0; i < mitad; i++) {
        if (cuadrado[i] != cuadrado[l-1-i]) {
            es = false;
            break;
        }
    }
    return es;
}

int main() {
    int i,l,j,small,flag, cant;
    scanf("%d",&T);
    for(int caso = 1; caso <= T; caso++) {
        cant = 0;
        scanf("%lld %lld", &A, &B);
        A2 = sqrt(A);
        sprintf(cuadrado, "%lld", A2*A2);
        if (A2*A2 == A && palindromo()) cant++;
        palin = A2;
        B2 = sqrt(B);
        //printf("B2 quedo %lld\n", B2);
        sprintf(K, "%lld", A2);
        //printf("asi comenzo %s\n", K);
        while (palin <= B2) {
            //printf("palin es %lld y B2 %lld\n", palin, B2);
            find_palin();
            sscanf(K, "%lld", &palin);
            if (palin > B2) break;
            sprintf(cuadrado, "%lld", palin*palin);
            //printf("%s\n", cuadrado);
            //return 0;
            if (palindromo()) {
                cant++;
                //puts(cuadrado);
            }
        }
        printf("Case #%d: %d\n", caso, cant);
    }
    return 0;
}
