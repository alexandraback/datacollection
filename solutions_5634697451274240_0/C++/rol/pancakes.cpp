#include<cstdio>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;

/*
int flip(char *S){
    int lenS = strlen(S);
    for(int i = 0; i < lenS; ++i){
        if(S[i] != '+') goto lbl;
    }
    return 0;
    lbl:
    char pcpy[1 << 7], *Sp = pcpy, mcpy[1 << 7], *Sm = mcpy;
    strcpy(Sp, S); strcpy(Sm, S);
    int p = 0, ml = lenS - 1;
    while(S[p] == '+') ++p;
    while(S[ml] == '+') --ml;
    reverse(Sp, Sp + p);
    for(int i = 0; i < p; ++i) Sp[i] = '-';
    reverse(Sm, Sm + ml + 1);
    for(int i = 0; i <= ml; ++i) Sm[i] = (Sm[i] == '+') ? '-' : '+';
    if(strcmp(S, Sp) == 0) return 1 + flip(Sm);
    if(strcmp(S, Sm) == 0) return 1 + flip(Sp);
    return 1 + min(flip(Sp), flip(Sm));
}
*/

int flip(char *S){
    int lenS = strlen(S);
    for(int i = 0; i < lenS; ++i){
        if(S[i] != '+') goto lbl;
    }
    return 0;
    lbl:
    int p = 0;
    if(S[p] == '+'){
        // We have to flip the p-prefix
        while(S[p] == '+') ++p;
    } else {
        p = lenS;
        while(S[p - 1] == '+') --p;
    }
    reverse(S, S + p);
    for(int i = 0; i < p; ++i) S[i] = (S[i] == '+') ? '-' : '+';
    return 1 + flip(S);
}

int main(){

    int T, C = 1;
    char arr[1 << 7], *S = arr;
    scanf("%d", &T);
    while(T--){
        scanf(" %s", S);
        printf("Case #%d: %d\n", C++, flip(S));
    }

}
