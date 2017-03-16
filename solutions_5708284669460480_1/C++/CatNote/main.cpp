#include<stdio.h>
#include<algorithm>
int Coin[7];
int main(){
    int T, C, D, V, i, j, sum, cnt;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        sum=cnt=0;
        scanf("%d %d %d", &C, &D, &V);
        for(j=1; j<=D; j++) scanf("%d", &Coin[j]);
        std::sort(Coin+1, Coin+D+1);
        Coin[D+1]=V+1;
        for(j=1; j<=D+1; j++){
            if(sum>=V) break;
            while(sum+1<Coin[j]){
                sum+=sum+1;
                cnt++;
            }
            sum+=Coin[j];
        }
        printf("Case #%d: %d\n", i, cnt);
    }
    return 0;
}
