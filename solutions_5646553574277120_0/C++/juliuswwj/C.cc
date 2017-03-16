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
    
int C, D, V;
int cv[110];
int v[10000];

void doset(int nv)
{
    for(int i=1; i<=C; i++){
        for(int p=V; p>=0; p--){
            if(v[p] && p+ nv*i <=V)v[p+ nv*i]=1;
        }
    }
}
    
int q()
{
    RIII(C, D, V);
    for(int i=0; i<D; i++)RI(cv[i]);
    
    for(int i=0; i<=V; i++)v[i] = 0;
    v[0] = 1;
    for(int k=0; k<D; k++)doset(cv[k]);
    
    int ret = 0;
    while(1){
        int nd = -1;
        //fprintf(stderr, "[");
        for(int i=0; i<=V; i++){
            //fprintf(stderr, "%d", v[i]);
            if(!v[i]){
                nd = i;
                break;
            }
        }
        //fprintf(stderr, "]\n");
        if(nd == -1)return ret;
        //fprintf(stderr, "%d %d\n", V, nd);
        ret++;
        doset(nd);
    }  
}

int main(){
    CASET {
        printf("Case #%d: %d\n", case_n++, q());
    }
    return 0;
}