#include <stdio.h>

int mark[1005];
int cnt[15];
char word[][15] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};

int main(){
    int T;
    scanf("%d", &T);
    for(int test=1; test<=T; test++){
        for(int i='A'; i<='Z'; i++) mark[i] = 0;
        for(int i=0; i<=9; i++) cnt[i] = 0;
        char s[2005];
        scanf("%s", s);
        for(int i=0; s[i]; i++) mark[s[i]]++;
        cnt[0] = mark['Z'];
        for(int i=0; word[0][i]; i++) mark[word[0][i]] -= cnt[0];
        cnt[4] = mark['U'];
        for(int i=0; word[4][i]; i++) mark[word[4][i]] -= cnt[4];
        cnt[6] = mark['X'];
        for(int i=0; word[6][i]; i++) mark[word[6][i]] -= cnt[6];
        cnt[5] = mark['F'];
        for(int i=0; word[5][i]; i++) mark[word[5][i]] -= cnt[5];
        cnt[7] = mark['V'];
        for(int i=0; word[7][i]; i++) mark[word[7][i]] -= cnt[7];
        cnt[2] = mark['W'];
        for(int i=0; word[2][i]; i++) mark[word[2][i]] -= cnt[2];
        cnt[8] = mark['G'];
        for(int i=0; word[8][i]; i++) mark[word[8][i]] -= cnt[8];
        cnt[3] = mark['R'];
        for(int i=0; word[3][i]; i++) mark[word[3][i]] -= cnt[3];
        cnt[1] = mark['O'];
        for(int i=1; word[1][i]; i++) mark[word[1][i]] -= cnt[1];
        cnt[9] = mark['N']/2;
        for(int i=0; word[9][i]; i++) mark[word[9][i]] -= cnt[9];
        printf("Case #%d: ", test);
        for(int i=0; i<=9; i++){
            for(int j=0; j<cnt[i]; j++) printf("%d", i);
        }
        printf("\n");
    }
}