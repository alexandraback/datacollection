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


int bff[1020];
vector<int> rbff[1020];
int vbf[1020];

int h;
int v[1020];
int next(int n, int pp)
{
    v[n] = 1;
    
    //printf("=> %d\n", n);
    
    int a = 0;
    int k = bff[n];
    if( !v[k] ) {
        vbf[n] = 1;
        a = max(a, next(k, n)+1);
        vbf[n] = 0;
    }
    if(bff[n] == pp || pp == -1){
        for(auto z : rbff[n]){
            if( !v[z] ) a = max(a, next(z, n)+1);
        }
    }
    
    if(a == 0){  // check n & h
        if(!vbf[h] && bff[n] != h){
            a = -1;
        }
        if(bff[n] != h && bff[n] != pp){
            a = -1;
        }
    }
    //if(n == 1 && h == 2){
    //    printf("vbf h = %d bffn = %d a=%d\n", vbf[h], bff[n], a);
    //}
    //printf("<= %d %d\n", n, a);
    
    v[n] = 0;
    
    return a;
}


void q(){
    memset(bff, 0, sizeof(bff));

    DRI(N);

    for(int i=1; i<=N; i++){
        rbff[i].clear();
    }
    
    for(int i=1; i<=N; i++){
        RI(bff[i]);
        rbff[ bff[i] ].push_back( i );
    }
    
    int m = 0;
    for(int i=1; i<=N; i++){
        memset(v, 0, sizeof(v));
        memset(vbf, 0, sizeof(vbf));
        h = i;
        int v = next(i, -1);
        if(v > m) m = v;
    }
    printf("%d\n", m+1);
}
    

int main(){
    CASET {
        printf("Case #%d: ", case_n++);
        q();
        fflush(stdout);
    }
    return 0;
}

