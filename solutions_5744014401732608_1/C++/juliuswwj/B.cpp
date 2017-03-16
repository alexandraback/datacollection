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

typedef long long int ll;


int e[55][55];
int B;
ll M;
ll  c[55];

ll count()
{
    
    memset(c, 0, sizeof(c));
    
    int n = B-1;
    c[ n ] = 1;
    while(n > 0){
        n--;
        for(int i=n+1; i<=B-1; i++)if(e[n][i])c[n]+=c[i];
    }
    return c[0];
}

void p(){
    printf("POSSIBLE\n");
    for(int a=0; a<B; a++){
        for(int b=0; b<B; b++){
            printf("%d", e[a][b]);
        }
        printf("\n");
    }
}

void q(){
    RI(B);
    scanf("%lld", &M);
    
    ll m = M;
    
    memset(e, 0, sizeof(e));
    if(M == 0){
        p();
        return;
    }
    ll v = 1;
    for(int i=0; i<B-1; i++)v*=2;
    v /= 2;
    M -= 1;
    
    for(int i=1; i<B-1; i++){
        for(int j=i+1; j<B; j++)e[i][j] = 1;
    }
    
    if(M>=v){
        printf("IMPOSSIBLE\n");
        return;
    }
    int k = 0;
    while(v>=1){
        v/=2;
        k++;
        
        if(M>=v){
            e[0][k] = 1;
            M -= v;
        }
    }
    //printf("%lld %lld\n", m, count());
    p();
}
    

int main(){
    CASET {
        printf("Case #%d: ", case_n++);
        q();
        fflush(stdout);
    }
    return 0;
}

