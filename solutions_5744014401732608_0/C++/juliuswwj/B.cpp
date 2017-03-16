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


int e[10][10];
int B, M;


int count()
{
    int v[10];
    int p[10];
    int d = 0;
    memset(v, 0, sizeof(v));
    
    v[0] = 1;
    p[d++] = 0;
    p[d] = 1;
    
    int cnt = 0;
    while(true){
        if(p[d] >= B){
            d--;
            if(d<1) break;
            v[ p[d] ] = 0;
            p[d]++;
            continue;
        }
        if(!e[ p[d-1] ][ p[d] ]){
            p[d]++;
            continue;
        }
        if(v[ p[d] ]){
            return -1;
        }
        if(p[d] == B-1){
            cnt++;
            p[d]++;
        } else {
            v[ p[d] ] = 1;
            d++;
            p[d] = 1;
        }
    }
    return cnt;
}


bool ccc(int x, int y)
{
    while(x<B){
        while(y<B){
            y++;
            
            e[x][y] = 0;
            if( ccc(x, y+1) ) return true;
            
            e[x][y] = 1;
            if( ccc(x, y+1) ) return true;
            
        }
        x++;
        y = x;
    }
    
    if(count() == M){
        printf("POSSIBLE\n");
        for(int a=0; a<B; a++){
            for(int b=0; b<B; b++){
                printf("%d", e[a][b]);
            }
            printf("\n");
        }
        return true;
    }
    return false;
}

void q(){
    RII(B, M);
    
    memset(e, 0, sizeof(e));
    if(!ccc(0, 0))
        printf("IMPOSSIBLE\n");
}
    

int main(){
    CASET {
        printf("Case #%d: ", case_n++);
        q();
        fflush(stdout);
    }
    return 0;
}

