#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

const int N = 109;
int A[N][N]; bool vis[N][N];
int r, c, b;

#define REP(i, n) for (int i=0;i<n;++i)
#define REP_1(i, n) for (int i=1;i<=n;++i)

bool inGrid(int x, int y){
    return x >= 0 && y >= 0 && x < r && y < c;
}

int C(int x, int y){
    int z= 0;REP(i, 8){
        int xx = x +dx[i], yy = y +dy[i];
        if (inGrid(xx, yy) && !A[xx][yy]) ++z;
    }
    return z;
}

int cnt;
void dfs(int x = 0, int y = 0){
    vis[x][y] = 1; if (!A[x][y]) return;
    ++cnt; if (C(x, y)) return;
    REP(i, 8){
        int xx = x +dx[i], yy = y +dy[i];
        if (inGrid(xx, yy) && !vis[xx][yy]) dfs(xx, yy);
    }
}

bool ck(int cc){
    if (r*cc < b) return 0;

    int bb = 0;

    memset(A, 0, sizeof(A));
    int ii;
    REP(i, r){
        REP(j, cc) if (bb < b) A[i][j] = 1, ii = i, ++bb;
    }

    if (b%cc == 1){
        A[ii][1] = 1;
        A[ii-1][cc-1] = 0;
    }

    memset(vis, 0, sizeof(vis));
    cnt = 0; dfs(); return cnt == b;
}

bool ck(){
    REP_1(cc, c) if (ck(cc)) return 1;
    return 0;
}

int Case;

int main(){

#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    freopen("C-small-attempt0 (1).in", "r", stdin);
    //freopen("____________________________________________.txt", "w", stdout);
#endif

    int T; cin >> T; while (T--){

        printf("Case #%d:\n", ++Case);
        scanf("%d %d %d", &r, &c, &b); b = r*c - b;

        if (ck()){
            for (int i=0;i<r;++i){
                for (int j=0;j<c;++j){
                    if (!i && !j) putchar('c');
                    else putchar(A[i][j] ? '.' : '*');
                }
                puts("");
            }
        }
        else{
            puts("Impossible");
        }
    }
}
