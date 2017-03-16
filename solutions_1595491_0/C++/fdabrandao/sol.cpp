#include<cstdio>
#include<cassert>
#include<cstring>
#include<algorithm>
using namespace std;

#define EXT 10
#define MAX_N 100
#define MAX_SUM 30
#define MAX_SCORE 10

int N;
int S;
int RES_P;
int T[MAX_N+EXT];
int AUX[2][MAX_SUM+1+EXT][MAX_SCORE+1+EXT];
int DP[MAX_N+EXT][MAX_N+EXT];

void init(){
    for(int a = 0; a <= 10; a++){
        for(int b = a; b <= 10; b++){
            for(int c = b; c <= 10; c++){
                int sum = a+b+c;
                if(c-a < 2){
                    for(int m = c; m >= 0; m--){
                        AUX[0][sum][m] = 1;
                    }
                }else if(c-a == 2){
                    for(int m = c; m >= 0; m--){
                        AUX[1][sum][m] = 1;
                    }
                }
            }
        }
    }
}

void read(){
    assert(scanf("%d%d%d", &N, &S, &RES_P)==3);
    for(int i = 0; i < N; i++){
        assert(scanf("%d", &T[i])==1);
    }
}

int f(int n, int s){
    if(n < 0){
        if(s == 0) 
            return 0;
        else
            return -1;
    }
    int &res = DP[n][s];
    if(res) return res-2;
    res = -1;
    if(s > 0){
        int r = f(n-1, s-1); 
        if(r != -1) res = r+AUX[1][T[n]][RES_P];
    }
    int r = f(n-1, s);
    if(r != -1){
        res = max(res, r+AUX[0][T[n]][RES_P]);
    }
    res += 2;
    return res-2;
}

int solve(){
    memset(DP, 0, sizeof(DP));
    return f(N-1, S);
}

int main(){
    init();
    int t;
    assert(scanf("%d", &t)==1);    
    for(int i = 0; i < t; i++){
        read();
        int res = solve();
        printf("Case #%d: %d\n", i+1, res);
    }
    return 0;
}

