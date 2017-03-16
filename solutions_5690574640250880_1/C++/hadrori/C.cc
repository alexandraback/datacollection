#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <complex>

using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
const int inf = 1e9;
const double eps = 1e-8;
const double pi = acos(-1.0);

int R, C, M, N;
int table[64][64];

void init(){
    memset(table, 0, sizeof(table));
}

void input(){
    cin >> R >> C >> M;
}

void show(){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(table[i][j] == 2) printf("c");
            else if(table[i][j] == 1) printf(".");
            else printf("*");
            if(j==C-1) puts("");
        }
    }
}

void solve(){
    N = R*C-M;
    if(N==1 or R==1 or C==1){
        for(int i = 0; i < R and N > 0; i++)
            for(int j = 0; j < C and N > 0; j++)
                if(N--) table[i][j] = 1;
        table[0][0] = 2;
        show();
        return;
    }
    if(N < 4) {
        puts("Impossible");
        return;
    }
    if(N % 2 == 0){
        for(int j = 0; j < C and N > 0; j++){
            N -= 2;
            table[0][j] = table[1][j] = 1;
        }
        for(int i = 2; i < R and N > 0; i++){
            for(int j = 0; j + 1 < C and N > 0; j+=2){
                N -= 2;
                table[i][j] = table[i][j+1] = 1;
            }
            if(i%2 and C%2 and  N > 0){
                N -= 2;
                table[i-1][C-1] = table[i][C-1] = 1;
            }
        }
        table[0][0] = 2;
        show();
        return;
    }
    if(R == 2 or C == 2 or N < 8){
        puts("Impossible");
        return;
    }
    N -= 3;
    for(int j = 0; j < C and N > 0; j++){
        N -= 2;
        table[0][j] = table[1][j] = 1;
    }
    table[0][0] = 2;
    if(N == 0){
        table[2][0] = table[2][1] = table[2][2] = 1;
        show();
        return;
    }
    for(int i = 2; i < R and N > 0; i++){
        for(int j = 0; j < C and N > 0; j++){
            N--;
            table[i][j] = 1;
            if(N == 0){
                j++;
                if(j + 2 < C) table[i][j] = table[i][j+1] = table[i][j+2] = 1;
                else if(j < C) table[i][j] = table[i+1][0] = table[i+1][1] = 1;
                else table[i+1][0] = table[i+1][1] = table[i+1][2] = 1;
            }
        }
    }
    show();
    return;
}

int main(){
    int T; cin >> T;
    for(int t = 1; t <= T; t++){
        printf("Case #%d:\n", t);
        init(); input();
        solve();
    }
    return 0;
}
