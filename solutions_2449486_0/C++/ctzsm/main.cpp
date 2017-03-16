#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

int T, nCase = 1;
int N, M;
int a[105][105];
int d[105][105];
bool solve(){
    scanf("%d%d", &N, &M);
    int MAX = 0;
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            scanf("%d", &a[i][j]);
            d[i][j] = 3;
            MAX = max(a[i][j], MAX);
        }
    }
    for(int i = 0; i < N; ++i){
        int h = a[i][0];
        bool flag = false;
        for(int j = 1; j < M; ++j){
            if(h != a[i][j]){
                flag = true; break;
            }
        }
        if(flag){
            for(int j = 0; j < M; ++j){
                d[i][j] &= 2;
            }
        }
    }
    
    for(int j = 0; j < M; ++j){
        int h = a[0][j];
        bool flag = false;
        for(int i = 1; i < N; ++i){
            if(h != a[i][j]){
                flag = true; break;
            }
        }
        if(flag){
            for(int i = 0; i < N; ++i){
                d[i][j] &= 1;
            }
        }
    }
    
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            if(d[i][j] == 0 && a[i][j] != MAX) return false;
        }
    }
    return true;
}
int main(int argc, char** argv) {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    scanf("%d", &T);
    while(nCase <= T){
        printf("Case #%d: ", nCase++);
        printf(solve() ? "YES\n" : "NO\n");
    }
    return 0;
}

