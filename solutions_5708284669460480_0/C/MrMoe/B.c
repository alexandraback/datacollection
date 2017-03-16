#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int TOTAL = 0;
int BANANAS = 0;
int MAXPOSSIBLE = 0;


void countBananas(char * text, int Ntext, char * target, int Ntarget) {
    int bananas = 0;
    int i;
    for (i=0; i<=Ntext-Ntarget; i++) {
        if (strncmp(text+i, target, Ntarget) == 0) {
            bananas++;
        }
    }
    //printf("bananas: %d\n", bananas);
    
    TOTAL++;
    BANANAS += bananas;
    if (bananas > MAXPOSSIBLE) {
        MAXPOSSIBLE = bananas;
    }
}



void fill(char * letters, int Nletters, char * text, int C, int Ntext, char * target, int Ntarget) {
    if (C == Ntext)
        return;
    int l;
    for (l=0; l<Nletters; l++) {
        text[C] = letters[l];
        if (C+1 == Ntext) {
            //printf("-%s\n", text);
            countBananas(text, Ntext, target, Ntarget);
        } else {
            fill(letters, Nletters, text, C+1, Ntext, target, Ntarget);
        }
    }
}


int main() {
    int T;
    scanf("%d", &T);
    
    int t;
    for (t=0; t<T; t++) {
        TOTAL = 0;
        BANANAS = 0;
        MAXPOSSIBLE = 0;
        
        int K, L, S;
        scanf("%d %d %d", &K, &L, &S);
        char letters[K+1];
        scanf("%s", letters);
        char target[L+1];
        scanf("%s", target);
        
        char text[S+1];
        text[S] = 0;
        fill(letters, K, text, 0, S, target, L);
        
        printf("Case #%d: %1.7f\n", t+1, (double)MAXPOSSIBLE - (double)BANANAS/(double)TOTAL);
    }
    
    return 0;
}


