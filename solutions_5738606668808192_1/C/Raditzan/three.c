#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <solve.h>

#define N 16
#define J 50
int bin[N+1];
int divPrime[100000001]={0};
int num=0;

void populatePrimes(){
    int i,j,f;
    divPrime[0]=divPrime[1]=-111111;
    for(i=2;i<=100000000;++i)
        if(!divPrime[i]){
            for(j=i;j<=N;j+=i)
                divPrime[j]=i;
        }
}

int baseChange(int b){
    int i;
    int r=1;
    int sum=0;
    for(i=N;i>=1;--i){
        sum += bin[i]*r;
        r*=b;
    }
    return sum;
}

void recurse(int n){
    if(num>=J)return;
    if(n==N-1){
        int flag=0;
        int i;
        char l[1000];
        char m[100];
        for(i=2;i<=10;++i){
            int c = baseChange(i);
            if(divPrime[c]==c){
                flag=1;
                break;
            }
            sprintf(m,"%d ",divPrime[c]);
            strcat(l,m);
        }
        if(!flag){
            if(solve(bin,l))
                num++;
        }
    }else{
        bin[n]=0;
        recurse(n+1);
        bin[n]=1;
        recurse(n+1);
    }
}

int main(){
    populatePrimes();
    bin[1]=bin[N]=1;
    recurse(2);
    return 0;
}