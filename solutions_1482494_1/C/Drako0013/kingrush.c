#include <stdio.h>
#include <limits.h>

int onestar[1005], twostar[1005];

int seacabaron(int N){
    int i;
    for(i = 0; i < N; i++){
        if(onestar[i] >= 0) { return 0;}
        if(twostar[i] >= 0) { return 0; }
    }
    return 1;
}

int sepuede(int stars, int N){
    int i;
    for(i = 0; i < N; i++){
        if(onestar[i] >= 0)
            if(onestar[i] <= stars) return 1;
        if(twostar[i] >= 0)
            if(twostar[i] <= stars) return 1;
    }
    return 0;
}

int buscados(int stars, int N){
    int i;
    for(i = 0; i < N; i++){
        if(twostar[i] >= 0 && twostar[i] <= stars) return i;
    }
    return -1;
}

int buscaruno(int stars, int N){
    int i, inmax = -1, maxi = 0;
    for(i = 0; i < N;  i++){
        if(onestar[i] <= stars && onestar[i] >= 0){
            if(twostar[i] >= maxi){
                maxi = twostar[i];
                inmax = i;
            }
        }
    }
    return inmax;
}

int main(){
    int i, j, T, N, stars, sol, vale, aux;
    scanf("%d",&T);
    for(i = 1; i <= T; i++){
        stars = 0, sol = 0, vale = 1;
        scanf("%d",&N);
        for(j = 0; j < N; j++){
            scanf("%d",&onestar[j]);
            scanf("%d",&twostar[j]);
        }   
        while(1){
            if(seacabaron(N)) { break; } 
            if(sepuede(stars, N)){
                aux = buscados(stars, N);
                if(aux >= 0){
                    if(onestar[aux] < 0){
                        stars++;
                    } else {
                        stars += 2;
                    }
                    onestar[aux] = -1;
                    twostar[aux] = -1;
                } else {
                    aux = buscaruno(stars, N);
                    stars++;
                    onestar[aux] = -1;
                }
                sol++;
            } else {
                vale = 0;
                printf("Case #%d: Too Bad\n",i);
                break;
            }
        }
        
        if(vale)
            printf("Case #%d: %d\n",i,sol);
    }
    return 0;
}
