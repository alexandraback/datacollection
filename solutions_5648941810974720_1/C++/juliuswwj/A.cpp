#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
#include<list>
#include<queue>
#include<stack>
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
using namespace std;


const char* digits[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int v[26];
int d[10][26];
int ds[26];
char str[3000];

int guess[10];

bool sss(int c, int inc){
    if(inc>0){
        for(int k=0; k<26; k++)if(v[k] < inc * d[c][k]) return false;
    }
    for(int k=0; k<26; k++)v[k] -= inc * d[c][k];
    guess[c] += inc;
    return true;
}

void q(){
    memset(v, 0, sizeof(v));
    memset(str, 0, sizeof(str));
    memset(guess, 0, sizeof(guess));
    RS(str);
    for(int i=0; str[i]; i++){
        v[ str[i] - 'A' ]++;
    }

    for(int c=0; c<10; c++){
        for(int n=0; n<26; n++){
            if(v[n] && ds[n] == 1 && d[c][n] == 1){
                sss(c, v[n]);
            }
        }
    }

    
    vector<int> qq;
    qq.push_back(0);
    int qi = 0;
    while(true){
        bool ok = true;
        for(int n=0; n<26; n++)if(v[n])ok = false;
        if(ok)break;
        
        if(sss(qq[qi], 1)){
            qq.push_back(0);
            qi++;
            continue;
        }
        qq[qi]++;
        if(qq[qi] <= 9)continue;
        qi--;
        if(qi<0)break;
        sss(qq[qi], -1);
        qq[qi]++;
    }
    
    for(int c=0; c<10; c++){
        for(int n=0; n<guess[c]; n++)
            printf("%d", c);
    }
    printf("\n");
}
    

int main(){
    memset(d, 0, sizeof(d));
    memset(ds, 0, sizeof(ds));
    for(int i=0; i<10; i++){
        const char* ps = digits[i];
        while(*ps){
            d[i][ *ps - 'A'] ++;
            ds[*ps - 'A']++;
            ps++;
        }
    }
    
    
    CASET {
        printf("Case #%d: ", case_n++);
        q();
        fflush(stdout);
    }
    return 0;
}

