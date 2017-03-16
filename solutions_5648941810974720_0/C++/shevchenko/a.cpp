#include<stdio.h>
#include<string.h>

int L;
char S[2001];
char NUMBERS[10][10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int order[10][2] = {{0, 0}, {6, 2}, {8, 2}, {7, 0}, {5, 2}, {4, 0}, {3, 2}, {2, 1}, {1, 0}, {9, 1}};

void process(){
    int count[26]={0,},i,j,anscnt[10];
    for(i=0;i<L;i++) count[S[i]-'A']++;
    for(i=0;i<10;i++){
        int x = order[i][0], y = order[i][1];
        anscnt[x] = count[NUMBERS[x][y]-'A'];
        for(j=strlen(NUMBERS[x])-1;j>=0;j--){
            count[NUMBERS[x][j]-'A']-=anscnt[x];
        }
    }
    int check=0;
    for(i=0;i<26;i++) check+=count[i];
    if(check!=0){
        printf("FUCKED! ");
    }
    for(i=0;i<10;i++){
        for(j=0;j<anscnt[i];j++) printf("%d",i);
    }
    printf("\n");
}

int main(){
    int T, t;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%s",S);
        L = strlen(S);
        printf("Case #%d: ", t);
        process();
    }
    return 0;
}
