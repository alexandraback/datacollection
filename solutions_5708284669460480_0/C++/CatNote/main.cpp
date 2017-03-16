#include<stdio.h>
#include<string.h>
char Keyboard[110];
char Target[110];
char Typed[110];
double Success, All;
int K, L, S, max;
void Typing(int t){
    int i, j, cnt=0;
    if(t>S){
        for(i=1; i+L-1<=S; i++){
            for(j=0; j<L; j++) if(Typed[i+j]!=Target[j]) break;
            if(j==L) cnt++;
        }
        Success+=cnt;
        All++;
        if(max<cnt) max=cnt;
        return;
    }
    for(i=0; i<K; i++){
        Typed[t]=Keyboard[i];
        Typing(t+1);
    }
}
int main(){
    int T, i;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        All=Success=max=0;
        scanf("%d %d %d", &K, &L, &S);
        scanf("%s %s", Keyboard, Target);
        Typing(1);
        printf("Case #%d: %lf\n", i, max-Success/All);
    }
    return 0;
}
