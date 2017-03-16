#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<map>
#include<string>
#include<vector>

using namespace std;

int s[30][30], ln[100], sm;
int N, M, K, i, k;
int mn;

void sset(){
    sm = 0;
    for(int a=0;a<N*M;a++){
        s[a/M][a%M] = ln[a];
        sm += ln[a];
    }
}

int chk(int x, int y){
    int a;
    if(s[x][y] == 1) return 1;
    else {
        for(a=x;a>=0 and s[a][y]==0;a--);
        if(a<0) return 0;
        for(a=x;a<N and s[a][y]==0;a++);
        if(a==N) return 0;
        for(a=y;a>=0 and s[x][a]==0;a--);
        if(a<0) return 0;
        for(a=y;a<M and s[x][a]==0;a++);
        if(a==M) return 0;
        return 1;
    }
}

void calc(){
    i = 0;
    for(int a=0;a<N;a++){
        for(int b=0;b<M;b++){
            i += chk(a, b);
        }
    }
    if(i == k){
        mn = min(mn, sm);
    }
}

void gen(int x){
    if(x == N*M){
        sset();
        calc();
        return;
    }
    ln[x] = 1;
    gen(x+1);
    ln[x] = 0;
    gen(x+1);
}

int main(){
freopen("C-small-attempt0 (1).in", "r", stdin);
freopen("B_out.txt", "w", stdout);
int a, b, c, d;
int R, T;
string S;
cin >> R;
T = R;
while(T--){
    scanf("%d %d %d", &N, &M, &k);
    mn = 2e8;
    gen(0);
    printf("Case #%d: %d\n", R-T, mn);
}

return 0;
}
