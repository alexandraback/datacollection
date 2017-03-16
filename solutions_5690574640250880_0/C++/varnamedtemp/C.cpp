#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdlib>

using namespace std;

int R, C, M,  chk[55][55];
int dr[] = {-1, 1, 0, 0, 1, 1, -1, -1};
int dc[] = {0, 0, -1, 1, -1, 1, -1, 1};

bool ok(int r, int c) {
    return r >= 0 && r < R && c >= 0 && c < C && chk[r][c] == 0;
}

int main() {
    freopen("c-small-attempt0.in.txt", "r", stdin);
    freopen("C.out", "w", stdout);
    int T;
    scanf("%d",&T);
    for(int t = 1;t<=T;t++) {
        scanf("%d %d %d",&R, &C, &M);
        for(int i = 0;i<R;i++)
            for(int j = 0;j<C;j++)
                chk[i][j] = 0;
        
        M = R * C - M;

        queue<pair<int,int> > q;
        q.push(make_pair(0, 0));
        chk[0][0] = 1;
        int S = 1, maxR = 0, maxC = 0;
        while(!q.empty()) {
            pair<int,int> p = q.front(); q.pop();
            int r = p.first, c = p.second;
            maxR = max(maxR, r);
            maxC = max(maxC, c);
            int cnt = 0;
            for(int i = 0;i<8;i++) {
                int rr = r + dr[i];
                int cc = c + dc[i];
                if(ok(rr,cc))
                    cnt++;
            }
            if(S + cnt <= M) {
                for(int i = 0;i<8;i++) {
                    int rr = r + dr[i];
                    int cc = c + dc[i];
                    if(ok(rr, cc)) {
                        q.push(make_pair(rr, cc));
                        chk[rr][cc] = 1;
                    }
                }
                S += cnt;
            }
        }
        printf("Case #%d:\n", t); 
        if(M - S >= 2) {
            printf("Impossible\n");
            continue;
        }
        
        if(M - S == 1) {
            if(maxR < 2 || maxC < 2) {
                printf("Impossible\n");
                continue;
            }
            if(maxR < R - 1) {
                chk[maxR + 1][0] = chk[maxR + 1][1] = 1;
                chk[maxR][C - 1] = 0;
            }
            else {
                chk[0][maxC + 1] = chk[1][maxC + 1] = 1;
                chk[R - 1][maxC] = 0;
            }
        }

        for(int i = 0;i<R;i++) {
            for(int j = 0;j<C;j++) {
                if(i == 0 && j == 0)
                    printf("c");
                else {
                    if(chk[i][j] == 1) {
                        printf(".");
                    }
                    else {
                        printf("*");
                    }
                }
            }
            printf("\n");
        }

    }
    return 0;
}
