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
    
int K, L, S;
char keys[110];
char tag[110];
char buf[110];

int cnt[110];

void dfs(int s)
{
    if(s == S){
        int c = 0;
        for(int i=0; i<=S-L; i++){
            if(memcmp(&buf[i], tag, L) == 0)c++;
        }
        cnt[c]++;
        buf[s] = 0;
        //fprintf(stderr, "%s\n", buf);
        return;
    }
    for(int i=0; i<K; i++){
        buf[s] = keys[i];
        dfs(s+1);
    }
}

    
double q(){
    RIII(K, L, S);
    RS(keys);
    RS(tag);
    
    memset(cnt, 0, sizeof(cnt));
    dfs(0);
    
    double p = 0;
    double m = 0;
    int mc = 0;
    for(int i=0; i<=S; i++)if(cnt[i]){ m+=cnt[i]; mc = i; }
    for(int i=1; i<=S; i++){
        p += i * cnt[i] / m;
    }
    return mc - p;
}

int main(){
    CASET {
        printf("Case #%d: %lf\n", case_n++, q());
    }
    return 0;
}