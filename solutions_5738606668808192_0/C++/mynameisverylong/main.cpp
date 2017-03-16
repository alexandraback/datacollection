#include <stdio.h>
#include "stdlib.h"

long prime[1500],primenum;
long ans[510][10],an=0;

int primeinit(){
    char p[10000];
    long i,j;
    for (i=0;i<10000;i++){
        p[i]=1;
    }
    primenum=0;
    for (i=2;i<10000;i++){
        if (p[i]){
            prime[primenum]=i;
            primenum++;
            for (j=i;j<10000;j+=i){
                p[j]=0;
            }
        }
    }
    return 0;
}

int tryprime(long x,long k,long p){
    long i,j,t=0,mask=1;
    for (i=0;i<16;i++){
        t+=(x%2)*mask;
        mask*=k;
        x/=2;
    }
    for (j=0;j<primenum;j++){
        if (t%prime[j]==0){
            ans[p][k-1]=prime[j];
            return 1;
        }
    }
    return 0;
}

int output2(long k,long l){
    if (l>1)
        output2(k/2,l-1);
    printf("%ld",k%2);
    return 0;
}

int main() {
    primeinit();
    freopen("small.out", "w", stdout);
    long i,j;
    for (i=(1<<15)+1;an<50;i+=2){
        ans[an][0]=i;
        for (j=2;j<=10; j++) {
            if (!tryprime(i,j,an)){
                break;
            }
        }
        if (j==11)
            an++;
    }
    printf("Case #1:\n");
    for (i=0;i<an;i++){
        output2(ans[i][0],16);
        for (j=1;j<10;j++)
            printf(" %ld",ans[i][j]);
        printf("\n");
    }
    return 0;
}
