#include<stdio.h>

int judge[210];

double binary_search(int idx,int N,double suma){
    int j;
    double ini=0,fin=1;
    for(int i=0;i<50;i++){
        double med=(ini+fin)/2;
        double rest=1.0-med;
        double guy=judge[idx]+suma*med;
        int ganaste=0;
        for(j=0;j<N;j++){
            if(idx!=j){
                if(guy<judge[j]) continue;
                double needed=(guy-(double)judge[j])/suma;
                rest-=needed;
                if(rest<0) ganaste++;
            }
        }
        if(ganaste)
            fin=med;
        else ini=med;
    }
    return ini*100.0;
}

int main(){
    int T,N;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        double suma=0;
        scanf("%d",&N);
        for(int j=0;j<N;j++){
            scanf("%d",&judge[j]);
            suma+=judge[j];
        }
        printf("Case #%d:",i);
        for(int j=0;j<N;j++)
            printf(" %.6f",binary_search(j,N,suma));
        printf("\n");
    }
    return 0;
}
