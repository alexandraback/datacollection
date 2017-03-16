#include<stdio.h>
#include<string.h>

int l;
char S[1001];

void original_order(int s, int t){
    int i;
    for(i=s;i<t;i++) printf("%c",S[i]);
}

void process(int s, int t){
    if(s>=t) return;
    int i, idx = s;
    for(i=s+1;i<t;i++){
        if(S[i] >= S[idx]) idx = i;
    }
    printf("%c", S[idx]);
    process(s, idx);
    original_order(idx+1, t);
}

int main(){
    int T, t;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%s", S);
        printf("Case #%d: ", t);
        l = strlen(S);
        process(0, l);
        printf("\n");
    }
    return 0;
}
