#include<stdio.h>
#include<stdlib.h>
int E,R,N;
int v[10002];
int sum(int index, int energy, int total){
    if(index == N) return total;
    int max = 0;
    int dontScore = sum(index+1,energy,total);
    if(max < dontScore)
        max = dontScore;
    for(int i=0;i<=energy;i++){
        int score = i * v[index];
        int newEnergy = energy-i+R;
        if(newEnergy > E) newEnergy = E;
        int doScore = sum(index+1,newEnergy,total+score);
        if(max < doScore)
            max = doScore;
    }
    return max;
}
int main(){
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d%d%d",&E,&R,&N);
        for(int j=0;j<N;j++){
            scanf("%d",&v[j]);
        }
        printf("Case #%d: %d\n",i+1,sum(0,E,0));
    }
}
