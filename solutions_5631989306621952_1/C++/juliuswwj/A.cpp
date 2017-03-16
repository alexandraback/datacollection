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

char S[1020];
list<char> R;

void q(){
    RS(S);
    R.clear();
    
    
    for(int i=0; S[i]; i++){
        auto p = R.begin();
        if( p == R.end() ){
            R.insert(p, S[i]);
            continue;
        }
        if(S[i] >= *p)
            R.insert(p, S[i]);
        else
            R.insert(R.end(), S[i]);
    }
    int i = 0;
    for(auto p : R){
        S[i++] = p;
    }
    S[i] = 0;
    printf("%s\n", S);
}
    

int main(){
    CASET {
        printf("Case #%d: ", case_n++);
        q();
        fflush(stdout);
    }
    return 0;
}

